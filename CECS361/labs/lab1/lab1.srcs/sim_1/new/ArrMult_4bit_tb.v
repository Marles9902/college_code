`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/06/2022 12:36:18 PM
// Design Name: 
// Module Name: ArrMult_4bit_tb
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


module ArrMult_4bit_tb();
reg [3:0] a_tb, b_tb;
wire [7:0] prod_tb;

ArrMult_4bit uut(.a(a_tb), .b(b_tb), .prod(prod_tb));

initial begin
    // Test Case 1
    a_tb = 4'b1101;
    b_tb = 4'b1001;
    #10
    
    // Test Case 2
    a_tb = 4'b1111;
    b_tb = 4'b1111;
    #10
    
    // Test Case 3 
    a_tb = 4'b0101;
    b_tb = 4'b1010;
    #10
    
    // Test Case 4
    a_tb = 4'b0110;
    b_tb = 4'b0000;
    #10
    
    // Test Case 5
    a_tb = 4'b0011;
    b_tb = 4'b1100;
    #10
    
    // Test Case 6
    a_tb = 4'b1110;
    b_tb = 4'b0001;
    #10

    $finish;
end
endmodule