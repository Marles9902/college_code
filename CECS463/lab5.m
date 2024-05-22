function lab5
load("bach_fugue.mat")  % load "theVoices" structure with bach fugue info.

melody = cell(1,length(theVoices)); % pre-fill melody cell-array

% Iterate through the three different bach fugue melodies in theVoices
for idx=1:length(theVoices)
    % Starting pulse of the note. Used for arranging placements of notes
    % relative to each other.
    startPulses = theVoices(idx).startPulses;
    % Duration of note in "pulses". Later converted to time duration
    durations   = theVoices(idx).durations;
    % Note Number later coverted to a frequency in sinusoidal eg(A4=440 Hz)
    noteNumbers = theVoices(idx).noteNumbers;
    % Store melody output in cell array
    melody{idx} = get_melody(startPulses, durations, noteNumbers);
end
bach = sum([melody{:}],1);  % Sum melody cell-arrays into one bach song

% Plot the spectrogram
figure;
spectrogram(bach, 1024, 512, 1024, 11025, 'yaxis');
title('Spectrogram of Bach Fugue');
xlabel('Time (s)');
ylabel('Frequency (Hz)');


filename = 'bach_fugue.wav';
audiowrite(filename,bach,11025);
end

%--------------------------------------------------------------------------

function xx = key2note(X, keynum, dur)
% KEY2NOTE Produce a sinusoidal waveform corresponding to a
% given piano key number
%
% usage: xx = key2note (X, keynum, dur)
%
% xx = the output sinusoidal waveform
% X = complex amplitude for the sinusoid, X = A*exp(j*phi).
% keynum = the piano keyboard number of the desired note
% dur = the duration (in seconds) of the output note
%

% extra variables
keyFreq = 440; % frequency for A4 --> 440 Hz
keyPos = keynum - 49;

fs = 11025; %-- or use 8000 Hz
tt = 0:(1/fs):dur;
freq = keyFreq*2^((keyPos)/12); %<=============== fill in this line
xx = real(X*exp(j*2*pi*freq*tt));

plot(tt,xx); % plot to check
end

function warmup
    % WARM-UP SECTION 3.2 Synthesize a Scale
    %--- NOTES:    C  D  E  F  G  A  B  C
    scale.keys = [ 40 42 44 45 47 49 51 52 ];   % key #40 is middle-C
    scale.durations = 0.25 * ones(1,length(scale.keys));
    fs = 11025;             %-- or 8000Hz
    xx = zeros(1,sum(scale.durations)*fs+length(scale.keys));
    n1 = 1;
    for kk = 1:length(scale.keys)
        keynum = scale.keys(kk);
        tone = key2note(xx,keynum,n1); %<- filled
        n2 = n1+length(tone)-1;
        xx(n1:n2) = xx(n1:n2)+tone;
        n1 = n2+1;
    end
    soundsc(xx,fs)
end
%--------------------------------------------------------------------------
%{
function prelab
    % % PRE-LAB SECTION 2.2 D-to-A Conversion (uncomment soundsc to listen)
    % % part a ---
    % [x1,x1_t] = syn_sin(800, 100*exp(j*(-pi/3)), 11025, 0.5, 0);
    % %soundsc(real(x1), 11025);
    % % part b ---
    % [x2,x2_t] = syn_sin(1200, 80*exp(j*(pi/4)), 11025, 0.8, 0);
    % %soundsc(real(x2), 11025);
    % % part c ---
    % N = 1000;
    % xx = [x1, zeros(1,N), x2];
    % %soundsc(real(xx), 11025);
    % % part d ---
    % tt = (1/11025)*(1:length(xx));
    % plot(tt,xx);
    % % part e ---
    % soundsc(real(xx), 22050);
    
    % % PRE-LAB SECTION 2.3 Structures in MATLAB
    % x.Amp = 7;
    % x.phase = -pi/2;
    % x.freq = 100;
    % x.fs = 11025;
    % x.timeInterval = 0:(1/x.fs):0.05;
    % x.values = x.Amp*cos(2*pi*(x.freq)*(x.timeInterval)+x.phase);
    % x.name = 'My Signal';
    % x               %---- echo the contents of the structure "x"
    % plot(x.timeInterval, x.values)
    % title(x.name)
end
%}
%--------------------------------------------------------------------------

% syn_sin function stolen from lab 2 
function [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)
    f = length(fk);
    X = length(Xk);
    if (X ~= f) 
        disp('error'); 
    end
    if (nargin < 5) 
        tstart = 0; 
    end 
    tt = tstart:1/fs:dur;
    xx = 0; 
    for k=1:X
        x = Xk(k).*exp(j*2*pi*fk(k)*tt);
        xx = xx+x;
    end
end

%--------------------------------------------------------------------------

function xx = get_melody(startPulses,durations,noteNumbers)
% GET_MELODY  Create a sequence of notes made up of pure sinusoidal
%              waveforms that vary in duration/frequency
%
%           xx = the output array of notes that make a musical melody
%  startPulses = Starting Pulse of a note
%    durations = the note's duration in pulses
%  noteNumbers = The note's Key number such as (C3,..A4,..G5,etc)
%

fs = 11025; % Sampling frequency, [samples/sec]

% Find seconds_per_pulse to convert "durations" input from pulses to time
bpm = 120; %  Beats Per Minute
beats_per_second = bpm/60;
seconds_per_beat = 1/beats_per_second;
seconds_per_pulse = seconds_per_beat / 4;
time_dur_per_note = durations * seconds_per_pulse;

length_xx = ceil(sum(time_dur_per_note)+1)*fs;
xx = zeros(1,length_xx);    % pre-fill max size of melody
x = 1; % Default value for complex amplitude input to key2note
n1=startPulses(1);  % Begin melody at starting place of 1st note
for kk = 1:length(noteNumbers)

    keynum = noteNumbers(kk);
    dur    = time_dur_per_note(kk);
    note   = key2note(x,keynum,dur);  % x=1 before for loop.
    
    E_length = length(note); % Envelope length must be same as note length
    
    upramp   = round( 0.1 * E_length ); % Percentage of note for ramp
    downramp = round( 0.2 * E_length ); % Percentage of note for downramp
    hold     = E_length-upramp-downramp; % Percentage of note to hold max
     
    E_upramp   = linspace(0,1,upramp);   % ramp up from 0 to 1
    E_hold     = ones(1,hold);           % hold note at max value
    E_downramp = linspace(1,0,downramp); % down ramp from 1 to 0
     
    % Create an envelope, E, that linearly 
    % ramps up from 0 to 1, holds, then ramps down to 0 at set intervals
    E = [ E_upramp E_hold E_downramp ];
    % E: truncate extraneous values due to rounding
    E = E(1:length(note));
    % Multiply note by E envelope
    note = E.*note;
    
    n2 = n1 + length(note) - 1;     % Find end of note's "sub-array"
    xx(n1:n2) = xx(n1:n2) + note;   % Insert note's "sub-array" into melody
    n1 = startPulses(kk)+n2;        % Find start of next note's "sub-array"
end
end
%--------------------------------------------------------------------------