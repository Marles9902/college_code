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
set_property webtalk.parent_dir C:/Users/marwi/Desktop/Code/361/final_project/Multiple_7segments/Multiple_7segments.cache/wt [current_project]
set_property parent.project_path C:/Users/marwi/Desktop/Code/361/final_project/Multiple_7segments/Multiple_7segments.xpr [current_project]
set_property default_lib xil_defaultlib [current_project]
set_property target_language Verilog [current_project]
set_property board_part digilentinc.com:nexys-a7-100t:part0:1.0 [current_project]
read_verilog -library xil_defaultlib {
  C:/Users/marwi/Downloads/BCD_To_7seg_REI.v
  C:/Users/marwi/Downloads/DReg_wEnable_REI.v
  C:/Users/marwi/Downloads/Decoder_REI.v
  C:/Users/marwi/Downloads/LCD_3_Digits_REI.v
  C:/Users/marwi/Downloads/SRAM_REI.v
}
foreach dcp [get_files -quiet -all *.dcp] {
  set_property used_in_implementation false $dcp
}
read_xdc C:/Users/marwi/Downloads/NexysA7-100t_REI.xdc
set_property used_in_implementation false [get_files C:/Users/marwi/Downloads/NexysA7-100t_REI.xdc]


synth_design -top SRAM -part xc7a100tcsg324-1


write_checkpoint -force -noxdef SRAM.dcp

catch { report_utilization -file SRAM_utilization_synth.rpt -pb SRAM_utilization_synth.pb }
