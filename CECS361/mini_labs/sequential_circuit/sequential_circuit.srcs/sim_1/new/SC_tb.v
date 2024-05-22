`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/01/2022 12:11:12 PM
// Design Name: 
// Module Name: SC_tb
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


module SC_tb(
    );
    
    reg i_tb, clk_tb;
    wire [1:0] o_tb;
    integer index; 
    reg [9:0] data;
    
    SC uut(.i(i_tb), .clk(clk_tb), .o(o_tb));
    
    initial begin 
        i_tb = 0;
        data = 10'b0001101011;
        index = 0;
    end
    
    initial begin
        clk_tb = 0;
        forever begin 
            #20; 
            clk_tb = ~clk_tb;
        end
    end
    
    always @ (posedge clk_tb) begin
        i_tb = data >> index;
        index = index +1;
    end
endmodule
