`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 04:15:03 PM
// Design Name: 
// Module Name: D_tb
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


module D_tb(
    );
    
    reg d_tb, clk_tb;
    wire q_tb_ff, q_tb_latch;
    integer index;
    reg [0:15] data;
    
    D_FF uut1(.d(d_tb), .clk(clk_tb), .q(q_tb_ff));
    D_Latch uut2(.d(d_tb), .en(clk_tb), .q(q_tb_latch));
    
    initial begin 
        data = 16'b0100010111101001;
        index=0;
        d_tb=0;
    end
    
    initial begin
        clk_tb = 0;
            forever begin 
                #20;
                clk_tb = ~clk_tb;
        end
    end
    
    always @ (posedge clk_tb) begin
        d_tb = data >> index;
        index = index + 1;
        #10;
        d_tb = data >> index;
        index = index + 1;
    end
    
endmodule
