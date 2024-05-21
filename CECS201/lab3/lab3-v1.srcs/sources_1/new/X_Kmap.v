`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS-201 Sec 01 
// Engineer: Marwin Gonzales 
//////////////////////////////////////////////////////////////////////////////////

module X_Kmap(
    input a,
    input b,
    input c,
    input d,
    output XK_out
    );
    
// X_Kmap = a'b + bc' + bd'
assign XK_out = (~a & b) | (b & ~c) | (b & ~d);

endmodule
