`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 10/11/2022
// Design Name: 361_Lab3
// Module Name: Lab3_eq
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module Lab3_eq(
    input A, B, C, D, E,
    output out
    );

    // old equation
//    assign out = (~B & ~C & ~D & ~E) | (~B & ~C & D & ~E) | (A & B & C & D & ~E) | (~A & B & C & ~D) | (B & C & ~D & ~E);
    assign out = (~B & ~C & ~E) | (A & B & C & ~E) | (~A & B & C & ~D);

//    assign out = A;

endmodule
