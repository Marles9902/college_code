`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS-201 Sec 01 
// Engineer: Marwin Gonzales a_tb = 0;
//////////////////////////////////////////////////////////////////////////////////


module Boolean_function(
    input a,
    input b,
    input c,
    output z
    );
    
// implement z = ab' + a'c
wire p;
wire q;

assign p = a & ~b;
assign q = ~a & c;
assign z = p | q;

endmodule
