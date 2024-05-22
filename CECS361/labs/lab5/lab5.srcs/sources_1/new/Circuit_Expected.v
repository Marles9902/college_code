`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 361 - Fall 2022
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 11/28/2022 02:02:34 PM
// Module Name: Circuit_Expected
//////////////////////////////////////////////////////////////////////////////////
module Circuit_Expected(
    input A,
    input B,
    input C,
    output F0,
    output F1
    );
    
    // Write the code for the expected circuit either structurally or behaviorally. 
    assign {F1, F0} = A + B + C;        // behaviorial              
   
endmodule