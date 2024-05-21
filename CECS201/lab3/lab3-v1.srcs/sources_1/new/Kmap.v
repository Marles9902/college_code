`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS-201 Sec 01 
// Engineer: Marwin Gonzales 
//////////////////////////////////////////////////////////////////////////////////

module Kmap(
    input a,
    input b,
    input c,
    input d,
    output K_out
    );

// Kmap(1) = a'bc + a'bd' + bcd' + abc'd
assign K_out = (~a & b & c) | (~a & b & ~d) | (b & c & ~d) | (a & b & ~c & d);

endmodule
