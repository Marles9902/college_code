%{
SECTION 5 -- Lab Exercise: Representation of Sinusoids with Complex Exponentials
%}

function lab2
    % [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)
    [xx,tt] = syn_sin([0.5, 0.5, 0.5], [2, 2*exp(-j*pi*1.25), (1-j)], 10, 3*1/0.5, -0.5);
    plot(tt, real(xx)); % plot x against t
    xlabel t; % labels
    ylabel x; % labels

    % PART C
    z1 = 2;
    z2 = 2*exp(-j*pi*1.25);
    z3 = (1-j);
    zSum = z1 + z2 + z3;
    zprint(zSum);
end 

%{
Multipath Lab -- syn_sin() function from 4.2.1
%}

function [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)

    % SYN_SIN Function to synthesize a sum of cosine waves
    % usage:
    % [xx,tt] = syn_sin(fk, Xk, fs, dur, tstart)
    % fk = vector of frequencies
    % (these could be negative or positive)
    % Xk = vector of complex amplitudes: Amp*eˆ(j*phase)
    % fs = the number of samples per second for the time axis
    % dur = total time duration of the signal
    % tstart = starting time (default is zero, if you make this input optional)
    % xx = vector of sinusoidal values
    % tt = vector of times, for the time axis
    %
    % Note: fk and Xk must be the same length.
    % Xk(1) corresponds to frequency fk(1),
    % Xk(2) corresponds to frequency fk(2), etc.


    f = length(fk); % vector of frequencies
    X = length(Xk); % vector of complex amplitudes: Amp*eˆ(j*phase)
    
    % make sure X and f are same length
    if (X ~= f) 
        disp('error'); 
    end
    
    % from 4.2.2 -- Default Inputs 
    if (nargin < 5) 
        tstart = 0; 
    end             %--default value is zero
    
    tt = tstart:1/fs:dur;   % generate time vector 
    xx = 0; % begin synthesized signal at 0 first

    % add sinusoid components to synthesize signal
    for k=1:X
        x = Xk(k).*exp(j*2*pi*fk(k)*tt);    % calculate complex exponential signal
        xx = xx+x;  % add up the sinusoid parts
    end
end