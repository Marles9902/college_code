`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 01/25/2022 03:33:17 PM
// Design Name: 
// Module Name: and_sample_tb
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


module and_sample_tb(
    );
    
    // Create registers and wires
    reg a_tb, b_tb;
    wire out_tb;
    
    // Duration for each bit
    localparam period = 100;
    
    // Instantiate the Module
    and_sample uut(.a(a_tb), .b(b_tb), .out(out_tb));
    
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
        $finish;
    end
endmodule
