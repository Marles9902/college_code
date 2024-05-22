`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/25/2022 12:38:11 PM
// Design Name: 
// Module Name: mux_2to1_tb
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


module mux_2to1_tb(
    );
    
    reg a_tb, b_tb, c_tb;
    wire out_tb;
    
    mux_2to1 uut (.a(a_tb), .b(b_tb), .c(c_tb), .out(out_tb));
    
    localparam period = 100;    
    
    initial begin
    a_tb = 0;
    b_tb = 0;
    c_tb = 0;
    #period;
    
    a_tb = 1;
    b_tb = 0;
    c_tb = 0;
    #period;
    
    a_tb = 0;
    b_tb = 1;
    c_tb = 0;
    #period;
    
    a_tb = 1;
    b_tb = 1;
    c_tb = 0;
    #period;
    
    a_tb = 0;
    b_tb = 0;
    c_tb = 1;
    #period;
    
    a_tb = 1;
    b_tb = 0;
    c_tb = 1;
    #period;
    
    a_tb = 0;
    b_tb = 1;
    c_tb = 1;
    #period;
    
    a_tb = 1;
    b_tb = 1;
    c_tb = 1;
    #period;
    
    $finish;
    end
    
endmodule
