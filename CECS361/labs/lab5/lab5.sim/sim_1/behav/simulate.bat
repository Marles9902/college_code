@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.2\\bin
call %xv_path%/xsim Circuit_Expected_tb_behav -key {Behavioral:sim_1:Functional:Circuit_Expected_tb} -tclbatch Circuit_Expected_tb.tcl -log simulate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
