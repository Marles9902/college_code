`timescale 1ns / 1ps

module fib_beh_tb();

reg en_tb, clk_tb, rst_tb;
wire [15:0] out_str_tb, out_beh_tb;

fib_str uut0(.en(en_tb), .clk(clk_tb), .rst(rst_tb), .out(out_str_tb));
fib_beh uut1(.en(en_tb), .clk(clk_tb), .rst(rst_tb), .out(out_beh_tb));

always #10 clk_tb = ~clk_tb;

initial begin
    clk_tb = 0; rst_tb = 1; en_tb = 0;
    #20;
    
    rst_tb = 0;
    #20;
    en_tb = 1;
    
end

endmodule
