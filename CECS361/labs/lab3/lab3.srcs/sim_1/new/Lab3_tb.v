`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 10/11/2022
// Design Name: 361_Lab3
// Module Name: lab3_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module Lab3_tb();
reg a,b,c,d,e;
wire out;

Lab3 uut (.A(a), .B(b), .C(c), .D(d), .E(e), .Out(out));

integer i;

initial begin
    for(i = 5'b0; i < 32; i = i + 1'b1) begin
        {a, b, c, d, e} = i;
        #20;
    end
    $finish;
end

endmodule