`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/03/2022 03:58:37 PM
// Design Name: 
// Module Name: or_fromMUX
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


module or_fromMUX(
    input in0, 
    input in1, 
    output o
    );
    
    mux_4to1v2 uut(.a(1'b1), .b(1'b1), .c(1'b1), .d(1'b0), .sel({in1, in0}), .out(o));     // { } <-- concatenation
    
endmodule
