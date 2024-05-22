`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 361 - Fall 2022
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 11/28/2022 01:27:18 PM
// Module Name: top
//////////////////////////////////////////////////////////////////////////////////
module top(
    input A, B, C, 
    output [2:0] RGB
);

wire F0_expected, F0_given, F1_expected, F1_given, Final;

// Innstatiane the given circuit and the expected circuit Here.

Circuit_SA1 Given (.A(A), .B(B), .C(C), .F1(F1_given), .F0(F0_given));
Circuit_Expected Expected (.A(A), .B(B), .C(C), .F1(F1_expected), .F0(F0_expected));

assign Final = (F0_given ^ F0_expected) | (F1_given ^ F1_expected);

assign RGB = (Final) ? 3'b001 : 3'b000; // Represent color of your choice when Final=1;

endmodule