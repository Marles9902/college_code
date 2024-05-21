`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 03/08/2022 03:42:56 PM
// Design Name: 
// Module Name: SD_tb
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module SD_tb();

    reg i_tb, clk_tb;
    wire o_tb;
    integer index;
    reg [9:0] data;
    
    SD uut (.i(i_tb), .clk(clk_tb), .o(o_tb));
    
    initial begin 
        i_tb = 0;
        data = 10'b0001101011; // b1010000101 for HW2-Q4, b0001101011 for mini lab
        index = 0;
    end
    
    initial begin
        clk_tb = 0;
        forever begin
            #20;
            clk_tb =~clk_tb;
        end
    end
    
    always @ (posedge clk_tb) begin
        i_tb = data >> index;
        index = index + 1;
    end
    
endmodule
