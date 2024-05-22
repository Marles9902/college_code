`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 361 - Fall 2022
// Engineer: Joshua Siajuat, Marwin Gonzales
// Create Date: 12/02/2022 02:48:49 PM
// Module Name: digitalClock
//////////////////////////////////////////////////////////////////////////////////
module digitalClock(
    input clk,                          // internal clock
    input bC,                           // time set mode -- when on, allowed to change/set the time
    input bR,                           // swap between changing the minutes
    input bL,                           // swap between changing the hours
    input bU,                           // increment based on if the minutes or hours are being changed
    input bD,                           // decrement based on if the minutes or hours are being changed
    input switch,                       // switch between standard and military
    output switchLED,                   // indicator if in military or standard time
    output [5:0] seconds,               // seconds LED
    output [7:0] sevenSeg,              // 7-segment display
    output [7:0] boardDisplay,          // 8 displays on the board
    output [2:0] AM_PM_RGB,             // RGB to indicate AM (OFF) or PM (ON)
    output [2:0] modeRGB                // RGB to indicate if clock is in set time mode
    );
    
    // create a 1 second generator to drive the clock
    reg [26:0] counter = 0;         // counter
    parameter max = 100_000_000;    // 100MHz / 1Hz = 1 second
    
    // set up connections to hours, minutes, seconds, and display
    reg [5:0] hrs, min, sec = 0;                                                // hours go from 1-12, minutes go from 0-59, seconds go from 0-59 -- 60 max --> 6-bits max
    reg [3:0] secOnes, secTens, minOnes, minTens, hrsOnes, hrsTens = 0;         // initialize the clock to all 0's
    reg timeToggle = 0;                                                         // toggle betweeen changing hours or minutes -- 0 = minutes, 1 = hours
    assign seconds = sec;                                                       // seconds display will come directly from the counter
    assign switchLED = switch;                                                  // assign LED to switch input -- 0 = OFF (standard), 1 = ON (military)
    
    // initialize values of RGBs
    reg [2:0] PM = 0;                                       // PM set to 0 -- starting clock at midnight (12:00 AM)
    assign AM_PM_RGB = (PM) ? 3'b010 : 3'b000;              // RGB off until clock time enters PM, then PM causes a green RGB
    reg [2:0] mode = 0;                                     // mode set to 0 -- clock paused
    assign modeRGB = (mode) ? 3'b000 : 3'b100;              // when mode = 0 -- blue RGB to indicate clock paused and can be changed -- mode = 1, clock starts back at 0 seconds and resumes
    
    // instantiate sevenSegment module to connect it to clock
    sevenSegment clockDisplay(clk, secOnes, secTens, minOnes, minTens, hrsOnes, hrsTens, sevenSeg, boardDisplay);
    
    // set up the actual time on the clock
    // clock defaulted to setTime mode, allowing for changing time
    // when center button pressed -- enter setTime mode to change time with up and down buttons
    parameter displayTime = 1'b0;
    parameter setTime = 1'b1;
    reg currentMode = setTime;
    
    // set up logic for the clock and changing the time
    always@ (posedge clk) begin
        case(currentMode) 
            displayTime: begin              // clock displays 12:00AM - 11:59PM (standard) or 00:00 - 24:00 (military
                if (bC) begin               // center button pushed -- allow for time to be changed and reset all counters
                    mode <= 0;
                    currentMode <= setTime;
                    counter <= 0;
                    timeToggle <= 0;
                    sec <= 0;
                    secOnes <= 0;           // seconds display also set back to 0
                    secTens <= 0;
                end
                
                // seconds incrementer
                if (counter < max) begin 
                    counter <= counter + 1;
                end
                else begin
                    counter <= 0;
                    sec <= sec + 1;
                    secOnes <= (sec + 1) % 10;      // n + 1 to cancel out the n - 1 rule of binary operations
                    secTens <= (sec + 1) / 10;
                end
            end // end displayTime block
        
            // set up hours and minutes and changing/setting the time
            setTime: begin
                if (bC) begin                       // center button pushed again -- resume clock
                    mode <= 1;
                    currentMode <= displayTime;
                end 
                
                if (counter < (25_000_000)) begin     // clock speed for buttons (4Hz)
                    counter <= counter + 1;
                end 
                else begin
                    counter <= 0;
                    case(timeToggle)
                        1'b0: begin         // changing minutes
                            if (bU) begin   // up button -- increment minutes
                                min <= min + 1;
                            end
                            if (bD) begin   // down button -- decrement minutes
                                if (min > 0) begin
                                    min <= min - 1;
                                end
                                else if (hrs > 0) begin     // ex: 12:00 --> 11:59
                                    hrs <= hrs - 1;
                                    min <= 59;
                                end 
                                else if (hrs == 0) begin    // ex: 1:00 --> 12:59
                                    hrs <= 23;   
                                    min <= 59;
                                 end
                             end
                             
                             // toggle between minutes and hours 
                             if (bL) begin      // left button -- change hours
                                timeToggle <= 1;
                            end
                        end
                        
                        1'b1: begin // change hours
                            if (bU) begin   // up button -- increment hours
                                hrs <= hrs + 1;
                            end
                            if (bD) begin   // down button -- decrement hours
                                if (hrs > 0) begin
                                    hrs <= hrs - 1;
                                end
                                else if (hrs == 0) begin
                                    hrs <= 23;
                                end
                            end
                            if (bR) begin   // right button -- change minutes
                                timeToggle <= 0;
                            end
                        end
                    endcase // end timeToggle case block
                end
            end
        endcase // end currentMode case block
        
            // clock format -- standard time -- HH:MM:SS
            if (sec >= 60) begin    // after 60 seconds, increment minutes and go back to 0 to start again
                sec <= 0;
                secOnes <= 0;
                secTens <= 0;
                min <= min + 1;
            end
            if (min >= 60) begin    // after 60 minutes, increment hours, go back to 0
                min <= 0;
                hrs <= hrs + 1;
            end
            if (hrs >= 24) begin    // after 12 hours, swap between AM and PM
                hrs <= 0;
            end
            
            // standard time setup  -- 0 = AM, 1 = PM
            else if (~switch) begin     // switch -- down = AM, up = PM
                minOnes <= min % 10;
                minTens <= min / 10;
                if (hrs < 12) begin
                    if (hrs == 0) begin // midnight
                        hrsOnes <= 2;
                        hrsTens <= 1;
                    end 
                    else begin
                        hrsOnes <= hrs % 10;
                        hrsTens <= hrs / 10;
                    end
                    PM <= 0;
                end
                else begin
                    if (hrs == 12) begin
                        hrsOnes <= 2;
                        hrsTens <= 1;
                    end 
                    else begin
                        // ex: (18:00 - 12:00) = 6:00PM
                        hrsOnes <= (hrs - 12) % 10;     
                        hrsTens <= (hrs - 12) / 10;
                    end
                    PM <= 1;
                end 
            end // end standard time block
            
            // military time setup
            else begin
                minOnes <= min % 10;
                minTens <= min / 10;
                if (hrs < 12) begin
                    if (hrs == 0) begin
                        hrsOnes <= 0;
                        hrsTens <= 0;
                    end
                    else begin
                        hrsOnes <= hrs % 10;
                        hrsTens <= hrs / 10;
                    end
                    PM <= 0;
                end
                else begin
                    if (hrs == 24) begin
                        hrsOnes <= 0;
                        hrsTens <= 0;
                    end
                    else begin
                        hrsOnes <= hrs % 10;
                        hrsTens <= hrs / 10;
                    end
                    PM <= 0;
                end
            end
        end  
endmodule       