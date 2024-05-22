`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 09/27/2022 12:22:46 PM
// Design Name: lab2
// Module Name: Solver
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////


module Solver(
    input clk, 
    input reset,
    input in,
    output reg [2:0] RGB,
    output reg [2:0] solution,
    output reg [2:0] LED
    );
    
    
    always@(posedge clk, posedge reset) begin
        if(reset) begin
            solution <= 3'b0;
            LED <= 3'b000;
            RGB <= 3'b001; //RGB Code for Red.
        end
        else if(in) begin
            LED <= solution;
            RGB <= 3'b010; //RGB Code for Green. 
        end
        else begin 
            solution <= solution + 1;
            LED <= 3'b0;
            RGB <= 3'b001;
            // Insert logic here to iterate to the next test expression
            // when a solution has not yet been found. 
            // Hint: update LEDs and RGB here as well.
            
        end      
    end
endmodule
