`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/25/2022 01:00:47 PM
// Design Name: 
// Module Name: mux_4to1
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

module mux_4to1(
    input a,
    input b,
    input c,
    input d,
    input [1:0] sel,
    output out
    );
    
    assign out = sel[1] ? (sel[0] ? a : b) : (sel[0] ? c : d);
    
endmodule
