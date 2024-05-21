`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 301 - Spring 2022
// Engineer: Marwin Gonzales 
// 
// Create Date: 01/25/2022 03:28:28 PM
// Design Name: 
// Module Name: and_sample
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


module and_sample(
    input a,
    input b,
    output out
    );
    
    // Declare internal signals
    wire w1, w2;
    
    // Declare gate
    /*
    or u1 (w1, a, b);
    xor u2 (w2, a, b);
    xor u3 (out, w1, w2);
    // another way to declare gates 
    assign w1 = a|b;
    assign w2 = a^b;
    */
    // shortest way to represent 
    assign out = (a|b)^(a^b);
endmodule
