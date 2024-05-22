`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/15/2022 04:42:44 PM
// Design Name: 
// Module Name: converter_tb
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
module converter_tb();

   // reg [4:0] m_timeHex;
    reg [5:0] m_time_tb;
    //wire AM_PM_Hex;
    wire AM_PM_tb;
    //wire [3:0] s_timeHex;
    wire [4:0] s_time_tb;
    
    //converterHex uutHex (.m_time(m_timeHex), .AM_PM(AM_PM_Hex), .s_time(s_timeHex));
    converter uut (.m_time(m_time_tb), .AM_PM(AM_PM_tb), .s_time(s_time_tb));
    
    //always #100 m_timeHex = (m_timeHex == 5'd23) ? 0 : m_timeHex + 1;
    always #100 m_time_tb = (m_time_tb == 6'h23) ? 0 : (((m_time_tb == 6'h9) | (m_time_tb == 6'h19)) ? (m_time_tb + 7) : (m_time_tb + 1));
    
    initial begin
        //m_timeHex = 0;
        m_time_tb = 0;
    end
endmodule