################################################################################

# This XDC is used only for OOC mode of synthesis, implementation
# This constraints file contains default clock frequencies to be used during
# out-of-context flows such as OOC Synthesis and Hierarchical Designs.
# This constraints file is not used in normal top-down synthesis (default flow
# of Vivado)
################################################################################
create_clock -name Mhz10ClkDcxo1_ClkIn -period 100 [get_ports Mhz10ClkDcxo1_ClkIn]
create_clock -name Mhz10ClkDcxo2_ClkIn -period 100 [get_ports Mhz10ClkDcxo2_ClkIn]
create_clock -name Mhz10ClkMac_ClkIn -period 100 [get_ports Mhz10ClkMac_ClkIn]
create_clock -name Mhz10ClkSma_ClkIn -period 100 [get_ports Mhz10ClkSma_ClkIn]
create_clock -name PcieRefClockN -period 10 [get_ports PcieRefClockN]
create_clock -name PcieRefClockP -period 10 [get_ports PcieRefClockP]
create_clock -name Mhz200Clk_ClkIn_clk_p -period 5 [get_ports Mhz200Clk_ClkIn_clk_p]

################################################################################