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
set_property webtalk.parent_dir C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.cache/wt [current_project]
set_property parent.project_path C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part digilentinc.com:nexys-a7-100t:part0:1.0 [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.srcs/sources_1/new/Sync_BCD_Counter.v
  C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.srcs/sources_1/new/BCD_To_7seg.v
  C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.srcs/sources_1/new/Top.v
}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.srcs/constrs_1/new/NexysA7-100t.xdc
set_property used_in_implementation false [get_files C:/Users/marwi/Desktop/Code/361/final_project/configurable_digital_clock/configurable_digital_clock.srcs/constrs_1/new/NexysA7-100t.xdc]


synth_design -top Top -part xc7a100tcsg324-1


write_checkpoint -force -noxdef Top.dcp

catch { report_utilization -file Top_utilization_synth.rpt -pb Top_utilization_synth.pb }