`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 02/03/2022 04:09:19 PM
// Design Name: 
// Module Name: or_fromMUX_tb
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


module or_fromMUX_tb(
    );
    
    reg in0_tb, in1_tb;
    wire o_tb;
    
    localparam period = 250;
    
    or_fromMUX uut(.in0(in0_tb), .in1(in1_tb), .o(o_tb));
    
    initial begin
    
        in0_tb = 0;
        in1_tb = 0;
        #period;
        
        in0_tb = 1;
        in1_tb = 0;
        #period;
        
        in0_tb = 0;
        in1_tb = 1;
        #period;
        
        in0_tb = 1;
        in1_tb = 1;
        #period;
    
        $finish;
        
    end
        
endmodule
