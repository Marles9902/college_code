`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 10/19/2022 03:16:25 PM
// Design Name: circuit_from_waveform
// Module Name: circuit_from_waveform_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module circuit_from_waveform_tb();
reg a_tb, clk_tb;
wire [2:0] out_tb;

circuit_from_waveform uut(.a(a_tb),.clk(clk_tb),.out(out_tb));

always #10 clk_tb = ~clk_tb;

initial begin
    clk_tb = 0;
    a_tb = 1'b1;
    #60;
    a_tb = 1'b0;
    #220;
    a_tb = 1'b1;
    #60;
    a_tb = 1'b0;
    #80 $finish;
end
    

endmodule
