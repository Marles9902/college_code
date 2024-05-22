`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CSULB
// Engineer: Marwin Gonzales
// 
// Create Date: 08/23/2022 12:35:53 PM
// Design Name: 
// Module Name: majority_sample_tb
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


module majority_sample_tb(
    );
    
    // Create registers and wires
    reg m_tb, e1_tb, e2_tb, e3_tb;
    wire o_tb;
    
    // Duration for each bit
    localparam period = 50;
    
    // Instantiate the module
    majority_sample uut(.m(m_tb), .e1(e1_tb), .e2(e2_tb), .e3(e3_tb), .o(o_tb));
    
    initial begin
        m_tb = 0;
        e3_tb = 0;
        e2_tb = 0;
        e1_tb = 0;
        #period;
    
        m_tb = 0;
        e3_tb = 0;
        e2_tb = 0;
        e1_tb = 1;
        #period;

        m_tb = 0;
        e3_tb = 0;
        e2_tb = 1;
        e1_tb = 0;
        #period;

        m_tb = 0;
        e3_tb = 0;
        e2_tb = 1;
        e1_tb = 1;
        #period;

        m_tb = 0;
        e3_tb = 1;
        e2_tb = 0;
        e1_tb = 0;
        #period;
        
        m_tb = 0;
        e3_tb = 1;
        e2_tb = 0;
        e1_tb = 1;
        #period;

        m_tb = 0;
        e3_tb = 1;
        e2_tb = 1;
        e1_tb = 0;
        #period;

        m_tb = 0;
        e3_tb = 1;
        e2_tb = 1;
        e1_tb = 1;
        #period;

        m_tb = 1;
        e3_tb = 0;
        e2_tb = 0;
        e1_tb = 0;
        #period;

        m_tb = 1;
        e3_tb = 0;
        e2_tb = 0;
        e1_tb = 1;
        #period;

        m_tb = 1;
        e3_tb = 0;
        e2_tb = 1;
        e1_tb = 0;
        #period;

        m_tb = 1;
        e3_tb = 0;
        e2_tb = 1;
        e1_tb = 1;
        #period;
        
        m_tb = 1;
        e3_tb = 1;
        e2_tb = 0;
        e1_tb = 0;
        #period;

        m_tb = 1;
        e3_tb = 1;
        e2_tb = 0;
        e1_tb = 1;
        #period;

        m_tb = 1;
        e3_tb = 1;
        e2_tb = 1;
        e1_tb = 0;
        #period;
        
        m_tb = 1;
        e3_tb = 1;
        e2_tb = 1;
        e1_tb = 1;
        #period;
    end
endmodule
