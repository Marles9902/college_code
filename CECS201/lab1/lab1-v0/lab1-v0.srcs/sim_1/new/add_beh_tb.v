`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 201 - Spring 2021 
// Engineer: Marwin Gonzales
//////////////////////////////////////////////////////////////////////////////////

module add_beh_tb(

    );
    
    // input to the module under the tetst
    reg [2:0] in0_tb;
    reg [2:0] in1_tb;
    
    // output in the tested module 
    wire [2:0] out_tb;
    wire carry_tb;
    
    // instatiate the module
    add_beh  uut(.in0(in0_tb), .in1(in1_tb), .out(out_tb), .carry(carry_tb));
    
    initial begin
    in0_tb = 3'b000;
    in1_tb = 3'b001;
    #100;
    
    in0_tb = 3'b111;
    in1_tb = 3'b001;
    #100;
    
    // test cases 
    
    in0_tb = 3'b010;
    in1_tb = 3'b101;
    #100;
    
    in0_tb = 3'b110;
    in1_tb = 3'b100;
    #100;
    
    end
    
endmodule
