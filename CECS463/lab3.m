function lab3
    % Define source and sensor positions
    xT = -10;     % Source x position in meters
    yT = 17.32;   % Source y position in meters
    xySensors = [-0.4, 0; 0.4, 0]';  % Sensor positions in meters
    
    % Call the rcvpairsigs function to get complex amplitudes
    Camps = rcvpairsigs(xT, yT, xySensors);
    
    % Calculate the phases of the received signals
    phases = angle(Camps);
    
    % Display the complex amplitudes and phases at each sensor
    disp('Complex Amplitudes at Sensors:');
    disp(Camps);
    disp('Phases (in radians) at Sensors:');
    disp(phases);
end

function Camps = rcvpairsigs( xT, yT, xySensors )
    % RCVPAIRSIGS - generate data for a sinusoid emitted from a single
    %               source location and received at multiple sensors (microphones)
    %
    % xT = x position of the source
    % yT = y position of the source
    % xySensors = 2 by Ns matrix of (x,y) positions of the receivers
    %             where Ns = number of sensors (receivers)
    % Camps = matrix of COMPLEX amplitudes, one for each sensor
    %         size(Camps) is 1 by Ns
    
    % Constants
    c = 333;  % Sound velocity in meters/sec
    freq = 222;  % Frequency in Hz
    
    % Calculate number of sensors
    Ns = size(xySensors, 2);
    
    % Initialize output matrix Camps
    Camps = zeros(1, Ns);
    
    % Calculate wave number
    k = 2 * pi * freq / c;
    
    % Calculate source position vector
    rT = [xT; yT];
    
    % Loop through each sensor and calculate received signal
    for i = 1:Ns
        % Calculate sensor position vector
        rS = xySensors(:, i);
    
        % Calculate distance between source and sensor
        r = norm(rS - rT);
    
        % Calculate received signal amplitude
        Camps(i) = exp(1i * k * r);
    end
end