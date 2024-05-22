`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// Create Date: 11/13/2022 02:43:11 PM
// Design Name: 
// Module Name: digital_clock
// Project Name: 
//////////////////////////////////////////////////////////////////////////////////
/*module digital_clockHex(
    input clk,
    input reset,
    input [16:0] time_in,   // concatenated time input
    output [16:0] time_out  // concatenated time output
    );
 
    // separate time signals
    wire [5:0] sec_in;
    wire [5:0] min_in;
    wire [4:0] hrs_in;
    reg [5:0] sec_out;
    reg [5:0] min_out;
    reg [4:0] hrs_out;
    
    // concatenate signals into input and output
    assign {hrs_in, min_in, sec_in} = time_in;
    assign time_out = {hrs_out, min_out, sec_out};
 
    // seconds   
    always@ (posedge clk or posedge reset) begin
        if (reset) begin
            sec_out <= sec_in;
        end
        else begin
            // seconds count up to 59, before going back to 0 and counting up again
            sec_out <= (sec_out == 6'd59) ? 6'd0 : (sec_out + 6'd1);
        end
    end
    
    // minutes
    always@ (posedge clk or posedge reset) begin
        if (reset) begin
            min_out <= min_in;
        end
        else begin
            if (sec_out == 6'd59) begin
                // as seconds count up, minutes count up to 59, go back to 0 and count up again
                min_out <= (min_out == 6'd59) ? 6'd0 : (min_out + 6'd1);
            end
        end
    end
    
    // hours
    always@ (posedge clk or posedge reset) begin
        if (reset) begin
            hrs_out <= hrs_in;
        end
        else begin
            if ((sec_out == 6'd59) & (min_out == 6'd59)) begin
                hrs_out <= (hrs_out == 5'd23) ? 5'd0 : (hrs_out + 5'd1);
            end
        end
    end         
endmodule*/

module digital_clock(
    input clk,
    input reset,
    input [19:0] time_in,
    output [19:0] time_out
);

    wire [6:0] sec_in;
    wire [6:0] min_in;
    wire [5:0] hrs_in;
    reg [6:0] sec_out;
    reg [6:0] min_out;
    reg [5:0] hrs_out;
    
    assign {hrs_in, min_in, sec_in} = time_in;
    assign time_out = {hrs_out, min_out, sec_out};
    
    // seconds
    always@ (posedge clk or reset) begin
        if (reset) begin
            sec_out <= sec_in;
        end
        else begin
            casex(sec_out) // casex allows for "Z", "?", and "X" to be treated as don't cares
                7'h59:
                    begin
                        sec_out <= 7'd0;
                    end
                7'h?9:
                    begin
                        sec_out <= {(sec_out[6:4] + 3'd1), 4'h0};
                    end
                default:
                    begin
                        sec_out <= sec_out + 7'd1;
                    end
                endcase
            end
        end
    
    // minutes
    always@ (posedge clk or posedge reset) begin
        if (reset) begin
            min_out <= min_in;
        end
        else begin
            if (sec_out == 7'h59) begin
                casex(min_out)
                    7'h59:
                        begin
                            min_out <= 7'h0;
                        end
                    7'h?9:
                        begin
                            min_out <= {(min_out[6:4]+3'd1), 4'h0};
                        end
                    default:
                        begin
                            min_out <= min_out + 7'd1;
                        end
                    endcase
                end
            end
        end

    always@ (posedge clk or posedge reset) begin
        if (reset) begin
            hrs_out <= hrs_in;
        end
        else begin
            if ((sec_out == 7'h59) & (min_out == 7'h59)) begin
                casex(hrs_out)
                    6'h23:
                        begin
                            hrs_out <= 6'd0;
                        end
                    6'b0?1011: // 09 & 19
                        begin
                            hrs_out <= {(hrs_out[5:4] + 3'd1), 4'd0};
                        end
                    default:
                        begin
                            hrs_out <= hrs_out + 6'd1;
                        end
                endcase
            end
        end
    end
endmodule