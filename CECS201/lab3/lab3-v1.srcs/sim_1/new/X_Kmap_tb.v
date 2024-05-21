`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: CECS-201 Sec 01 
// Engineer: Marwin Gonzales 
//////////////////////////////////////////////////////////////////////////////////

module X_Kmap_tb;
    // inputs 
    reg a_tb;
    reg b_tb;
    reg c_tb;
    reg d_tb;
    // ouputs
    wire XK_out_tb;
    
    // instantiate Unit Under Test
    X_Kmap uut (.a(a_tb), .b(b_tb), .c(c_tb), .d(d_tb), . XK_out(XK_out_tb));
    
    initial begin
            // initialize inputs
        a_tb = 0;
        b_tb = 0;
        c_tb = 0;
        d_tb = 0;
        #100; // m0: expected K_out_tb = 0
        
        a_tb = 0;
        b_tb = 0;
        c_tb = 0;
        d_tb = 1;
        #100; // m1: expected K_out_tb = 0
        
        a_tb = 0;
        b_tb = 0;
        c_tb = 1;
        d_tb = 0;
        #100; // m2: expected K_out_tb = 0
        
        a_tb = 0;
        b_tb = 0;
        c_tb = 1;
        d_tb = 1;
        #100; // m3: expected K_out_tb = 0
        
        a_tb = 0;
        b_tb = 1;
        c_tb = 0;
        d_tb = 0;
        #100; // m4: expected K_out_tb = 1
        
        a_tb = 0;
        b_tb = 1;
        c_tb = 0;
        d_tb = 1;
        #100; // m5: expected K_out_tb = 1
        
        a_tb = 0;
        b_tb = 1;
        c_tb = 1;
        d_tb = 0;
        #100; // m6: expected K_out_tb = 1
        
        a_tb = 0;
        b_tb = 1;
        c_tb = 1;
        d_tb = 1;
        #100; // m7: expected K_out_tb = 1
        
        a_tb = 1;
        b_tb = 0;
        c_tb = 0;
        d_tb = 0;
        #100; // m8: expected K_out_tb = 0
        
        a_tb = 1;
        b_tb = 0;
        c_tb = 0;
        d_tb = 1;
        #100; // m9: expected K_out_tb = 0
        
        a_tb = 1;
        b_tb = 0;
        c_tb = 1;
        d_tb = 0;
        #100;  // m10: expected K_out_tb = 0
        
        a_tb = 1;
        b_tb = 0;
        c_tb = 1;
        d_tb = 1;
        #100; // m11: expected K_out_tb = 0
        
        a_tb = 1;
        b_tb = 1;
        c_tb = 0;
        d_tb = 0;
        #100; // m12: expected K_out_tb = 1
        
        a_tb = 1;
        b_tb = 1;
        c_tb = 0;
        d_tb = 1;
        #100; // m13: expected K_out_tb = 1
        
        a_tb = 1;
        b_tb = 1;
        c_tb = 1;
        d_tb = 0;
        #100; // m14: expected K_out_tb = 1
        
        a_tb = 1;
        b_tb = 1;
        c_tb = 1;
        d_tb = 1;
        #100; // m15: expected K_out_tb = 0
        
    end
    
endmodule
