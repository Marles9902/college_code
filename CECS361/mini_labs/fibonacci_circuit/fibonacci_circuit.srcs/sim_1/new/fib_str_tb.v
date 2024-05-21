`timescale 1ns / 1ps

module fib_str_tb();

reg en_tb, clk_tb, rst_tb;
wire [15:0] out_tb;

fib_str uut(.en(en_tb), .clk(clk_tb), .rst(rst_tb), .out(out_tb));

always #10 clk_tb = ~clk_tb;

initial begin
    clk_tb = 0; rst_tb = 1;
    #100;
    
    rst_tb = 0;
    en_tb = 1;
    
end

endmodule