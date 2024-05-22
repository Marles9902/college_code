`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales, Joshua Siajuat
// Create Date: 10/18/2022 03:53:09 PM
// Design Name: configurable_digital_clock
// Module Name: Top
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module Top(
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
