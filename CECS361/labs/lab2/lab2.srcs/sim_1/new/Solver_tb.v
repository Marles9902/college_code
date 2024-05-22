`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 10/03/2022 03:38:38 PM
// Design Name: lab2
// Module Name: Solver_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////


module Solver_tb();

reg clk_tb, reset_tb, in_tb;
wire [2:0] RGB_tb, solution_tb, LED_tb;

Solver uut (.clk(clk_tb), .reset(reset_tb), .in(in_tb), .RGB(RGB_tb), .solution(solution_tb), .LED(LED_tb));

always #10 clk_tb = ~clk_tb;

initial begin
    clk_tb = 0; reset_tb = 1;
    #20;
    reset_tb = 0;
    
    in_tb = 0;
    #260;
    in_tb = 1;
    #40;
    in_tb = 0;
    #120;
    in_tb = 1;
    #40;
    in_tb = 0;
    
end

endmodule
