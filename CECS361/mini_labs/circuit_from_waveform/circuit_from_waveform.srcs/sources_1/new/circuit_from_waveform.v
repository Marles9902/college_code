`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// Create Date: 10/19/2022 03:14:33 PM
// Design Name: circuit_from_wavefrom
// Module Name: circuit_from_waveform
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module circuit_from_waveform(
    input clk, a,
    output reg [2:0] out = 3'b100
    );
    
    always@(posedge clk) begin
        if(a) begin
            out <= 3'b100;
        end
        else begin
            if(out < 3'b110) begin
                out <= out + 3'b001;
            end
            else begin
                out <= 3'b000;
            end 
        end
    end
endmodule
