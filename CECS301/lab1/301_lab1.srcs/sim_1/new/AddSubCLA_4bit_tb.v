`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 301 Sec 03 - Spring 2022
// Engineer: Marwin Gonzales
// Create Date: 02/10/2022 03:24:07 PM
// Design Name: 301_lab1
// Module Name: AddSubCLA_4bit_tb
// Revision 0.01 - File Created
//////////////////////////////////////////////////////////////////////////////////

module AddSubCLA_4bit_tb( );
    
    reg [3:0] a_tb, b_tb;
    reg  sel_tb;    
    wire c_out_tb, of_tb;
    wire [3:0] sum_tb;
    
    localparam period = 100;
    
    AddSubCLA_4bit uut (.a(a_tb), .b(b_tb), .sel(sel_tb), .sum(sum_tb), .carry(c_out_tb), .overflow(of_tb));
    
    initial begin
//        //case 1
//        a_tb = 4'b0101;
//        b_tb = 4'b1001;
//        sel_tb = 0;      //adding
//        #period;
        
//        a_tb = 4'b0101;
//        b_tb = 4'b1001;     
//        sel_tb = 1;      //subtracting
//        #period;	
    
//        //case 2
//        a_tb = 4'b1110;
//        b_tb = 4'b0110;
//        sel_tb = 0;      //adding
//        #period;
        
//        a_tb = 4'b1110;
//        b_tb = 4'b0110;     
//        sel_tb = 1;      //subtracting
//        #period;    
        
//        //case 3
//        a_tb = 4'b0111;
//        b_tb = 4'b0100;
//        sel_tb = 0;      //adding
//        #period;
        
//        a_tb = 4'b0111;
//        b_tb = 4'b0100;     
//        sel_tb = 1;      //subtracting
//        #period;    
        
//        //case 4
//        a_tb = 4'b0011;
//        b_tb = 4'b1010;
//        sel_tb = 0;      //adding
//        #period;
        
//        a_tb = 4'b0011;
//        b_tb = 4'b1010;     
//        sel_tb = 1;      //subtracting
//        #period;    
        
//        //case 5
//        a_tb = 4'b1101;
//        b_tb = 4'b0001;
//        sel_tb = 0;      //adding
//        #period;
        
//        a_tb = 4'b1101;
//        b_tb = 4'b0001;     
//        sel_tb = 1;      //subtracting
//        #period;            
    
        // lab demo test cases
        
        a_tb = 4'b0000;
        b_tb = 4'b0000;
        sel_tb = 0;
        #period;
        
        a_tb = 4'b0000;
        b_tb = 4'b0000;
        sel_tb = 1;
        #period;
        
        
        a_tb = 4'b1000;
        b_tb = 4'b0001;
        sel_tb = 0;
        #period;
        
        a_tb = 4'b1000;
        b_tb = 4'b0001;
        sel_tb = 1;
        #period;
        
        
        a_tb = 4'b1010;
        b_tb = 4'b0101;
        sel_tb = 0;
        #period;
        
        a_tb = 4'b1010;
        b_tb = 4'b0101;
        sel_tb = 1;
        #period;
        
        
        a_tb = 4'b0010;
        b_tb = 4'b1110;
        sel_tb = 0;
        #period;
        
        a_tb = 4'b0010;
        b_tb = 4'b1110;
        sel_tb = 1;
        #period;
                                                      
    
	$finish;
    end  
endmodule