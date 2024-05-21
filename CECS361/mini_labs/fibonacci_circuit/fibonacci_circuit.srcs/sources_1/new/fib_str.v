`timescale 1ns / 1ps

module fib_str(
    input en, input clk, input rst,
    output [15:0] out
);

wire [15:0] d1, d0;
wire [15:0] q1, q0;
dff reg1(.d(d1), .q(q1), .clk(clk), .rst(rst), .default_value(1'b1));
dff reg0(.d(d0), .q(q0), .clk(clk), .rst(rst), .default_value(1'b0));

mux mux1(.in0(q1), .in1(out), .sel(en), .out(d1));
mux mux0(.in0(q0), .in1(q1), .sel(en), .out(d0));

assign out = q1 + q0;

endmodule