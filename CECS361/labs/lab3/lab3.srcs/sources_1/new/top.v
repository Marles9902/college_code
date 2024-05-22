`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 10/11/2022
// Design Name: 361_Lab3
// Module Name: top
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module top(
    input a, b, c, d, e,

    output out1, out2, eq
    );
    
    Lab3 original(a, b, c, d, e, out1);
    Lab3_eq equivalent(a, b, c, d, e, out2);
    assign eq = out1 ^ out2;
endmodule