`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/01/2022 11:59:20 AM
// Design Name: 
// Module Name: SC
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


module SC(
    input i, 
    input clk,
    output reg [1:0] o
    );
    
    localparam [1:0] s0=2'b00, s1=2'b01, s2=2'b10;
    
    reg [1:0] c_state, n_state;
    
    always @ (posedge clk) begin
    c_state <= n_state;
    end
    
    always @ (*) begin
        case (c_state)
            s0: begin
                n_state = (i) ? s1:s0;
                o = (i) ? 2'b11:2'b00;
                end
            s1: begin
                n_state = (i) ? s2:s1;
                o = (i) ? 2'b11:2'b01;
                end
            s2: begin
                n_state = (i) ? s0:s2;
                o = (i) ? 2'b11:2'b10;
                end
            default: begin
                n_state = s0;
                o = 1'b0;
                end
        endcase
    end
endmodule
