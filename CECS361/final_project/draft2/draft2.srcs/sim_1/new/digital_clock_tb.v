`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/13/2022 02:53:05 PM
// Design Name: 
// Module Name: digital_clock_tb
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
module digital_clock_tb();
    reg clk_tb;
    reg reset_tb;
    reg [19:0] time_in_tb;
    
    wire [19:0] time_out_tb;
    wire [6:0] sec_tb;
    wire [6:0] min_tb;
    wire [5:0] hrs_tb;
    
    // assume 10ns = 1s
    always #5  clk_tb = ~clk_tb;
    
    assign {hrs_tb, min_tb, sec_tb} = time_out_tb;
    
    digital_clock uut(.clk(clk_tb), .reset(reset_tb), .time_in(time_in_tb), .time_out(time_out_tb), .sec_out(sec_tb), .min_out(min_tb), .hrs_out(hrs_tb));
    
    initial begin
        clk_tb = 0;
        reset_tb = 0;
        time_in_tb = {6'h23, 7'h48, 7'h0}; // 23:48:00
        #10
        reset_tb = 1;
        #10
        reset_tb = 0;
        #1000000;
    end
endmodule