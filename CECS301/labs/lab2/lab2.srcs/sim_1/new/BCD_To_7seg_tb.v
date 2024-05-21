`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 03/01/2022 04:15:26 PM
// Design Name: 301_Lab2
// Module Name: BCD_To_7seg_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module BCD_To_7seg_tb();

reg [3:0] Q_tb;
wire [7:0] cathode_tb;

BCD_To_7seg uut (.Q(Q_tb),.cathode(cathode_tb));
integer i;

initial begin
    for(i=0;i<11;i=i+1)begin
        Q_tb=i;
        #50;
    end
    $finish;
end
endmodule
