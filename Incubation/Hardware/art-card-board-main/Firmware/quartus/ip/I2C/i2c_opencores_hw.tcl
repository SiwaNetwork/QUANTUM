# TCL File Generated by Component Editor 18.1
# Tue Dec 17 15:56:49 CET 2019
# DO NOT MODIFY


# 
# i2c_opencores "Avalon I2C (Master) OpenCores" v1.0
#  2019.12.17.15:56:48
# 
# 

# 
# request TCL package from ACDS 16.1
# 
package require -exact qsys 16.1


# 
# module i2c_opencores
# 
set_module_property DESCRIPTION ""
set_module_property NAME i2c_opencores
set_module_property VERSION 1.0
set_module_property INTERNAL false
set_module_property OPAQUE_ADDRESS_MAP true
set_module_property GROUP OpenCores
set_module_property AUTHOR ""
set_module_property DISPLAY_NAME "Avalon I2C (Master) OpenCores"
set_module_property INSTANTIATE_IN_SYSTEM_MODULE true
set_module_property EDITABLE true
set_module_property REPORT_TO_TALKBACK false
set_module_property ALLOW_GREYBOX_GENERATION false
set_module_property REPORT_HIERARCHY false


# 
# file sets
# 
add_fileset QUARTUS_SYNTH QUARTUS_SYNTH "" ""
set_fileset_property QUARTUS_SYNTH TOP_LEVEL i2c_master_top
set_fileset_property QUARTUS_SYNTH ENABLE_RELATIVE_INCLUDE_PATHS false
set_fileset_property QUARTUS_SYNTH ENABLE_FILE_OVERWRITE_MODE false
add_fileset_file i2c_master_bit_ctrl.vhd VHDL PATH i2c_master_bit_ctrl.vhd
add_fileset_file i2c_master_byte_ctrl.vhd VHDL PATH i2c_master_byte_ctrl.vhd
add_fileset_file i2c_master_top.vhd VHDL PATH i2c_master_top.vhd TOP_LEVEL_FILE


# 
# parameters
# 
add_parameter ARST_LVL STD_LOGIC 0
set_parameter_property ARST_LVL DEFAULT_VALUE 0
set_parameter_property ARST_LVL DISPLAY_NAME ARST_LVL
set_parameter_property ARST_LVL TYPE STD_LOGIC
set_parameter_property ARST_LVL UNITS None
set_parameter_property ARST_LVL ALLOWED_RANGES 0:1
set_parameter_property ARST_LVL HDL_PARAMETER true


# 
# display items
# 


# 
# connection point interrupt_sender
# 
add_interface interrupt_sender interrupt end
set_interface_property interrupt_sender associatedAddressablePoint ""
set_interface_property interrupt_sender associatedClock clock
set_interface_property interrupt_sender associatedReset reset_wb
set_interface_property interrupt_sender bridgedReceiverOffset ""
set_interface_property interrupt_sender bridgesToReceiver ""
set_interface_property interrupt_sender ENABLED true
set_interface_property interrupt_sender EXPORT_OF ""
set_interface_property interrupt_sender PORT_NAME_MAP ""
set_interface_property interrupt_sender CMSIS_SVD_VARIABLES ""
set_interface_property interrupt_sender SVD_ADDRESS_GROUP ""

add_interface_port interrupt_sender wb_inta_o irq Output 1


# 
# connection point clock
# 
add_interface clock clock end
set_interface_property clock clockRate 0
set_interface_property clock ENABLED true
set_interface_property clock EXPORT_OF ""
set_interface_property clock PORT_NAME_MAP ""
set_interface_property clock CMSIS_SVD_VARIABLES ""
set_interface_property clock SVD_ADDRESS_GROUP ""

add_interface_port clock wb_clk_i clk Input 1


# 
# connection point reset
# 
add_interface reset reset end
set_interface_property reset associatedClock clock
set_interface_property reset synchronousEdges DEASSERT
set_interface_property reset ENABLED true
set_interface_property reset EXPORT_OF ""
set_interface_property reset PORT_NAME_MAP ""
set_interface_property reset CMSIS_SVD_VARIABLES ""
set_interface_property reset SVD_ADDRESS_GROUP ""

add_interface_port reset arst_i reset Input 1


# 
# connection point reset_wb
# 
add_interface reset_wb reset end
set_interface_property reset_wb associatedClock clock
set_interface_property reset_wb synchronousEdges DEASSERT
set_interface_property reset_wb ENABLED true
set_interface_property reset_wb EXPORT_OF ""
set_interface_property reset_wb PORT_NAME_MAP ""
set_interface_property reset_wb CMSIS_SVD_VARIABLES ""
set_interface_property reset_wb SVD_ADDRESS_GROUP ""

add_interface_port reset_wb wb_rst_i reset Input 1


# 
# connection point csr
# 
add_interface csr avalon end
set_interface_property csr addressUnits WORDS
set_interface_property csr associatedClock clock
set_interface_property csr associatedReset reset_wb
set_interface_property csr bitsPerSymbol 8
set_interface_property csr burstOnBurstBoundariesOnly false
set_interface_property csr burstcountUnits WORDS
set_interface_property csr explicitAddressSpan 0
set_interface_property csr holdTime 0
set_interface_property csr linewrapBursts false
set_interface_property csr maximumPendingReadTransactions 0
set_interface_property csr maximumPendingWriteTransactions 0
set_interface_property csr readLatency 0
set_interface_property csr readWaitTime 1
set_interface_property csr setupTime 0
set_interface_property csr timingUnits Cycles
set_interface_property csr writeWaitTime 0
set_interface_property csr ENABLED true
set_interface_property csr EXPORT_OF ""
set_interface_property csr PORT_NAME_MAP ""
set_interface_property csr CMSIS_SVD_VARIABLES ""
set_interface_property csr SVD_ADDRESS_GROUP ""

add_interface_port csr wb_adr_i address Input 3
add_interface_port csr wb_dat_i writedata Input 8
add_interface_port csr wb_dat_o readdata Output 8
add_interface_port csr wb_we_i write Input 1
add_interface_port csr wb_stb_i chipselect Input 1
add_interface_port csr wb_ack_o waitrequest_n Output 1
set_interface_assignment csr embeddedsw.configuration.isFlash 0
set_interface_assignment csr embeddedsw.configuration.isMemoryDevice 0
set_interface_assignment csr embeddedsw.configuration.isNonVolatileStorage 0
set_interface_assignment csr embeddedsw.configuration.isPrintableDevice 0


# 
# connection point i2c_serial
# 
add_interface i2c_serial conduit end
set_interface_property i2c_serial associatedClock clock
set_interface_property i2c_serial associatedReset reset
set_interface_property i2c_serial ENABLED true
set_interface_property i2c_serial EXPORT_OF ""
set_interface_property i2c_serial PORT_NAME_MAP ""
set_interface_property i2c_serial CMSIS_SVD_VARIABLES ""
set_interface_property i2c_serial SVD_ADDRESS_GROUP ""

add_interface_port i2c_serial scl_pad_i scl_pad_i Input 1
add_interface_port i2c_serial scl_pad_o scl_pad_o Output 1
add_interface_port i2c_serial scl_padoen_o scl_padoen_o Output 1
add_interface_port i2c_serial sda_pad_i sda_pad_i Input 1
add_interface_port i2c_serial sda_pad_o sda_pad_o Output 1
add_interface_port i2c_serial sda_padoen_o sda_padoen_o Output 1

