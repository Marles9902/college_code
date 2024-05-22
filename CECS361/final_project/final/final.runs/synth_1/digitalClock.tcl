# 
# Synthesis run script generated by Vivado
# 

set_param xicom.use_bs_reader 1
set_msg_config -id {HDL 9-1061} -limit 100000
set_msg_config -id {HDL 9-1654} -limit 100000
create_project -in_memory -part xc7a100tcsg324-1

set_param project.singleFileAddWarning.threshold 0
set_param project.compositeFile.enableAutoGeneration 0
set_param synth.vivado.isSynthRun true
set_property webtalk.parent_dir C:/Users/marwi/Desktop/Code/361/final_project/final/final.cache/wt [current_project]
set_property parent.project_path C:/Users/marwi/Desktop/Code/361/final_project/final/final.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part digilentinc.com:nexys-a7-100t:part0:1.0 [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/marwi/Desktop/Code/361/final_project/final/final.srcs/sources_1/new/sevenSegment.v
  C:/Users/marwi/Desktop/Code/361/final_project/final/final.srcs/sources_1/new/digitalClock.v
}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc C:/Users/marwi/Desktop/Code/361/final_project/final/final.srcs/constrs_1/new/constraint.xdc
set_property used_in_implementation false [get_files C:/Users/marwi/Desktop/Code/361/final_project/final/final.srcs/constrs_1/new/constraint.xdc]


synth_design -top digitalClock -part xc7a100tcsg324-1


write_checkpoint -force -noxdef digitalClock.dcp

catch { report_utilization -file digitalClock_utilization_synth.rpt -pb digitalClock_utilization_synth.pb }