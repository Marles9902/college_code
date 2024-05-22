`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS 361 - Fall 2022
// Engineer: Rei Angelo Amurao, Marwin Gonzales, Joshua Siajuat
// Create Date: 11/28/2022 01:26:49 PM
// Module Name: Circuit_Expected_tb
//////////////////////////////////////////////////////////////////////////////////
module Circuit_Expected_tb();
    reg A, B, C;
    wire F0, F1;
    integer i;

    Circuit_Expected uut(.A(A), .B(B), .C(C), .F0(F0), .F1(F1));
    
    // Check all the possile cases. There are three inputs. Thus, there should be 8 cases.
    initial begin 
        for (i = 0; i < 8; i = i + 1) begin
            {A, B, C} = i;
            #10;
        end
        $finish;
    end
endmodule