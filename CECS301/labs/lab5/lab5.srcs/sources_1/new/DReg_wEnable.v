`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 4/26/2022 3:014:14 AM
// Design Name: 301_Lab5
// Module Name: DReg_wEnable
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module DReg_wEnable(
    input clk,
    input reset,
    input e,
    input [7:0] D,
    output reg [7:0] Q
    );
    
    always@(posedge clk, posedge reset) begin 
        if(reset)
            Q <= 8'b0;
        else if(e)
            Q <= D;
    end
endmodule