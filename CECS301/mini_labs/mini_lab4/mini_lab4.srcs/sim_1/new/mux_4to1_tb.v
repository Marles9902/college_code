`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/01/2022 03:44:18 PM
// Design Name: 
// Module Name: mux_4to1_tb
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


module mux_4to1_tb(
    );
    
    reg a_tb, b_tb, c_tb, d_tb;
    reg [1:0] sel_tb;
    wire out_tb;
    
    localparam period = 100;
    
    mux_4to1 uut(.a(a_tb), .b(b_tb), .c(c_tb), .d(d_tb), .sel(sel_tb), .out(out_tb));
    
    initial begin
    
    a_tb = 1;
    b_tb = 1;
    c_tb = 1;
    d_tb = 0;
    sel_tb = 2'b00;
    #period;
    
    a_tb = 0;
    b_tb = 0;
    c_tb = 0;
    d_tb = 1;
    sel_tb = 2'b00;
    #period;
    
    a_tb = 1;
    b_tb = 1;
    c_tb = 0;
    d_tb = 1;
    sel_tb = 2'b01;
    #period;
    
    a_tb = 0;
    b_tb = 0;
    c_tb = 1;
    d_tb = 0;
    sel_tb = 2'b01;
    #period;
    
    a_tb = 1;
    b_tb = 0;
    c_tb = 1;
    d_tb = 1;
    sel_tb = 2'b10;
    #period;
    
    a_tb = 0;
    b_tb = 1;
    c_tb = 0;
    d_tb = 0;
    sel_tb = 2'b10;
    #period;
    
    a_tb = 0;
    b_tb = 1;
    c_tb = 1;
    d_tb = 1;
    sel_tb = 2'b11;
    #period;
    
    a_tb = 1;
    b_tb = 0;
    c_tb = 0;
    d_tb = 0;
    sel_tb = 2'b11;
    #period;
    
    $finish;
    
    end
endmodule
