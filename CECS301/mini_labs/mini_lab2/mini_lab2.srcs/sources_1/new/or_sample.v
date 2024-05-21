`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 301- Spring 2022
// Engineer: Marwin Gonzales
// 
// Create Date: 01/27/2022 04:01:10 PM
// Design Name: 
// Module Name: or_sample
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


module or_sample(
    input a,
    input b,
    output out
    );
    
    assign out = a | (~a & b);
    
endmodule
