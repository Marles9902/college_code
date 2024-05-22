`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales, Joshua Siajuat
// Create Date: 10/18/2022 03:53:09 PM
// Design Name: configurable_digital_clock
// Module Name: Sync_BCD_Counter
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module Sync_BCD_Counter(
    input clk,
    input reset,
    output reg [3:0] Q
    );
    
    reg [32:0] tick;        

        always@(posedge clk, posedge reset) begin
        if(reset) begin 
            tick <= 33'b0;
            Q <= 4'b0;
        end
        else if (tick == 100000000 * 60) begin   // tick == 10 for sim, tick == 100000000 for 1 sec on board
            tick <= 33'b0;
            if(Q < 9)
                Q <= Q + 1'b1;
            else
            Q <= 4'b0;
        end
        else
            tick <= tick + 1'b1;
        end
endmodule