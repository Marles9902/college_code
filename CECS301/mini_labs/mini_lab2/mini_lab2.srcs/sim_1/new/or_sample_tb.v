`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/27/2022 04:03:24 PM
// Design Name: 
// Module Name: or_sample_tb
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


module or_sample_tb(
    );
    
    // Create registers and wires
    reg a_tb, b_tb;
    wire out_tb;
    
    // Duration for each bit
    localparam period = 250;
    
    // Instantiate the Module
    or_sample uut(.a(a_tb), .b(b_tb), .out(out_tb));
    
    initial begin
        a_tb = 0;
        b_tb = 0;
        #period;
            
        a_tb = 0;
        b_tb = 1;
        #period;
        
        a_tb = 1;
        b_tb = 0;
        #period;
           
        a_tb = 1;
        b_tb = 1;
        #period;
    end
endmodule
