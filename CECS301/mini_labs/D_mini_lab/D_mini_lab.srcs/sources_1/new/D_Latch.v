`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/15/2022 04:13:42 PM
// Design Name: 
// Module Name: D_Latch
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


module D_Latch(
    input d, 
    input en,
    output q,
    output q_bar
    );
    
    reg q;
    assign q_bar = ~q;
    
    always@(en, d) begin
        if (en) q <= d;
    end
endmodule
