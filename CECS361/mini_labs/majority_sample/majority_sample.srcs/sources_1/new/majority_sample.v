`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// 
// Create Date: 08/23/2022 12:32:57 PM
// Design Name: 
// Module Name: majority_sample
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


module majority_sample(
    input m,
    input e1,
    input e2,
    input e3,
    output o
    );
    
    //Declare internal signals
    wire w1, w2, w3;
    
    //Declare gates
    and u1 (w1, e1, e3);
    and u2 (w2, e1, e2);
    and u3 (w3, e2, e3);
    or u4 (o, m , w1, w2, w3);
endmodule
