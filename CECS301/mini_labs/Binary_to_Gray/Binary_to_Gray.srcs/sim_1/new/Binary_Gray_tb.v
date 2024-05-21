`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Amin Rezaei
// Create Date: 4/14/2021 11:11:14 AM
// Design Name: Dual Binary to Gray Convertor
// Module Name: Binary_Gray_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////
module Binary_Gray_tb (
    );
    
    reg [3:0] num_tb; 
    reg sel_tb;
    wire [3:0] out_tb;
    
    Binary_Gray uut(.num(num_tb), .sel(sel_tb), .out(out_tb));
    
    initial begin
        // Binary to Gray
        sel_tb = 0;
        num_tb = 4'b0110;
        #20;

	num_tb = 4'b1101;
        #20;
        
        // Gray to Binary
        sel_tb = 1;
        num_tb = 4'b0101;
        #20;
	
	num_tb = 4'b1011;
        #20;

	$finish;
    end
endmodule