@echo off
set xv_path=C:\\Xilinx\\Vivado\\2016.2\\bin
call %xv_path%/xelab  -wto a55579309b96499eb625764ea3fe8e8a -m64 --debug typical --relax --mt 2 -L xil_defaultlib -L unisims_ver -L unimacro_ver -L secureip --snapshot majority_sample_tb_behav xil_defaultlib.majority_sample_tb xil_defaultlib.glbl -log elaborate.log
if "%errorlevel%"=="0" goto SUCCESS
if "%errorlevel%"=="1" goto END
:END
exit 1
:SUCCESS
exit 0
