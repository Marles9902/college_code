`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 03/01/2022 03:43:05 PM
// Design Name: 301_Lab2
// Module Name: Sync_BCD_Counter
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module Sync_BCD_Counter(
    input clk,
    input reset,
    output reg [3:0] Q
    );
    
    reg [26:0] tick;        

        always@(posedge clk, posedge reset) begin
        if(reset) begin 
            tick <= 27'b0;
            Q <= 4'b0;
        end
        else if (tick == 10) begin   // tick == 100000000 for board, tick == 10 for sim
            tick <= 27'b0;
            if(Q < 9)
                Q <= Q + 1'b1;
            else
            Q <= 4'b0;
        end
        else
            tick <= tick + 1'b1;
        end
endmodule
