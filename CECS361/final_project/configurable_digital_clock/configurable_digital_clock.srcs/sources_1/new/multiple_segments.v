`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/18/2022 04:13:53 PM
// Design Name: 
// Module Name: multiple_segments
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


module multiple_segments(
    input clk,
    input reset,
    input [7:0]data_out,
    output [7:0]cathode,
    output reg [7:0]anode 
    );
    
    reg [1:0] digit; // number 567, 5 is digit=2, 6 is digit=1, 7 is digit=0
    reg [3:0] data_digit_lcd; // value of digit to display
    reg [26:0] tick;
    
    always@(posedge clk, posedge reset) begin
        if(reset) begin
            tick <= 27'b0;
            data_digit_lcd <= 4'b0;
            anode <= 8'b1111_1000;
            digit <= 2'b00;
        end
        else if(tick == 500000) begin
            tick <= 27'b0; // 100000000 ticks is 1 second, 1000000 is .01 seconds, 500000 is .005 seconds
            
            if(digit == 0)begin
                data_digit_lcd <= data_out/100; // num/100 is left digit
                anode <= 8'b1111_1011; // Display hundreds digit
                digit <= 2'b01; // 1, digit 0 to 1
            end
            else if(digit == 1)begin
                data_digit_lcd <= (data_out%100)/10; // (num%100)/10 is middle digit
                anode <= 8'b1111_1101; // Display tens digit
                digit <= 2'b10; // 2, digit 1 to 2
            end
            else begin
                data_digit_lcd <= data_out%10; // num%10 is right digit
                anode <= 8'b1111_1110; // Display ones digit
                digit <= 2'b00; // 0, digit 2 to 0
            end
            
        end
        else begin
            tick <= tick + 1'b1;
        end
    
    end       
    
    BCD_To_7seg BCD(.Q(data_digit_lcd), .cathode(cathode));
    
endmodule
