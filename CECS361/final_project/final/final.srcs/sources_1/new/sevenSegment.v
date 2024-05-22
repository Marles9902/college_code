`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 361 - Fall 2022
// Engineer: Joshua Siajuat, Marwin Gonzales
// Create Date: 12/02/2022 02:48:37 PM
// Module Name: sevenSegment
//////////////////////////////////////////////////////////////////////////////////
module sevenSegment(
    input clk,                          // internal clock -- 100MHz
    input [3:0] secOnes,                // separate seconds number into ones and tens place -- 59 -- 5 is 'tens', 9 is 'ones'
    input [3:0] secTens,
    input [3:0] minOnes,                // similarly separate minutees
    input [3:0] minTens,       
    input [3:0] hrsOnes,                // similarly separate hours
    input [3:0] hrsTens,       
    output reg [7:0] sevenSeg,          // seven segments on a display -- technically 8 with decimal point
    output reg [7:0] boardDisplay       // 8 displays on board
    );
    
    reg [2:0] numDisplay = 0;   // six displays will be used -- HH:MM:SS format -- 3-bits max 
    reg [7:0] display [7:0];    // seven segments for each display (8 displays)    
    
    reg [17:0] counter = 0;     // generate a clock to toggle the segment displays
    parameter max = 250_000;    // 100MHz (frequency of board) / 100Hz (10ms for each display) = 1 million clock cycles / 4 = 250,000 cycles
    wire [5:0] placement [5:0]; // carry signals for seconds', minutes', and hours' ones and tens digits 
    
    // ---FORMAT---
    // HH:MM:SS
    // assign values to show on the segment display
    assign placement[0] = secOnes;  
    assign placement[1] = secTens;
    assign placement[2] = minOnes;
    assign placement[3] = minTens;
    assign placement[4] = hrsOnes;
    assign placement[5] = hrsTens;
    
    // generate clock to enable each segment 
    always@ (posedge clk) begin
        if (counter < max) begin
            counter <= counter + 1;
        end
        
        // move onto next display after counter reaches max, and repeat again
        else begin
            numDisplay <= numDisplay + 1;
            counter <= 0; 
        end
    
        // active low -- 0 = ON, 1 = OFF
        // BCD to 7-segment display decoder
        case(placement[numDisplay])          //abcd_efgh     PATTERNS
            4'b0000 : display[numDisplay] = 8'b0000_0011; // 0
            4'b0001 : display[numDisplay] = 8'b1001_1111; // 1
            4'b0010 : display[numDisplay] = 8'b0010_0101; // 2
            4'b0011 : display[numDisplay] = 8'b0000_1101; // 3
            4'b0100 : display[numDisplay] = 8'b1001_1001; // 4
            4'b0101 : display[numDisplay] = 8'b0100_1001; // 5
            4'b0110 : display[numDisplay] = 8'b0100_0001; // 6
            4'b0111 : display[numDisplay] = 8'b0001_1111; // 7
            4'b1000 : display[numDisplay] = 8'b0000_0001; // 8
            4'b1001 : display[numDisplay] = 8'b0000_1001; // 9
            default : display[numDisplay] = 8'b1111_1111; // OFF
        endcase   
        
        // enable each segment and display a number
        case(numDisplay)  // look through each of the displays
            3'b000: begin
                boardDisplay <= 8'b1111_1110;       // select this 7-segment display
                sevenSeg <= display[0];             // display a number on the display
            end                                     // similar logic for the other cases
            
            3'b001: begin
                boardDisplay <= 8'b1111_1101;
                sevenSeg <= display[1];
            end
            
            3'b010: begin
                boardDisplay <= 8'b1111_0111;
                sevenSeg <= display[2];
            end
            
            3'b011: begin
                boardDisplay <= 8'b1110_1111;
                sevenSeg <= display[3];
            end
            
            3'b100: begin
                boardDisplay <= 8'b1011_1111;
                sevenSeg <= display[4];
            end
            
            3'b101: begin
                boardDisplay <= 8'b0111_1111;
                sevenSeg <= display[5];
            end
        endcase
    end
endmodule