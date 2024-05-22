`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 08/30/2022 12:39:33 PM
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
    output o 
    );
    
    reg o;
    
    // State declaration 
    localparam [1:0] s0=2'b00, s1=2'b01, s2=2'b10, s3=2'b11;
    
    // State variables
    reg [1:0] c_state, n_state;
    
    // State register
    always @ (posedge clk) begin
        c_state <= n_state;
    end
    
    // Next state logic (example)
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

    // Next state logic (worked on)
//    always @ (*) begin
//        case (c_state)
//            s0: begin
//                n_state = (i) ? s0:s1;
//                o = 1'b0;
//                end
//            s1: begin
//                n_state = (i) ? s0:s2;
//                o = 1'b0;
//                end
//            s2: begin 
//                n_state = (i) ? s3:s1;
//                o = 1'b0;
//                end
//            s3: begin
//                n_state = (i) ? s0:s1;
//                o = (i) ? 1'b1:1'b0;
//                end
//            default: begin
//                n_state = s0;
//                o = 1'b0;
//                end
//        endcase
//    end
endmodule
