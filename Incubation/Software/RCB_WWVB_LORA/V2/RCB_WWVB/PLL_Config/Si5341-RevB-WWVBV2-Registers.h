/*
 * Si5341 Rev B Configuration Register Export Header File
 *
 * This file represents a series of Skyworks Si5341 Rev B 
 * register writes that can be performed to load a single configuration 
 * on a device. It was created by a Skyworks ClockBuilder Pro
 * export tool.
 *
 * Part:		                                       Si5341 Rev B
 * Design ID:                                          WWVBV2
 * Includes Pre/Post Download Control Register Writes: Yes
 * Created By:                                         ClockBuilder Pro v4.13 [2024-05-31]
 * Timestamp:                                          2024-06-10 09:58:15 GMT-07:00
 *
 * A complete design report corresponding to this export is included at the end 
 * of this header file.
 *
 */

#ifndef SI5341_REVB_REG_CONFIG_HEADER
#define SI5341_REVB_REG_CONFIG_HEADER

#define SI5341_REVB_REG_CONFIG_NUM_REGS				285

typedef struct
{
	unsigned int address; /* 16-bit register address */
	unsigned char value; /* 8-bit register data */

} si5341_revb_register_t;

si5341_revb_register_t const si5341_revb_registers[SI5341_REVB_REG_CONFIG_NUM_REGS] =
{

	/* Start configuration preamble */
	{ 0x0B24, 0xD8 },
	{ 0x0B25, 0x00 },
	/* Rev B stuck divider fix */
	{ 0x0502, 0x01 },
	{ 0x0505, 0x03 },
	{ 0x0957, 0x1F },
	{ 0x0B4E, 0x1A },
	/* End configuration preamble */

	/* Delay 300 msec */
	/*    Delay is worst case time for device to complete any calibration */
	/*    that is running due to device state change previous to this script */
	/*    being processed. */

	/* Start configuration registers */
	{ 0x000B, 0x74 },
	{ 0x0017, 0x10 },
	{ 0x0018, 0xFE },
	{ 0x0021, 0x09 },
	{ 0x0022, 0x00 },
	{ 0x002B, 0x0A },
	{ 0x002C, 0x31 },
	{ 0x002D, 0x01 },
	{ 0x002E, 0xB1 },
	{ 0x002F, 0x00 },
	{ 0x0030, 0x00 },
	{ 0x0031, 0x00 },
	{ 0x0032, 0x00 },
	{ 0x0033, 0x00 },
	{ 0x0034, 0x00 },
	{ 0x0035, 0x00 },
	{ 0x0036, 0xB1 },
	{ 0x0037, 0x00 },
	{ 0x0038, 0x00 },
	{ 0x0039, 0x00 },
	{ 0x003A, 0x00 },
	{ 0x003B, 0x00 },
	{ 0x003C, 0x00 },
	{ 0x003D, 0x00 },
	{ 0x0041, 0x03 },
	{ 0x0042, 0x00 },
	{ 0x0043, 0x00 },
	{ 0x0044, 0x00 },
	{ 0x009E, 0x00 },
	{ 0x0102, 0x01 },
	{ 0x0108, 0x02 },
	{ 0x0109, 0xCC },
	{ 0x010A, 0x00 },
	{ 0x010B, 0x00 },
	{ 0x010D, 0x02 },
	{ 0x010E, 0xCC },
	{ 0x010F, 0x00 },
	{ 0x0110, 0x00 },
	{ 0x0112, 0x02 },
	{ 0x0113, 0xCC },
	{ 0x0114, 0x00 },
	{ 0x0115, 0x00 },
	{ 0x0117, 0x01 },
	{ 0x0118, 0x09 },
	{ 0x0119, 0x3B },
	{ 0x011A, 0x00 },
	{ 0x011C, 0x02 },
	{ 0x011D, 0xCC },
	{ 0x011E, 0x00 },
	{ 0x011F, 0x00 },
	{ 0x0121, 0x02 },
	{ 0x0122, 0xCC },
	{ 0x0123, 0x00 },
	{ 0x0124, 0x00 },
	{ 0x0126, 0x02 },
	{ 0x0127, 0xCC },
	{ 0x0128, 0x00 },
	{ 0x0129, 0x00 },
	{ 0x012B, 0x02 },
	{ 0x012C, 0xCC },
	{ 0x012D, 0x00 },
	{ 0x012E, 0x00 },
	{ 0x0130, 0x02 },
	{ 0x0131, 0xCC },
	{ 0x0132, 0x00 },
	{ 0x0133, 0x00 },
	{ 0x013A, 0x02 },
	{ 0x013B, 0xCC },
	{ 0x013C, 0x00 },
	{ 0x013D, 0x00 },
	{ 0x013F, 0x00 },
	{ 0x0140, 0x00 },
	{ 0x0141, 0x40 },
	{ 0x0202, 0x00 },
	{ 0x0203, 0x00 },
	{ 0x0204, 0x00 },
	{ 0x0205, 0x00 },
	{ 0x0206, 0x00 },
	{ 0x0208, 0x01 },
	{ 0x0209, 0x00 },
	{ 0x020A, 0x00 },
	{ 0x020B, 0x00 },
	{ 0x020C, 0x00 },
	{ 0x020D, 0x00 },
	{ 0x020E, 0x01 },
	{ 0x020F, 0x00 },
	{ 0x0210, 0x00 },
	{ 0x0211, 0x00 },
	{ 0x0212, 0x00 },
	{ 0x0213, 0x00 },
	{ 0x0214, 0x00 },
	{ 0x0215, 0x00 },
	{ 0x0216, 0x00 },
	{ 0x0217, 0x00 },
	{ 0x0218, 0x00 },
	{ 0x0219, 0x00 },
	{ 0x021A, 0x00 },
	{ 0x021B, 0x00 },
	{ 0x021C, 0x00 },
	{ 0x021D, 0x00 },
	{ 0x021E, 0x00 },
	{ 0x021F, 0x00 },
	{ 0x0220, 0x00 },
	{ 0x0221, 0x00 },
	{ 0x0222, 0x00 },
	{ 0x0223, 0x00 },
	{ 0x0224, 0x00 },
	{ 0x0225, 0x00 },
	{ 0x0226, 0x00 },
	{ 0x0227, 0x00 },
	{ 0x0228, 0x00 },
	{ 0x0229, 0x00 },
	{ 0x022A, 0x00 },
	{ 0x022B, 0x00 },
	{ 0x022C, 0x00 },
	{ 0x022D, 0x00 },
	{ 0x022E, 0x00 },
	{ 0x022F, 0x00 },
	{ 0x0235, 0x00 },
	{ 0x0236, 0x00 },
	{ 0x0237, 0x00 },
	{ 0x0238, 0x00 },
	{ 0x0239, 0xB0 },
	{ 0x023A, 0x02 },
	{ 0x023B, 0x00 },
	{ 0x023C, 0x00 },
	{ 0x023D, 0x00 },
	{ 0x023E, 0x80 },
	{ 0x024A, 0x04 },
	{ 0x024B, 0x00 },
	{ 0x024C, 0x00 },
	{ 0x024D, 0x0F },
	{ 0x024E, 0x00 },
	{ 0x024F, 0x00 },
	{ 0x0250, 0x0F },
	{ 0x0251, 0x00 },
	{ 0x0252, 0x00 },
	{ 0x0253, 0x00 },
	{ 0x0254, 0x00 },
	{ 0x0255, 0x00 },
	{ 0x0256, 0x04 },
	{ 0x0257, 0x00 },
	{ 0x0258, 0x00 },
	{ 0x0259, 0x04 },
	{ 0x025A, 0x00 },
	{ 0x025B, 0x00 },
	{ 0x025C, 0x04 },
	{ 0x025D, 0x00 },
	{ 0x025E, 0x00 },
	{ 0x025F, 0xFF },
	{ 0x0260, 0x69 },
	{ 0x0261, 0x18 },
	{ 0x0262, 0xFF },
	{ 0x0263, 0x69 },
	{ 0x0264, 0x18 },
	{ 0x0268, 0x0F },
	{ 0x0269, 0x00 },
	{ 0x026A, 0x00 },
	{ 0x026B, 0x57 },
	{ 0x026C, 0x57 },
	{ 0x026D, 0x56 },
	{ 0x026E, 0x42 },
	{ 0x026F, 0x56 },
	{ 0x0270, 0x32 },
	{ 0x0271, 0x00 },
	{ 0x0272, 0x00 },
	{ 0x0302, 0x00 },
	{ 0x0303, 0x00 },
	{ 0x0304, 0x00 },
	{ 0x0305, 0x80 },
	{ 0x0306, 0x15 },
	{ 0x0307, 0x00 },
	{ 0x0308, 0x00 },
	{ 0x0309, 0x00 },
	{ 0x030A, 0x00 },
	{ 0x030B, 0x80 },
	{ 0x030C, 0x00 },
	{ 0x030D, 0x00 },
	{ 0x030E, 0x00 },
	{ 0x030F, 0x00 },
	{ 0x0310, 0x00 },
	{ 0x0311, 0x00 },
	{ 0x0312, 0x00 },
	{ 0x0313, 0x00 },
	{ 0x0314, 0x00 },
	{ 0x0315, 0x00 },
	{ 0x0316, 0x00 },
	{ 0x0317, 0x00 },
	{ 0x0318, 0x00 },
	{ 0x0319, 0x00 },
	{ 0x031A, 0x00 },
	{ 0x031B, 0x00 },
	{ 0x031C, 0x00 },
	{ 0x031D, 0x00 },
	{ 0x031E, 0x00 },
	{ 0x031F, 0x00 },
	{ 0x0320, 0x00 },
	{ 0x0321, 0x00 },
	{ 0x0322, 0x00 },
	{ 0x0323, 0x00 },
	{ 0x0324, 0x00 },
	{ 0x0325, 0x00 },
	{ 0x0326, 0x00 },
	{ 0x0327, 0x00 },
	{ 0x0328, 0x00 },
	{ 0x0329, 0x00 },
	{ 0x032A, 0x00 },
	{ 0x032B, 0x00 },
	{ 0x032C, 0x00 },
	{ 0x032D, 0x00 },
	{ 0x032E, 0x00 },
	{ 0x032F, 0x00 },
	{ 0x0330, 0x00 },
	{ 0x0331, 0x00 },
	{ 0x0332, 0x00 },
	{ 0x0333, 0x00 },
	{ 0x0334, 0x00 },
	{ 0x0335, 0x00 },
	{ 0x0336, 0x00 },
	{ 0x0337, 0x00 },
	{ 0x0338, 0x00 },
	{ 0x0339, 0x1F },
	{ 0x033B, 0x00 },
	{ 0x033C, 0x00 },
	{ 0x033D, 0x00 },
	{ 0x033E, 0x00 },
	{ 0x033F, 0x00 },
	{ 0x0340, 0x00 },
	{ 0x0341, 0x00 },
	{ 0x0342, 0x00 },
	{ 0x0343, 0x00 },
	{ 0x0344, 0x00 },
	{ 0x0345, 0x00 },
	{ 0x0346, 0x00 },
	{ 0x0347, 0x00 },
	{ 0x0348, 0x00 },
	{ 0x0349, 0x00 },
	{ 0x034A, 0x00 },
	{ 0x034B, 0x00 },
	{ 0x034C, 0x00 },
	{ 0x034D, 0x00 },
	{ 0x034E, 0x00 },
	{ 0x034F, 0x00 },
	{ 0x0350, 0x00 },
	{ 0x0351, 0x00 },
	{ 0x0352, 0x00 },
	{ 0x0353, 0x00 },
	{ 0x0354, 0x00 },
	{ 0x0355, 0x00 },
	{ 0x0356, 0x00 },
	{ 0x0357, 0x00 },
	{ 0x0358, 0x00 },
	{ 0x0359, 0x00 },
	{ 0x035A, 0x00 },
	{ 0x035B, 0x00 },
	{ 0x035C, 0x00 },
	{ 0x035D, 0x00 },
	{ 0x035E, 0x00 },
	{ 0x035F, 0x00 },
	{ 0x0360, 0x00 },
	{ 0x0361, 0x00 },
	{ 0x0362, 0x00 },
	{ 0x0802, 0x00 },
	{ 0x0803, 0x00 },
	{ 0x0804, 0x00 },
	{ 0x090E, 0x00 },
	{ 0x091C, 0x04 },
	{ 0x0943, 0x01 },
	{ 0x0949, 0x01 },
	{ 0x094A, 0x10 },
	{ 0x0A02, 0x00 },
	{ 0x0A03, 0x01 },
	{ 0x0A04, 0x01 },
	{ 0x0A05, 0x01 },
	{ 0x0B44, 0x0F },
	{ 0x0B4A, 0x1E },
	/* End configuration registers */

	/* Start configuration postamble */
	{ 0x001C, 0x01 },
	{ 0x0B24, 0xDB },
	{ 0x0B25, 0x02 },
	/* End configuration postamble */

};

/*
 * Design Report
 *
 * Overview
 * ========
 * 
 * Part:               Si5341ABCD Rev B
 * Project File:       C:\Users\yrenaym\AppData\Local\Microsoft\Windows\INetCache\Content.Outlook\M2SC4632\Si5341-RevD-WWVBV2-Project.slabtimeproj
 * Design ID:          WWVBV2
 * Created By:         ClockBuilder Pro v4.13 [2024-05-31]
 * Timestamp:          2024-06-10 09:58:15 GMT-07:00
 * 
 * Design Rule Check
 * =================
 * 
 * Errors:
 * - No errors
 * 
 * Warnings:
 * - OUT7: frequency less than 300 kHz [1]
 * - OUT8: frequency less than 300 kHz [1]
 * - Revision B is not recommended for new designs. Note you will not be able to
 *   create a Revision B custom part number (aka OPN)
 * 
 * Notes:
 * - You have selected CMOS output. Please review AN862 "Optimizing Jitter
 *   Performance in Next Generation Internet Infrastructure Systems" to ensure
 *   your configuration meets your jitter requirements
 * 
 * Footnotes:
 * [1] AC-coupled output clocks less than 300 kHz will be significantly attenuated when using 0.1 �F coupling capacitors as generally installed on Skyworks customer evaluation boards. To properly observe a clock with an output frequency <= 300 kHz, the output clock AC-coupling capacitor will need to be replaced with either a higher value capacitor or with a 0 ? resistor.
 * 
 * Device Grade
 * ============
 * Maximum Output Frequency: 32 MHz
 * Frequency Synthesis Mode: Integer
 * Frequency Plan Grade:     D
 * Minimum Base OPN:         Si5341D*
 * 
 * Base       Output Clock         Supported Frequency Synthesis Modes
 * OPN Grade  Frequency Range      (Typical Jitter)
 * ---------  -------------------  --------------------------------------------
 * Si5341A    100 Hz to 712.5 MHz  Integer (< 100 fs) and fractional (< 150 fs)
 * Si5341B    100 Hz to 350 MHz    "
 * Si5341C    100 Hz to 712.5 MHz  Integer only (< 100 fs)
 * Si5341D*   100 Hz to 350 MHz    "
 * 
 * * Based on your calculated frequency plan, a Si5341D grade device is
 * sufficient for your design. For more in-system configuration flexibility
 * (higher frequencies and/or to enable fractional synthesis), consider
 * selecting device grade Si5341A when specifying an ordering part number (OPN)
 * for your application. See the datasheet Ordering Guide for more information.
 * 
 * Design
 * ======
 * Host Interface:
 *    I/O Power Supply: VDDA (3.3V)
 *    SPI Mode: 3-Wire
 *    I2C Address Range: 116d to 119d / 0x74 to 0x77 (selected via A0/A1 pins)
 * 
 * Inputs:
 *    XAXB: Unused
 *     IN0: 10 MHz
 *          Standard
 *     IN1: Unused
 *     IN2: Unused
 *   FB_IN: Unused
 * 
 * Outputs:
 *    OUT0: 32 MHz
 *          Enabled, LVCMOS In-Phase 1.8 V 31 ?
 *    OUT1: 10 MHz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT2: 10 MHz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT3: Unused
 *    OUT4: 32 MHz
 *          Enabled, LVCMOS In-Phase 1.8 V 31 ?
 *    OUT5: 32 MHz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT6: 32 MHz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT7: 100 Hz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT8: 100 Hz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 *    OUT9: 10 MHz
 *          Enabled, LVCMOS In-Phase 3.3 V 22 ?
 * 
 * Output Enable:
 *    OUT0: OE0
 *    OUT1: OE0
 *    OUT2: OE0
 *    OUT3: OE0
 *    OUT4: OE0
 *    OUT5: OE0
 *    OUT6: OE0
 *    OUT7: OE0
 *    OUT8: OE0
 *    OUT9: OE0
 * 
 * Frequency Plan
 * ==============
 * 
 * Calculation Time: 0.19 sec (factory only)
 * Priority: maximize the number of low jitter outputs
 * 
 * Fpfd = 10 MHz
 * Fvco = 13.76 GHz
 * Fms0 = 320 MHz
 * 
 * P dividers:
 *    P0  = 1
 *    P1  = Unused
 *    P2  = Unused
 *    P3  = Unused
 *    Pxaxb = Unused
 * 
 * M = 1376
 * N dividers:
 *    N0:
 *       Value: 43
 *       Skew:  0.000 s
 *       OUT0: 32 MHz
 *       OUT1: 10 MHz
 *       OUT2: 10 MHz
 *       OUT4: 32 MHz
 *       OUT5: 32 MHz
 *       OUT6: 32 MHz
 *       OUT7: 100 Hz
 *       OUT8: 100 Hz
 *       OUT9: 10 MHz
 *    N1:
 *       Unused
 *    N2:
 *       Unused
 *    N3:
 *       Unused
 *    N4:
 *       Unused
 * 
 * R dividers:
 *    R0 = 10
 *    R1 = 32
 *    R2 = 32
 *    R3 = Unused
 *    R4 = 10
 *    R5 = 10
 *    R6 = 10
 *    R7 = 3200000
 *    R8 = 3200000
 *    R9 = 32
 * 
 * Dividers listed above show effective values. These values are translated to register settings by ClockBuilder Pro. For the actual register values, see below. Refer to the Family Reference Manual for information on registers related to frequency plan.
 * 
 * Digitally Controlled Oscillator (DCO)
 * =====================================
 * Mode: Register Direct Write
 * 
 * N0: DCO Disabled
 * 
 * N1: DCO Disabled
 * 
 * N2: DCO Disabled
 * 
 * N3: DCO Disabled
 * 
 * N4: DCO Disabled
 * 
 * Estimated Power & Junction Temperature
 * ======================================
 * Assumptions:
 * 
 * VDD:      1.8 V
 * Ta:       25 �C
 * Theta-JA: 18.30 �C/W (JEDEC Board with 2 m/s airflow)
 * 
 *                               Overall  On Chip
 * Condition                     Power    Power    Ta    Tj
 * ----------------------------  -------  -------  ----  ----
 * Typical Ta, Voltage, Current  938 mW   938 mW   25 C  42 C
 * 
 *                                   -----------------------
 *                                           Typical        
 *                                   -----------------------
 *                                   Voltage  Current  Power
 *        Output  Frequency  Format    (V)     (mA)    (mW) 
 *        ------  ---------  ------  -------  -------  -----
 * VDD                                  1.80      107    193
 * VDDA                                 3.30      113    374
 * VDDO0  OUT0       32 MHz  LVCMOS (in-phase)     1.80       14     25
 * VDDO1  OUT1       10 MHz  LVCMOS (in-phase)     3.30       14     45
 * VDDO2  OUT2       10 MHz  LVCMOS (in-phase)     3.30       14     45
 * VDDO3  OUT3       Unused        
 * VDDO4  OUT4       32 MHz  LVCMOS (in-phase)     1.80       14     25
 * VDDO5  OUT5       32 MHz  LVCMOS (in-phase)     3.30       15     49
 * VDDO6  OUT6       32 MHz  LVCMOS (in-phase)     3.30       15     49
 * VDDO7  OUT7       100 Hz  LVCMOS (in-phase)     3.30       13     43
 * VDDO8  OUT8       100 Hz  LVCMOS (in-phase)     3.30       13     43
 * VDDO9  OUT9       10 MHz  LVCMOS (in-phase)     3.30       14     45
 *                                   -------  -------  -----
 *                                      1.80      135    244
 *                                      3.30      210    694
 *                                   -------  -------  -----
 *                                     Total             938
 *                                   -------  -------  -----
 * 
 * Note:
 * 
 * - Tj is junction temperature. Tj must be less than 125 �C (on Si5341 Revision
 *   B) for device to comply with datasheet specifications. Tj = Ta +
 *   Theta_JA*On_Chip_Power.
 * - Overall power includes on-chip power dissipation and adds differential load
 *   power dissipation to estimate total power requirements.
 * - Above are estimates only: power and temperature should be measured on your
 *   PCB.
 * - Selection of appropriate Theta-JA is required for most accurate estimate.
 *   Ideally, select 'User Specified Theta-JA' and enter a Theta-JA value based
 *   on the thermal properties of your PCB.
 * 
 * OID Tone Scoring (Unlocked)
 * ===========================
 * Max Output Tone score: 0.000
 * Min Output Tone score: 0.000
 * MXAXB = 1376
 *    Score=0.000
 * N0 = 43
 *    OUT0: N Score=0.000, Full Score=0.000, 32 MHz
 *    OUT1: N Score=0.000, Full Score=0.000, 10 MHz
 *    OUT2: N Score=0.000, Full Score=0.000, 10 MHz
 *    OUT4: N Score=0.000, Full Score=0.000, 32 MHz
 *    OUT5: N Score=0.000, Full Score=0.000, 32 MHz
 *    OUT6: N Score=0.000, Full Score=0.000, 32 MHz
 *    OUT7: N Score=0.000, Full Score=0.000, 100 Hz
 *    OUT8: N Score=0.000, Full Score=0.000, 100 Hz
 *    OUT9: N Score=0.000, Full Score=0.000, 10 MHz
 * 
 * OID Tone Scoring Calculation Log (Unlocked)
 * ===========================================
 * 
 * Base Tone Scores
 * Fraction Near                 MXAXB Score  Nx Score
 * ----------------------------  -----------  --------
 * 0/1, 1/1                      2.4          2.4
 * 1/2                           2.1          2.1
 * 1/3, 2/3                      1.7          1.7
 * 1/4, 3/4                      1.4          1.4
 * 1/5, 2/5, 3/5, 4/5            1            1
 * 1/6, 5/6                      0.65         0.65
 * 1/7, 2/7, 3/7, 4/7, 5/7, 6/7  0.45         0.45
 * 1/8, 3/8, 5/8, 7/8            0.25         0.25
 * 
 * == Calculating tone for MXAXB=1376, Fpfdi=10 MHz, ilf3=1.5 MHz, dco_peak_pct=0 ppm, is_dspllb_free_run=False, mxaxb_external_input_error_pct=0 ppm, mxaxb_frac_exact_is_tone=False
 * -- Calculating tone for Freq_Into_Divider=10 MHz, Divider=1376, Divider(frac)=0, Source=Mi, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=UseBiggestTone, IBW=1.5 MHz, IBW_Multiplier=20, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT0 32 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=8 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT1 10 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=2.5 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT2 10 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=2.5 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT4 32 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=8 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT5 32 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=8 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT6 32 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=8 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT7 100 Hz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=25 Hz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT8 100 Hz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=25 Hz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * == Calculating tone for OUT9 10 MHz, N=43, Fvco=13.76 GHz, Fdco=320 MHz, dco_peak_pct=0 ppm
 * -- Calculating tone for Freq_Into_Divider=320 MHz, Divider=43, Divider(frac)=0, Source=Nx, Frac_Exact_Is_Tone=False, Multiple_Tone_Scheme=RSSAllTones, IBW=2.5 MHz, IBW_Multiplier=1, IBW_Extra_Base=0 Hz
 *    No tone because frac is exactly 0/1
 * 
 * Settings
 * ========
 * 
 * Location      Setting Name         Decimal Value      Hex Value        
 * ------------  -------------------  -----------------  -----------------
 * 0x000B[6:0]   I2C_ADDR             116                0x74             
 * 0x0017[0]     SYSINCAL_INTR_MSK    0                  0x0              
 * 0x0017[1]     LOSXAXB_INTR_MSK     0                  0x0              
 * 0x0017[2]     LOSREF_INTR_MSK      0                  0x0              
 * 0x0017[3]     LOL_INTR_MSK         0                  0x0              
 * 0x0017[5]     SMB_TMOUT_INTR_MSK   0                  0x0              
 * 0x0018[3:0]   LOSIN_INTR_MSK       14                 0xE              
 * 0x0021[0]     IN_SEL_REGCTRL       1                  0x1              
 * 0x0021[2:1]   IN_SEL               0                  0x0              
 * 0x0022[1]     OE                   0                  0x0              
 * 0x002B[3]     SPI_3WIRE            1                  0x1              
 * 0x002B[5]     AUTO_NDIV_UPDATE     0                  0x0              
 * 0x002C[3:0]   LOS_EN               1                  0x1              
 * 0x002C[4]     LOSXAXB_DIS          1                  0x1              
 * 0x002D[1:0]   LOS0_VAL_TIME        1                  0x1              
 * 0x002D[3:2]   LOS1_VAL_TIME        0                  0x0              
 * 0x002D[5:4]   LOS2_VAL_TIME        0                  0x0              
 * 0x002D[7:6]   LOS3_VAL_TIME        0                  0x0              
 * 0x002E[15:0]  LOS0_TRG_THR         177                0x00B1           
 * 0x0030[15:0]  LOS1_TRG_THR         0                  0x0000           
 * 0x0032[15:0]  LOS2_TRG_THR         0                  0x0000           
 * 0x0034[15:0]  LOS3_TRG_THR         0                  0x0000           
 * 0x0036[15:0]  LOS0_CLR_THR         177                0x00B1           
 * 0x0038[15:0]  LOS1_CLR_THR         0                  0x0000           
 * 0x003A[15:0]  LOS2_CLR_THR         0                  0x0000           
 * 0x003C[15:0]  LOS3_CLR_THR         0                  0x0000           
 * 0x0041[4:0]   LOS0_DIV_SEL         3                  0x03             
 * 0x0042[4:0]   LOS1_DIV_SEL         0                  0x00             
 * 0x0043[4:0]   LOS2_DIV_SEL         0                  0x00             
 * 0x0044[4:0]   LOS3_DIV_SEL         0                  0x00             
 * 0x009E[7:4]   LOL_SET_THR          0                  0x0              
 * 0x0102[0]     OUTALL_DISABLE_LOW   1                  0x1              
 * 0x0108[0]     OUT0_PDN             0                  0x0              
 * 0x0108[1]     OUT0_OE              1                  0x1              
 * 0x0108[2]     OUT0_RDIV_FORCE2     0                  0x0              
 * 0x0109[2:0]   OUT0_FORMAT          4                  0x4              
 * 0x0109[3]     OUT0_SYNC_EN         1                  0x1              
 * 0x0109[5:4]   OUT0_DIS_STATE       0                  0x0              
 * 0x0109[7:6]   OUT0_CMOS_DRV        3                  0x3              
 * 0x010A[3:0]   OUT0_CM              0                  0x0              
 * 0x010A[6:4]   OUT0_AMPL            0                  0x0              
 * 0x010B[2:0]   OUT0_MUX_SEL         0                  0x0              
 * 0x010B[7:6]   OUT0_INV             0                  0x0              
 * 0x010D[0]     OUT1_PDN             0                  0x0              
 * 0x010D[1]     OUT1_OE              1                  0x1              
 * 0x010D[2]     OUT1_RDIV_FORCE2     0                  0x0              
 * 0x010E[2:0]   OUT1_FORMAT          4                  0x4              
 * 0x010E[3]     OUT1_SYNC_EN         1                  0x1              
 * 0x010E[5:4]   OUT1_DIS_STATE       0                  0x0              
 * 0x010E[7:6]   OUT1_CMOS_DRV        3                  0x3              
 * 0x010F[3:0]   OUT1_CM              0                  0x0              
 * 0x010F[6:4]   OUT1_AMPL            0                  0x0              
 * 0x0110[2:0]   OUT1_MUX_SEL         0                  0x0              
 * 0x0110[7:6]   OUT1_INV             0                  0x0              
 * 0x0112[0]     OUT2_PDN             0                  0x0              
 * 0x0112[1]     OUT2_OE              1                  0x1              
 * 0x0112[2]     OUT2_RDIV_FORCE2     0                  0x0              
 * 0x0113[2:0]   OUT2_FORMAT          4                  0x4              
 * 0x0113[3]     OUT2_SYNC_EN         1                  0x1              
 * 0x0113[5:4]   OUT2_DIS_STATE       0                  0x0              
 * 0x0113[7:6]   OUT2_CMOS_DRV        3                  0x3              
 * 0x0114[3:0]   OUT2_CM              0                  0x0              
 * 0x0114[6:4]   OUT2_AMPL            0                  0x0              
 * 0x0115[2:0]   OUT2_MUX_SEL         0                  0x0              
 * 0x0115[7:6]   OUT2_INV             0                  0x0              
 * 0x0117[0]     OUT3_PDN             1                  0x1              
 * 0x0117[1]     OUT3_OE              0                  0x0              
 * 0x0117[2]     OUT3_RDIV_FORCE2     0                  0x0              
 * 0x0118[2:0]   OUT3_FORMAT          1                  0x1              
 * 0x0118[3]     OUT3_SYNC_EN         1                  0x1              
 * 0x0118[5:4]   OUT3_DIS_STATE       0                  0x0              
 * 0x0118[7:6]   OUT3_CMOS_DRV        0                  0x0              
 * 0x0119[3:0]   OUT3_CM              11                 0xB              
 * 0x0119[6:4]   OUT3_AMPL            3                  0x3              
 * 0x011A[2:0]   OUT3_MUX_SEL         0                  0x0              
 * 0x011A[7:6]   OUT3_INV             0                  0x0              
 * 0x011C[0]     OUT4_PDN             0                  0x0              
 * 0x011C[1]     OUT4_OE              1                  0x1              
 * 0x011C[2]     OUT4_RDIV_FORCE2     0                  0x0              
 * 0x011D[2:0]   OUT4_FORMAT          4                  0x4              
 * 0x011D[3]     OUT4_SYNC_EN         1                  0x1              
 * 0x011D[5:4]   OUT4_DIS_STATE       0                  0x0              
 * 0x011D[7:6]   OUT4_CMOS_DRV        3                  0x3              
 * 0x011E[3:0]   OUT4_CM              0                  0x0              
 * 0x011E[6:4]   OUT4_AMPL            0                  0x0              
 * 0x011F[2:0]   OUT4_MUX_SEL         0                  0x0              
 * 0x011F[7:6]   OUT4_INV             0                  0x0              
 * 0x0121[0]     OUT5_PDN             0                  0x0              
 * 0x0121[1]     OUT5_OE              1                  0x1              
 * 0x0121[2]     OUT5_RDIV_FORCE2     0                  0x0              
 * 0x0122[2:0]   OUT5_FORMAT          4                  0x4              
 * 0x0122[3]     OUT5_SYNC_EN         1                  0x1              
 * 0x0122[5:4]   OUT5_DIS_STATE       0                  0x0              
 * 0x0122[7:6]   OUT5_CMOS_DRV        3                  0x3              
 * 0x0123[3:0]   OUT5_CM              0                  0x0              
 * 0x0123[6:4]   OUT5_AMPL            0                  0x0              
 * 0x0124[2:0]   OUT5_MUX_SEL         0                  0x0              
 * 0x0124[7:6]   OUT5_INV             0                  0x0              
 * 0x0126[0]     OUT6_PDN             0                  0x0              
 * 0x0126[1]     OUT6_OE              1                  0x1              
 * 0x0126[2]     OUT6_RDIV_FORCE2     0                  0x0              
 * 0x0127[2:0]   OUT6_FORMAT          4                  0x4              
 * 0x0127[3]     OUT6_SYNC_EN         1                  0x1              
 * 0x0127[5:4]   OUT6_DIS_STATE       0                  0x0              
 * 0x0127[7:6]   OUT6_CMOS_DRV        3                  0x3              
 * 0x0128[3:0]   OUT6_CM              0                  0x0              
 * 0x0128[6:4]   OUT6_AMPL            0                  0x0              
 * 0x0129[2:0]   OUT6_MUX_SEL         0                  0x0              
 * 0x0129[7:6]   OUT6_INV             0                  0x0              
 * 0x012B[0]     OUT7_PDN             0                  0x0              
 * 0x012B[1]     OUT7_OE              1                  0x1              
 * 0x012B[2]     OUT7_RDIV_FORCE2     0                  0x0              
 * 0x012C[2:0]   OUT7_FORMAT          4                  0x4              
 * 0x012C[3]     OUT7_SYNC_EN         1                  0x1              
 * 0x012C[5:4]   OUT7_DIS_STATE       0                  0x0              
 * 0x012C[7:6]   OUT7_CMOS_DRV        3                  0x3              
 * 0x012D[3:0]   OUT7_CM              0                  0x0              
 * 0x012D[6:4]   OUT7_AMPL            0                  0x0              
 * 0x012E[2:0]   OUT7_MUX_SEL         0                  0x0              
 * 0x012E[7:6]   OUT7_INV             0                  0x0              
 * 0x0130[0]     OUT8_PDN             0                  0x0              
 * 0x0130[1]     OUT8_OE              1                  0x1              
 * 0x0130[2]     OUT8_RDIV_FORCE2     0                  0x0              
 * 0x0131[2:0]   OUT8_FORMAT          4                  0x4              
 * 0x0131[3]     OUT8_SYNC_EN         1                  0x1              
 * 0x0131[5:4]   OUT8_DIS_STATE       0                  0x0              
 * 0x0131[7:6]   OUT8_CMOS_DRV        3                  0x3              
 * 0x0132[3:0]   OUT8_CM              0                  0x0              
 * 0x0132[6:4]   OUT8_AMPL            0                  0x0              
 * 0x0133[2:0]   OUT8_MUX_SEL         0                  0x0              
 * 0x0133[7:6]   OUT8_INV             0                  0x0              
 * 0x013A[0]     OUT9_PDN             0                  0x0              
 * 0x013A[1]     OUT9_OE              1                  0x1              
 * 0x013A[2]     OUT9_RDIV_FORCE2     0                  0x0              
 * 0x013B[2:0]   OUT9_FORMAT          4                  0x4              
 * 0x013B[3]     OUT9_SYNC_EN         1                  0x1              
 * 0x013B[5:4]   OUT9_DIS_STATE       0                  0x0              
 * 0x013B[7:6]   OUT9_CMOS_DRV        3                  0x3              
 * 0x013C[3:0]   OUT9_CM              0                  0x0              
 * 0x013C[6:4]   OUT9_AMPL            0                  0x0              
 * 0x013D[2:0]   OUT9_MUX_SEL         0                  0x0              
 * 0x013D[7:6]   OUT9_INV             0                  0x0              
 * 0x013F[11:0]  OUTX_ALWAYS_ON       0                  0x000            
 * 0x0141[5]     OUT_DIS_LOL_MSK      0                  0x0              
 * 0x0141[7]     OUT_DIS_MSK_LOS_PFD  0                  0x0              
 * 0x0202[31:0]  XAXB_FREQ_OFFSET     0                  0x00000000       
 * 0x0206[1:0]   PXAXB                0                  0x0              
 * 0x0208[47:0]  P0                   1                  0x000000000001   
 * 0x020E[31:0]  P0_SET               1                  0x00000001       
 * 0x0212[47:0]  P1                   0                  0x000000000000   
 * 0x0218[31:0]  P1_SET               0                  0x00000000       
 * 0x021C[47:0]  P2                   0                  0x000000000000   
 * 0x0222[31:0]  P2_SET               0                  0x00000000       
 * 0x0226[47:0]  P3                   0                  0x000000000000   
 * 0x022C[31:0]  P3_SET               0                  0x00000000       
 * 0x0235[43:0]  M_NUM                2954937499648      0x2B000000000    
 * 0x023B[31:0]  M_DEN                2147483648         0x80000000       
 * 0x024A[23:0]  R0_REG               4                  0x000004         
 * 0x024D[23:0]  R1_REG               15                 0x00000F         
 * 0x0250[23:0]  R2_REG               15                 0x00000F         
 * 0x0253[23:0]  R3_REG               0                  0x000000         
 * 0x0256[23:0]  R4_REG               4                  0x000004         
 * 0x0259[23:0]  R5_REG               4                  0x000004         
 * 0x025C[23:0]  R6_REG               4                  0x000004         
 * 0x025F[23:0]  R7_REG               1599999            0x1869FF         
 * 0x0262[23:0]  R8_REG               1599999            0x1869FF         
 * 0x0268[23:0]  R9_REG               15                 0x00000F         
 * 0x026B[7:0]   DESIGN_ID0           87                 0x57             
 * 0x026C[7:0]   DESIGN_ID1           87                 0x57             
 * 0x026D[7:0]   DESIGN_ID2           86                 0x56             
 * 0x026E[7:0]   DESIGN_ID3           66                 0x42             
 * 0x026F[7:0]   DESIGN_ID4           86                 0x56             
 * 0x0270[7:0]   DESIGN_ID5           50                 0x32             
 * 0x0271[7:0]   DESIGN_ID6           0                  0x00             
 * 0x0272[7:0]   DESIGN_ID7           0                  0x00             
 * 0x0302[43:0]  N0_NUM               92341796864        0x01580000000    
 * 0x0308[31:0]  N0_DEN               2147483648         0x80000000       
 * 0x030C[0]     N0_UPDATE            0                  0x0              
 * 0x030D[43:0]  N1_NUM               0                  0x00000000000    
 * 0x0313[31:0]  N1_DEN               0                  0x00000000       
 * 0x0317[0]     N1_UPDATE            0                  0x0              
 * 0x0318[43:0]  N2_NUM               0                  0x00000000000    
 * 0x031E[31:0]  N2_DEN               0                  0x00000000       
 * 0x0322[0]     N2_UPDATE            0                  0x0              
 * 0x0323[43:0]  N3_NUM               0                  0x00000000000    
 * 0x0329[31:0]  N3_DEN               0                  0x00000000       
 * 0x032D[0]     N3_UPDATE            0                  0x0              
 * 0x032E[43:0]  N4_NUM               0                  0x00000000000    
 * 0x0334[31:0]  N4_DEN               0                  0x00000000       
 * 0x0338[0]     N4_UPDATE            0                  0x0              
 * 0x0338[1]     N_UPDATE             0                  0x0              
 * 0x0339[4:0]   N_FSTEP_MSK          31                 0x1F             
 * 0x033B[43:0]  N0_FSTEPW            0                  0x00000000000    
 * 0x0341[43:0]  N1_FSTEPW            0                  0x00000000000    
 * 0x0347[43:0]  N2_FSTEPW            0                  0x00000000000    
 * 0x034D[43:0]  N3_FSTEPW            0                  0x00000000000    
 * 0x0353[43:0]  N4_FSTEPW            0                  0x00000000000    
 * 0x0359[15:0]  N0_DELAY             0                  0x0000           
 * 0x035B[15:0]  N1_DELAY             0                  0x0000           
 * 0x035D[15:0]  N2_DELAY             0                  0x0000           
 * 0x035F[15:0]  N3_DELAY             0                  0x0000           
 * 0x0361[15:0]  N4_DELAY             0                  0x0000           
 * 0x0802[15:0]  FIXREGSA0            0                  0x0000           
 * 0x0804[7:0]   FIXREGSD0            0                  0x00             
 * 0x090E[0]     XAXB_EXTCLK_EN       0                  0x0              
 * 0x090E[1]     XAXB_PDNB            0                  0x0              
 * 0x091C[2:0]   ZDM_EN               4                  0x4              
 * 0x0943[0]     IO_VDD_SEL           1                  0x1              
 * 0x0949[3:0]   IN_EN                1                  0x1              
 * 0x0949[7:4]   IN_PULSED_CMOS_EN    0                  0x0              
 * 0x094A[7:4]   INX_TO_PFD_EN        1                  0x1              
 * 0x0A02[4:0]   N_ADD_0P5            0                  0x00             
 * 0x0A03[4:0]   N_CLK_TO_OUTX_EN     1                  0x01             
 * 0x0A04[4:0]   N_PIBYP              1                  0x01             
 * 0x0A05[4:0]   N_PDNB               1                  0x01             
 * 0x0B44[3:0]   PDIV_ENB             15                 0xF              
 * 0x0B4A[4:0]   N_CLK_DIS            30                 0x1E
 * 
 *
 */

#endif