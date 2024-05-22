`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 11/15/2022 04:35:41 PM
// Design Name: 
// Module Name: converter
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
/*module converterHex(
    input [4:0] m_time,
    output AM_PM,
    output [3:0] s_time
    );
    
    wire [4:0] m_time_temp;
    
    assign m_time_temp = m_time - 5'd12;
    
    assign AM_PM = (m_time > 5'd11);
    assign s_time = ((m_time == 5'd0) | (m_time == 5'd12)) ? 4'd12 : ((AM_PM) ? m_time_temp[3:0] : m_time[3:0]);
endmodule*/

module converter(
    input [5:0] m_time,
    output AM_PM,
    output [4:0] s_time
    );

    wire [5:0] m_time_temp;
    
    assign m_time_temp = m_time - ((m_time[5:1] == 5'b10000) ? 6'h18 : 6'h12);
    assign AM_PM = (m_time > 6'h11);
    assign s_time = ((m_time == 6'h0) | (m_time == 6'h12)) ? 5'h12 : ((AM_PM) ? m_time_temp[4:0] : m_time[4:0]);
endmodule