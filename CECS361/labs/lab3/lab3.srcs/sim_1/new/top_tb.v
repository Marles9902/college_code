`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 10/11/2022
// Design Name: 361_Lab3
// Module Name: top_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////


module top_tb();
reg a,b,c,d,e;
wire out1, out2, eq;

top uut (.a(a), .b(b), .c(c), .d(d), .e(e), .out1(out1), .out2(out2), .eq(eq));

integer i;

initial begin
    for(i = 5'b0; i < 32; i = i + 1'b1) begin
        {a, b, c, d, e} = i;
        #20;
    end
    $finish;
end

endmodule