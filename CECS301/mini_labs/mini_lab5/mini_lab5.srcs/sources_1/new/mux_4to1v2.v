`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/03/2022 03:22:22 PM
// Design Name: 
// Module Name: mux_4to1v2
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module mux_4to1v2(
    input a,
    input b, 
    input c, 
    input d, 
    input [1:0] sel, 
    output out
    );
    wire out1, out2;
    
    mux_2to1 uut1(.a(a), .b(b), .c(sel[0]), .out(out1));
    mux_2to1 uut2(.a(c), .b(d), .c(sel[0]), .out(out2));
    mux_2to1 uut3(.a(out1), .b(out2), .c(sel[1]), .out(out));
    
endmodule
