`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 03/03/2022 03:31:50 PM
// Design Name: 301_Lab2
// Module Name: top_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module top_tb();

    reg clk_tb;
    reg reset_tb;
    wire [7:0] cathode_tb;
    wire [7:0] anode_tb;
    
    top uut (.clk(clk_tb), .reset(reset_tb), .cathode(cathode_tb), .anode(anode_tb));
    
    initial begin
        clk_tb = 0;
        reset_tb = 1;
        #50;
        reset_tb = 0;
    end
    
    always
        #5 clk_tb = ~clk_tb;
        
endmodule
