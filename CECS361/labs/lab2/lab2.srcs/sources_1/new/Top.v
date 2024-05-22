`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 09/27/2022 12:23:22 PM
// Design Name: lab2
// Module Name: Top
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////


module Top(
    input clk,
    input reset,
    input [1:0] sel,
    output [2:0] RGB,
    output [2:0] LED
    );
    
    wire out;
    wire [2:0] solution;
    
    Solver S0(.clk(clk), .reset(reset), .in(out), .RGB(RGB), .solution(solution), .LED(LED));      
    
    CNF cnf0(.A(solution[2]), .B(solution[1]), .C(solution[0]), .sel(sel), .out(out));
endmodule
