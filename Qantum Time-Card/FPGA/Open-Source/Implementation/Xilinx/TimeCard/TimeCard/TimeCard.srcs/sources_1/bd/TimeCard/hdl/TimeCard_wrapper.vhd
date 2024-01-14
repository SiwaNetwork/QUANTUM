--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
--Date        : Sun Jan 14 23:01:34 2024
--Host        : HOME-PC running 64-bit major release  (build 9200)
--Command     : generate_target TimeCard_wrapper.bd
--Design      : TimeCard_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity TimeCard_wrapper is
  port (
    Clk_RxSdaT_EnaOut : out STD_LOGIC;
    Clk_RxSda_DatIn : in STD_LOGIC;
    Clk_RxSda_DatOut : out STD_LOGIC;
    Clk_TxSclT_EnaOut : out STD_LOGIC;
    Clk_TxScl_DatIn : in STD_LOGIC;
    Clk_TxScl_DatOut : out STD_LOGIC;
    Ext_DatIn_tri_i : in STD_LOGIC_VECTOR ( 1 downto 0 );
    Ext_DatOut : out STD_LOGIC_VECTOR ( 6 downto 0 );
    GoldenImageN_EnaIn : in STD_LOGIC;
    GpioGnss_DatOut_tri_o : out STD_LOGIC_VECTOR ( 1 downto 0 );
    GpioMac_DatIn_tri_i : in STD_LOGIC_VECTOR ( 1 downto 0 );
    I2c_scl_io : inout STD_LOGIC;
    I2c_sda_io : inout STD_LOGIC;
    InHoldover_DatOut : out STD_LOGIC;
    InSync_DatOut : out STD_LOGIC;
    MacPps0_EvtOut : out STD_LOGIC;
    MacPps1_EvtOut : out STD_LOGIC;
    MacPps_EvtIn : in STD_LOGIC;
    Mhz10ClkDcxo1_ClkIn : in STD_LOGIC;
    Mhz10ClkDcxo2_ClkIn : in STD_LOGIC;
    Mhz10ClkMac_ClkIn : in STD_LOGIC;
    Mhz10ClkSma_ClkIn : in STD_LOGIC;
    Mhz200Clk_ClkIn_clk_n : in STD_LOGIC;
    Mhz200Clk_ClkIn_clk_p : in STD_LOGIC;
    Mhz50Clk_ClkOut : out STD_LOGIC;
    Mhz50Clk_ClkOut_0 : out STD_LOGIC;
    Mhz62_5Clk_ClkOut : out STD_LOGIC;
    PciePerstN_RstIn : in STD_LOGIC;
    PcieRefClockN : in STD_LOGIC_VECTOR ( 0 to 0 );
    PcieRefClockP : in STD_LOGIC_VECTOR ( 0 to 0 );
    PpsGnss1_EvtIn : in STD_LOGIC;
    PpsGnss2_EvtIn : in STD_LOGIC;
    Pps_EvtOut : out STD_LOGIC;
    Reset50MhzN_RstOut : out STD_LOGIC_VECTOR ( 0 to 0 );
    Reset50MhzN_RstOut_0 : out STD_LOGIC_VECTOR ( 0 to 0 );
    Reset62_5MhzN_RstOut : out STD_LOGIC_VECTOR ( 0 to 0 );
    ResetN_RstIn : in STD_LOGIC;
    SmaIn1_DatIn : in STD_LOGIC;
    SmaIn1_EnOut : out STD_LOGIC;
    SmaIn2_DatIn : in STD_LOGIC;
    SmaIn2_EnOut : out STD_LOGIC;
    SmaIn3_DatIn : in STD_LOGIC;
    SmaIn3_EnOut : out STD_LOGIC;
    SmaIn4_DatIn : in STD_LOGIC;
    SmaIn4_EnOut : out STD_LOGIC;
    SmaOut1_DatOut : out STD_LOGIC;
    SmaOut1_EnOut : out STD_LOGIC;
    SmaOut2_DatOut : out STD_LOGIC;
    SmaOut2_EnOut : out STD_LOGIC;
    SmaOut3_DatOut : out STD_LOGIC;
    SmaOut3_EnOut : out STD_LOGIC;
    SmaOut4_DatOut : out STD_LOGIC;
    SmaOut4_EnOut : out STD_LOGIC;
    SpiFlash_io0_io : inout STD_LOGIC;
    SpiFlash_io1_io : inout STD_LOGIC;
    SpiFlash_io2_io : inout STD_LOGIC;
    SpiFlash_io3_io : inout STD_LOGIC;
    SpiFlash_ss_io : inout STD_LOGIC_VECTOR ( 0 to 0 );
    StartUpIo_cfgclk : out STD_LOGIC;
    StartUpIo_cfgmclk : out STD_LOGIC;
    StartUpIo_preq : out STD_LOGIC;
    UartGnss1Rx_DatIn : in STD_LOGIC;
    UartGnss1Tx_DatOut : out STD_LOGIC;
    UartGnss2Rx_DatIn : in STD_LOGIC;
    UartGnss2Tx_DatOut : out STD_LOGIC;
    pcie_7x_mgt_0_rxn : in STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_rxp : in STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_txn : out STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_txp : out STD_LOGIC_VECTOR ( 0 to 0 )
  );
end TimeCard_wrapper;

architecture STRUCTURE of TimeCard_wrapper is
  component TimeCard is
  port (
    Clk_RxSdaT_EnaOut : out STD_LOGIC;
    Clk_RxSda_DatIn : in STD_LOGIC;
    Clk_RxSda_DatOut : out STD_LOGIC;
    Clk_TxSclT_EnaOut : out STD_LOGIC;
    Clk_TxScl_DatIn : in STD_LOGIC;
    Clk_TxScl_DatOut : out STD_LOGIC;
    Ext_DatOut : out STD_LOGIC_VECTOR ( 6 downto 0 );
    GoldenImageN_EnaIn : in STD_LOGIC;
    InHoldover_DatOut : out STD_LOGIC;
    InSync_DatOut : out STD_LOGIC;
    MacPps0_EvtOut : out STD_LOGIC;
    MacPps1_EvtOut : out STD_LOGIC;
    MacPps_EvtIn : in STD_LOGIC;
    Mhz10ClkDcxo1_ClkIn : in STD_LOGIC;
    Mhz10ClkDcxo2_ClkIn : in STD_LOGIC;
    Mhz10ClkMac_ClkIn : in STD_LOGIC;
    Mhz10ClkSma_ClkIn : in STD_LOGIC;
    Mhz50Clk_ClkOut : out STD_LOGIC;
    Mhz50Clk_ClkOut_0 : out STD_LOGIC;
    Mhz62_5Clk_ClkOut : out STD_LOGIC;
    PciePerstN_RstIn : in STD_LOGIC;
    PcieRefClockN : in STD_LOGIC_VECTOR ( 0 to 0 );
    PcieRefClockP : in STD_LOGIC_VECTOR ( 0 to 0 );
    PpsGnss1_EvtIn : in STD_LOGIC;
    PpsGnss2_EvtIn : in STD_LOGIC;
    Pps_EvtOut : out STD_LOGIC;
    Reset50MhzN_RstOut : out STD_LOGIC_VECTOR ( 0 to 0 );
    Reset50MhzN_RstOut_0 : out STD_LOGIC_VECTOR ( 0 to 0 );
    Reset62_5MhzN_RstOut : out STD_LOGIC_VECTOR ( 0 to 0 );
    ResetN_RstIn : in STD_LOGIC;
    SmaIn1_DatIn : in STD_LOGIC;
    SmaIn1_EnOut : out STD_LOGIC;
    SmaIn2_DatIn : in STD_LOGIC;
    SmaIn2_EnOut : out STD_LOGIC;
    SmaIn3_DatIn : in STD_LOGIC;
    SmaIn3_EnOut : out STD_LOGIC;
    SmaIn4_DatIn : in STD_LOGIC;
    SmaIn4_EnOut : out STD_LOGIC;
    SmaOut1_DatOut : out STD_LOGIC;
    SmaOut1_EnOut : out STD_LOGIC;
    SmaOut2_DatOut : out STD_LOGIC;
    SmaOut2_EnOut : out STD_LOGIC;
    SmaOut3_DatOut : out STD_LOGIC;
    SmaOut3_EnOut : out STD_LOGIC;
    SmaOut4_DatOut : out STD_LOGIC;
    SmaOut4_EnOut : out STD_LOGIC;
    StartUpIo_cfgclk : out STD_LOGIC;
    StartUpIo_cfgmclk : out STD_LOGIC;
    StartUpIo_preq : out STD_LOGIC;
    UartGnss1Rx_DatIn : in STD_LOGIC;
    UartGnss1Tx_DatOut : out STD_LOGIC;
    UartGnss2Rx_DatIn : in STD_LOGIC;
    UartGnss2Tx_DatOut : out STD_LOGIC;
    Mhz200Clk_ClkIn_clk_n : in STD_LOGIC;
    Mhz200Clk_ClkIn_clk_p : in STD_LOGIC;
    Ext_DatIn_tri_i : in STD_LOGIC_VECTOR ( 1 downto 0 );
    GpioMac_DatIn_tri_i : in STD_LOGIC_VECTOR ( 1 downto 0 );
    GpioGnss_DatOut_tri_o : out STD_LOGIC_VECTOR ( 1 downto 0 );
    I2c_scl_i : in STD_LOGIC;
    I2c_scl_o : out STD_LOGIC;
    I2c_scl_t : out STD_LOGIC;
    I2c_sda_i : in STD_LOGIC;
    I2c_sda_o : out STD_LOGIC;
    I2c_sda_t : out STD_LOGIC;
    pcie_7x_mgt_0_rxn : in STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_rxp : in STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_txn : out STD_LOGIC_VECTOR ( 0 to 0 );
    pcie_7x_mgt_0_txp : out STD_LOGIC_VECTOR ( 0 to 0 );
    SpiFlash_io0_i : in STD_LOGIC;
    SpiFlash_io0_o : out STD_LOGIC;
    SpiFlash_io0_t : out STD_LOGIC;
    SpiFlash_io1_i : in STD_LOGIC;
    SpiFlash_io1_o : out STD_LOGIC;
    SpiFlash_io1_t : out STD_LOGIC;
    SpiFlash_io2_i : in STD_LOGIC;
    SpiFlash_io2_o : out STD_LOGIC;
    SpiFlash_io2_t : out STD_LOGIC;
    SpiFlash_io3_i : in STD_LOGIC;
    SpiFlash_io3_o : out STD_LOGIC;
    SpiFlash_io3_t : out STD_LOGIC;
    SpiFlash_ss_i : in STD_LOGIC_VECTOR ( 0 to 0 );
    SpiFlash_ss_o : out STD_LOGIC_VECTOR ( 0 to 0 );
    SpiFlash_ss_t : out STD_LOGIC
  );
  end component TimeCard;
  component IOBUF is
  port (
    I : in STD_LOGIC;
    O : out STD_LOGIC;
    T : in STD_LOGIC;
    IO : inout STD_LOGIC
  );
  end component IOBUF;
  signal I2c_scl_i : STD_LOGIC;
  signal I2c_scl_o : STD_LOGIC;
  signal I2c_scl_t : STD_LOGIC;
  signal I2c_sda_i : STD_LOGIC;
  signal I2c_sda_o : STD_LOGIC;
  signal I2c_sda_t : STD_LOGIC;
  signal SpiFlash_io0_i : STD_LOGIC;
  signal SpiFlash_io0_o : STD_LOGIC;
  signal SpiFlash_io0_t : STD_LOGIC;
  signal SpiFlash_io1_i : STD_LOGIC;
  signal SpiFlash_io1_o : STD_LOGIC;
  signal SpiFlash_io1_t : STD_LOGIC;
  signal SpiFlash_io2_i : STD_LOGIC;
  signal SpiFlash_io2_o : STD_LOGIC;
  signal SpiFlash_io2_t : STD_LOGIC;
  signal SpiFlash_io3_i : STD_LOGIC;
  signal SpiFlash_io3_o : STD_LOGIC;
  signal SpiFlash_io3_t : STD_LOGIC;
  signal SpiFlash_ss_i_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal SpiFlash_ss_io_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal SpiFlash_ss_o_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal SpiFlash_ss_t : STD_LOGIC;
begin
I2c_scl_iobuf: component IOBUF
     port map (
      I => I2c_scl_o,
      IO => I2c_scl_io,
      O => I2c_scl_i,
      T => I2c_scl_t
    );
I2c_sda_iobuf: component IOBUF
     port map (
      I => I2c_sda_o,
      IO => I2c_sda_io,
      O => I2c_sda_i,
      T => I2c_sda_t
    );
SpiFlash_io0_iobuf: component IOBUF
     port map (
      I => SpiFlash_io0_o,
      IO => SpiFlash_io0_io,
      O => SpiFlash_io0_i,
      T => SpiFlash_io0_t
    );
SpiFlash_io1_iobuf: component IOBUF
     port map (
      I => SpiFlash_io1_o,
      IO => SpiFlash_io1_io,
      O => SpiFlash_io1_i,
      T => SpiFlash_io1_t
    );
SpiFlash_io2_iobuf: component IOBUF
     port map (
      I => SpiFlash_io2_o,
      IO => SpiFlash_io2_io,
      O => SpiFlash_io2_i,
      T => SpiFlash_io2_t
    );
SpiFlash_io3_iobuf: component IOBUF
     port map (
      I => SpiFlash_io3_o,
      IO => SpiFlash_io3_io,
      O => SpiFlash_io3_i,
      T => SpiFlash_io3_t
    );
SpiFlash_ss_iobuf_0: component IOBUF
     port map (
      I => SpiFlash_ss_o_0(0),
      IO => SpiFlash_ss_io(0),
      O => SpiFlash_ss_i_0(0),
      T => SpiFlash_ss_t
    );
TimeCard_i: component TimeCard
     port map (
      Clk_RxSdaT_EnaOut => Clk_RxSdaT_EnaOut,
      Clk_RxSda_DatIn => Clk_RxSda_DatIn,
      Clk_RxSda_DatOut => Clk_RxSda_DatOut,
      Clk_TxSclT_EnaOut => Clk_TxSclT_EnaOut,
      Clk_TxScl_DatIn => Clk_TxScl_DatIn,
      Clk_TxScl_DatOut => Clk_TxScl_DatOut,
      Ext_DatIn_tri_i(1 downto 0) => Ext_DatIn_tri_i(1 downto 0),
      Ext_DatOut(6 downto 0) => Ext_DatOut(6 downto 0),
      GoldenImageN_EnaIn => GoldenImageN_EnaIn,
      GpioGnss_DatOut_tri_o(1 downto 0) => GpioGnss_DatOut_tri_o(1 downto 0),
      GpioMac_DatIn_tri_i(1 downto 0) => GpioMac_DatIn_tri_i(1 downto 0),
      I2c_scl_i => I2c_scl_i,
      I2c_scl_o => I2c_scl_o,
      I2c_scl_t => I2c_scl_t,
      I2c_sda_i => I2c_sda_i,
      I2c_sda_o => I2c_sda_o,
      I2c_sda_t => I2c_sda_t,
      InHoldover_DatOut => InHoldover_DatOut,
      InSync_DatOut => InSync_DatOut,
      MacPps0_EvtOut => MacPps0_EvtOut,
      MacPps1_EvtOut => MacPps1_EvtOut,
      MacPps_EvtIn => MacPps_EvtIn,
      Mhz10ClkDcxo1_ClkIn => Mhz10ClkDcxo1_ClkIn,
      Mhz10ClkDcxo2_ClkIn => Mhz10ClkDcxo2_ClkIn,
      Mhz10ClkMac_ClkIn => Mhz10ClkMac_ClkIn,
      Mhz10ClkSma_ClkIn => Mhz10ClkSma_ClkIn,
      Mhz200Clk_ClkIn_clk_n => Mhz200Clk_ClkIn_clk_n,
      Mhz200Clk_ClkIn_clk_p => Mhz200Clk_ClkIn_clk_p,
      Mhz50Clk_ClkOut => Mhz50Clk_ClkOut,
      Mhz50Clk_ClkOut_0 => Mhz50Clk_ClkOut_0,
      Mhz62_5Clk_ClkOut => Mhz62_5Clk_ClkOut,
      PciePerstN_RstIn => PciePerstN_RstIn,
      PcieRefClockN(0) => PcieRefClockN(0),
      PcieRefClockP(0) => PcieRefClockP(0),
      PpsGnss1_EvtIn => PpsGnss1_EvtIn,
      PpsGnss2_EvtIn => PpsGnss2_EvtIn,
      Pps_EvtOut => Pps_EvtOut,
      Reset50MhzN_RstOut(0) => Reset50MhzN_RstOut(0),
      Reset50MhzN_RstOut_0(0) => Reset50MhzN_RstOut_0(0),
      Reset62_5MhzN_RstOut(0) => Reset62_5MhzN_RstOut(0),
      ResetN_RstIn => ResetN_RstIn,
      SmaIn1_DatIn => SmaIn1_DatIn,
      SmaIn1_EnOut => SmaIn1_EnOut,
      SmaIn2_DatIn => SmaIn2_DatIn,
      SmaIn2_EnOut => SmaIn2_EnOut,
      SmaIn3_DatIn => SmaIn3_DatIn,
      SmaIn3_EnOut => SmaIn3_EnOut,
      SmaIn4_DatIn => SmaIn4_DatIn,
      SmaIn4_EnOut => SmaIn4_EnOut,
      SmaOut1_DatOut => SmaOut1_DatOut,
      SmaOut1_EnOut => SmaOut1_EnOut,
      SmaOut2_DatOut => SmaOut2_DatOut,
      SmaOut2_EnOut => SmaOut2_EnOut,
      SmaOut3_DatOut => SmaOut3_DatOut,
      SmaOut3_EnOut => SmaOut3_EnOut,
      SmaOut4_DatOut => SmaOut4_DatOut,
      SmaOut4_EnOut => SmaOut4_EnOut,
      SpiFlash_io0_i => SpiFlash_io0_i,
      SpiFlash_io0_o => SpiFlash_io0_o,
      SpiFlash_io0_t => SpiFlash_io0_t,
      SpiFlash_io1_i => SpiFlash_io1_i,
      SpiFlash_io1_o => SpiFlash_io1_o,
      SpiFlash_io1_t => SpiFlash_io1_t,
      SpiFlash_io2_i => SpiFlash_io2_i,
      SpiFlash_io2_o => SpiFlash_io2_o,
      SpiFlash_io2_t => SpiFlash_io2_t,
      SpiFlash_io3_i => SpiFlash_io3_i,
      SpiFlash_io3_o => SpiFlash_io3_o,
      SpiFlash_io3_t => SpiFlash_io3_t,
      SpiFlash_ss_i(0) => SpiFlash_ss_i_0(0),
      SpiFlash_ss_o(0) => SpiFlash_ss_o_0(0),
      SpiFlash_ss_t => SpiFlash_ss_t,
      StartUpIo_cfgclk => StartUpIo_cfgclk,
      StartUpIo_cfgmclk => StartUpIo_cfgmclk,
      StartUpIo_preq => StartUpIo_preq,
      UartGnss1Rx_DatIn => UartGnss1Rx_DatIn,
      UartGnss1Tx_DatOut => UartGnss1Tx_DatOut,
      UartGnss2Rx_DatIn => UartGnss2Rx_DatIn,
      UartGnss2Tx_DatOut => UartGnss2Tx_DatOut,
      pcie_7x_mgt_0_rxn(0) => pcie_7x_mgt_0_rxn(0),
      pcie_7x_mgt_0_rxp(0) => pcie_7x_mgt_0_rxp(0),
      pcie_7x_mgt_0_txn(0) => pcie_7x_mgt_0_txn(0),
      pcie_7x_mgt_0_txp(0) => pcie_7x_mgt_0_txp(0)
    );
end STRUCTURE;
