`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 03/03/2022 03:28:15 PM
// Design Name: 301_Lab2
// Module Name: top
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module top(
    input clk,
    input reset, 
    output [7:0] cathode,
    output [7:0] anode
    );
    
    assign anode = 8'b11111110; 
    wire [3:0] Q;
    
    BCD_To_7seg BCD(.Q(Q), .cathode(cathode));
    
    Sync_BCD_Counter counter(.clk(clk), .reset(reset), .Q(Q));
    
endmodule
