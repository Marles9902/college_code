`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// 
// Create Date: 03/08/2022 03:36:51 PM
// Design Name: 
// Module Name: SD
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


module SD(
    input i,
    input clk,
    output reg o
    );
    
    localparam [1:0] s0=2'b00, s1=2'b01, s2=2'b10;
    
    reg [1:0] c_state, n_state;
    
    always @ (posedge clk) begin
        c_state <= n_state;
    end
    
    // mini lab example
    always @ (*) begin
        case (c_state)
            s0: begin
                n_state = (i) ? s1:s0;
                o = 1'b0;
                end
            s1: begin
                n_state = (i) ? s1:s2;
                o = 1'b0;
                end
            s2: begin
                n_state = (i) ? s1:s0;
                o = (i) ? 1'b1:1'b0;
                end
            default: begin
                n_state = s0;
                o = 1'b0;
                end
        endcase
    end
    
    // homework example
//    always @ (*) begin
//        case (c_state)
//            s0: begin
//                n_state = (i) ? s0:s1;
//                o = (i) ? 1'b0:1'b1;
//                end
//            s1: begin
//                n_state = (i) ? s0:s2;
//                o = 1'b0;
//                end
//            s2: begin
//                n_state = (i) ? s2:s1;
//                o = (i) ? 1'b1:1'b0;
//                end
//            default: begin
//                n_state = s0;
//                o = 1'b0;
//                end
//        endcase
//    end

endmodule
