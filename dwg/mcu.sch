EESchema Schematic File Version 2
LIBS:roboCooler-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:roboCooler
LIBS:stm32
LIBS:dc-dc
LIBS:roboCooler-cache
EELAYER 25 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L STM32F407VGTx U3
U 1 1 591CDE4B
P 5950 3700
F 0 "U3" H 1650 6525 50  0000 L BNN
F 1 "STM32F407VGTx" H 10250 6525 50  0000 R BNN
F 2 "Housings_QFP:LQFP-100_14x14mm_Pitch0.5mm" H 10250 6475 50  0001 R TNN
F 3 "" H 5950 3700 50  0001 C CNN
	1    5950 3700
	1    0    0    -1  
$EndComp
Text HLabel 1450 4600 0    60   Input ~ 0
LED_0
Text HLabel 10450 5800 2    60   Output ~ 0
LED_1
Text HLabel 10450 5700 2    60   Output ~ 0
LED_2
Text HLabel 10450 5600 2    60   Output ~ 0
LED_3
Text HLabel 10450 4400 2    60   Output ~ 0
LED_4
Text HLabel 10450 4300 2    60   Output ~ 0
LED_5
Text HLabel 10450 4200 2    60   Output ~ 0
LED_6
Text HLabel 10450 4100 2    60   Output ~ 0
LED_7
Text HLabel 10450 1400 2    60   Output ~ 0
LED_UART
Text HLabel 10450 1700 2    60   Input ~ 0
HAL_1
Text HLabel 10450 1800 2    60   Input ~ 0
HAL_2
Text HLabel 10450 5000 2    60   Output ~ 0
PUSH_1
Text HLabel 10450 5100 2    60   Output ~ 0
PUSH_2
Text HLabel 10450 3300 2    60   Input ~ 0
CS_IRQ
Text HLabel 10450 2000 2    60   Output ~ 0
CS_SCL
Text HLabel 10450 5500 2    60   BiDi ~ 0
CS_SDA
Text HLabel 10450 1500 2    60   Output ~ 0
MOTOR_FWD
Text HLabel 10450 1600 2    60   Output ~ 0
MOTOR_REV
Text HLabel 1450 3400 0    60   Output ~ 0
MOTOR_PWM
Text HLabel 10450 3800 2    60   Output ~ 0
FAN_PWM
Text HLabel 10450 3400 2    60   Output ~ 0
PUMP_PWM
$Comp
L C_Small C21
U 1 1 591EE19D
P 1400 8300
F 0 "C21" H 1410 8370 50  0000 L CNN
F 1 "0.1uF" H 1410 8220 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1400 8300 50  0001 C CNN
F 3 "" H 1400 8300 50  0001 C CNN
	1    1400 8300
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR057
U 1 1 591EE235
P 1400 8650
F 0 "#PWR057" H 1400 8400 50  0001 C CNN
F 1 "GND" H 1400 8500 50  0000 C CNN
F 2 "" H 1400 8650 50  0001 C CNN
F 3 "" H 1400 8650 50  0001 C CNN
	1    1400 8650
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW1
U 1 1 591EE4D9
P 1200 8350
F 0 "SW1" H 1350 8460 50  0000 C CNN
F 1 "TL3342" H 1200 8270 50  0001 C CNN
F 2 "Buttons_Switches_SMD:SW_SPST_TL3342" H 1200 8350 50  0001 C CNN
F 3 "http://spec_sheets.e-switch.com/specs/P010632.pdf" H 1200 8350 50  0001 C CNN
	1    1200 8350
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R19
U 1 1 591DA663
P 1700 8500
F 0 "R19" H 1730 8520 50  0000 L CNN
F 1 "10k" H 1730 8460 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 1700 8500 50  0001 C CNN
F 3 "" H 1700 8500 50  0001 C CNN
	1    1700 8500
	1    0    0    -1  
$EndComp
$Comp
L R_Small R18
U 1 1 591DA9AB
P 1600 8500
F 0 "R18" H 1630 8520 50  0000 L CNN
F 1 "10k" H 1630 8460 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 1600 8500 50  0001 C CNN
F 3 "" H 1600 8500 50  0001 C CNN
	1    1600 8500
	-1   0    0    -1  
$EndComp
Text GLabel 1450 1200 0    60   Input ~ 0
NRST
Text GLabel 1450 1400 0    60   Input ~ 0
BOOT0
Text GLabel 1750 8050 2    60   Output ~ 0
NRST
Text GLabel 1750 8200 2    60   Input ~ 0
BOOT0
$Comp
L VDD #PWR058
U 1 1 591DB64B
P 5650 700
F 0 "#PWR058" H 5650 550 50  0001 C CNN
F 1 "VDD" H 5650 850 50  0000 C CNN
F 2 "" H 5650 700 50  0001 C CNN
F 3 "" H 5650 700 50  0001 C CNN
	1    5650 700 
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR059
U 1 1 591E1DAF
P 1150 9700
F 0 "#PWR059" H 1150 9550 50  0001 C CNN
F 1 "VDD" H 1150 9850 50  0000 C CNN
F 2 "" H 1150 9700 50  0001 C CNN
F 3 "" H 1150 9700 50  0001 C CNN
	1    1150 9700
	1    0    0    -1  
$EndComp
$Comp
L C_Small C19
U 1 1 591E1F8B
P 1150 9850
F 0 "C19" H 1160 9920 50  0000 L CNN
F 1 "10uF" H 1160 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1150 9850 50  0001 C CNN
F 3 "" H 1150 9850 50  0001 C CNN
	1    1150 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C22
U 1 1 591E1FCB
P 1400 9850
F 0 "C22" H 1410 9920 50  0000 L CNN
F 1 "0.1uF" H 1410 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1400 9850 50  0001 C CNN
F 3 "" H 1400 9850 50  0001 C CNN
	1    1400 9850
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR060
U 1 1 591E4031
P 1150 10000
F 0 "#PWR060" H 1150 9750 50  0001 C CNN
F 1 "GND" H 1150 9850 50  0000 C CNN
F 2 "" H 1150 10000 50  0001 C CNN
F 3 "" H 1150 10000 50  0001 C CNN
	1    1150 10000
	1    0    0    -1  
$EndComp
$Comp
L C_Small C23
U 1 1 591E4275
P 1650 9850
F 0 "C23" H 1660 9920 50  0000 L CNN
F 1 "0.1uF" H 1660 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1650 9850 50  0001 C CNN
F 3 "" H 1650 9850 50  0001 C CNN
	1    1650 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C24
U 1 1 591E42AF
P 1900 9850
F 0 "C24" H 1910 9920 50  0000 L CNN
F 1 "0.1uF" H 1910 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1900 9850 50  0001 C CNN
F 3 "" H 1900 9850 50  0001 C CNN
	1    1900 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C25
U 1 1 591E42B7
P 2150 9850
F 0 "C25" H 2160 9920 50  0000 L CNN
F 1 "0.1uF" H 2160 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2150 9850 50  0001 C CNN
F 3 "" H 2150 9850 50  0001 C CNN
	1    2150 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C26
U 1 1 591E4355
P 2400 9850
F 0 "C26" H 2410 9920 50  0000 L CNN
F 1 "0.1uF" H 2410 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2400 9850 50  0001 C CNN
F 3 "" H 2400 9850 50  0001 C CNN
	1    2400 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C27
U 1 1 591E435D
P 2650 9850
F 0 "C27" H 2660 9920 50  0000 L CNN
F 1 "0.1uF" H 2660 9770 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 2650 9850 50  0001 C CNN
F 3 "" H 2650 9850 50  0001 C CNN
	1    2650 9850
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C17
U 1 1 591E5255
P 700 1700
F 0 "C17" H 710 1770 50  0000 L CNN
F 1 "0.1uF" H 710 1620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 700 1700 50  0001 C CNN
F 3 "" H 700 1700 50  0001 C CNN
	1    700  1700
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR061
U 1 1 591E547E
P 700 1800
F 0 "#PWR061" H 700 1550 50  0001 C CNN
F 1 "GND" H 700 1650 50  0000 C CNN
F 2 "" H 700 1800 50  0001 C CNN
F 3 "" H 700 1800 50  0001 C CNN
	1    700  1800
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR062
U 1 1 591E5827
P 700 1600
F 0 "#PWR062" H 700 1450 50  0001 C CNN
F 1 "VDD" H 700 1750 50  0000 C CNN
F 2 "" H 700 1600 50  0001 C CNN
F 3 "" H 700 1600 50  0001 C CNN
	1    700  1600
	1    0    0    -1  
$EndComp
$Comp
L VDDA #PWR063
U 1 1 591E60AA
P 6250 700
F 0 "#PWR063" H 6250 550 50  0001 C CNN
F 1 "VDDA" H 6250 850 50  0000 C CNN
F 2 "" H 6250 700 50  0001 C CNN
F 3 "" H 6250 700 50  0001 C CNN
	1    6250 700 
	1    0    0    -1  
$EndComp
$Comp
L VDDA #PWR064
U 1 1 591E60E3
P 5350 8550
F 0 "#PWR064" H 5350 8400 50  0001 C CNN
F 1 "VDDA" H 5350 8700 50  0000 C CNN
F 2 "" H 5350 8550 50  0001 C CNN
F 3 "" H 5350 8550 50  0001 C CNN
	1    5350 8550
	1    0    0    -1  
$EndComp
$Comp
L C_Small C29
U 1 1 591E6469
P 5350 8700
F 0 "C29" H 5360 8770 50  0000 L CNN
F 1 "1uF" H 5360 8620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5350 8700 50  0001 C CNN
F 3 "" H 5350 8700 50  0001 C CNN
	1    5350 8700
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C31
U 1 1 591E64B1
P 5600 8700
F 0 "C31" H 5610 8770 50  0000 L CNN
F 1 "0.1uF" H 5610 8620 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5600 8700 50  0001 C CNN
F 3 "" H 5600 8700 50  0001 C CNN
	1    5600 8700
	-1   0    0    -1  
$EndComp
$Comp
L GND #PWR065
U 1 1 591E65D4
P 5350 8900
F 0 "#PWR065" H 5350 8650 50  0001 C CNN
F 1 "GND" H 5350 8750 50  0000 C CNN
F 2 "" H 5350 8900 50  0001 C CNN
F 3 "" H 5350 8900 50  0001 C CNN
	1    5350 8900
	1    0    0    -1  
$EndComp
Text GLabel 1450 1700 0    60   Input ~ 0
VREF+
Text GLabel 5700 8600 2    60   Input ~ 0
VREF+
$Comp
L GND #PWR066
U 1 1 591E7CD6
P 5950 6650
F 0 "#PWR066" H 5950 6400 50  0001 C CNN
F 1 "GND" H 5950 6500 50  0000 C CNN
F 2 "" H 5950 6650 50  0001 C CNN
F 3 "" H 5950 6650 50  0001 C CNN
	1    5950 6650
	1    0    0    -1  
$EndComp
$Comp
L C_Small C18
U 1 1 591E8372
P 3350 8400
F 0 "C18" H 3360 8470 50  0000 L CNN
F 1 "2.2uF" H 3360 8320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3350 8400 50  0001 C CNN
F 3 "" H 3350 8400 50  0001 C CNN
	1    3350 8400
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C20
U 1 1 591E843A
P 3550 8400
F 0 "C20" H 3560 8470 50  0000 L CNN
F 1 "2.2uF" H 3560 8320 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 3550 8400 50  0001 C CNN
F 3 "" H 3550 8400 50  0001 C CNN
	1    3550 8400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR067
U 1 1 591E8ABB
P 3450 8550
F 0 "#PWR067" H 3450 8300 50  0001 C CNN
F 1 "GND" H 3450 8400 50  0000 C CNN
F 2 "" H 3450 8550 50  0001 C CNN
F 3 "" H 3450 8550 50  0001 C CNN
	1    3450 8550
	1    0    0    -1  
$EndComp
Text GLabel 10450 3100 2    60   Input ~ 0
BOOT1
Text GLabel 1750 8350 2    60   Input ~ 0
BOOT1
Text GLabel 10450 2600 2    60   Input ~ 0
JTCK/SWCLK
Text GLabel 10450 2500 2    60   BiDi ~ 0
JTMS/SWDIO
Text GLabel 10450 2700 2    60   Input ~ 0
JTDI
Text GLabel 10450 3200 2    60   Input ~ 0
JTDO/SWO
$Comp
L R_Small R21
U 1 1 591F3C97
P 8950 8300
F 0 "R21" H 8980 8320 50  0000 L CNN
F 1 "10k" H 8980 8260 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 8950 8300 50  0001 C CNN
F 3 "" H 8950 8300 50  0001 C CNN
	1    8950 8300
	1    0    0    1   
$EndComp
$Comp
L Crystal_Small Y1
U 1 1 5920B24C
P 5200 9650
F 0 "Y1" H 5200 9750 50  0000 C CNN
F 1 "8MHz" H 5200 9550 50  0000 C CNN
F 2 "Crystals:Crystal_SMD_Abracon_ABM3-2pin_5.0x3.2mm_HandSoldering" H 5200 9650 50  0001 C CNN
F 3 "https://www.digikey.com/product-detail/en/abracon-llc/ABM3-8.000MHZ-D2Y-T/535-10630-1-ND/2344632" H 5200 9650 50  0001 C CNN
F 4 "ABM3-8.000MHZ-D2Y-T" H 5200 9650 60  0001 C CNN "Part Number"
	1    5200 9650
	1    0    0    -1  
$EndComp
$Comp
L C_Small C28
U 1 1 5920B768
P 5000 9750
F 0 "C28" H 5010 9820 50  0000 L CNN
F 1 "20pF" H 5010 9670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5000 9750 50  0001 C CNN
F 3 "" H 5000 9750 50  0001 C CNN
	1    5000 9750
	-1   0    0    -1  
$EndComp
$Comp
L C_Small C30
U 1 1 5920B7DD
P 5400 9750
F 0 "C30" H 5410 9820 50  0000 L CNN
F 1 "20pF" H 5410 9670 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5400 9750 50  0001 C CNN
F 3 "" H 5400 9750 50  0001 C CNN
	1    5400 9750
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR068
U 1 1 5920CBAA
P 5200 9850
F 0 "#PWR068" H 5200 9600 50  0001 C CNN
F 1 "GND" H 5200 9700 50  0000 C CNN
F 2 "" H 5200 9850 50  0001 C CNN
F 3 "" H 5200 9850 50  0001 C CNN
	1    5200 9850
	1    0    0    -1  
$EndComp
Text GLabel 5450 9300 2    60   Input ~ 0
OSC_OUT
Text GLabel 4950 9550 0    60   Output ~ 0
OSC_IN
Text GLabel 1450 2700 0    60   Output ~ 0
OSC_OUT
Text GLabel 1450 2600 0    60   Input ~ 0
OSC_IN
$Comp
L R_Small R20
U 1 1 5920FA4A
P 5400 9450
F 0 "R20" H 5430 9470 50  0000 L CNN
F 1 "300" H 5430 9410 50  0000 L CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" H 5400 9450 50  0001 C CNN
F 3 "" H 5400 9450 50  0001 C CNN
	1    5400 9450
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X05 J13
U 1 1 5922E662
P 8500 8100
F 0 "J13" H 8500 8400 50  0000 C CNN
F 1 "3221-10-0100-00" H 8500 7800 50  0000 C CNN
F 2 "roboCooler:Header_02x05_50mil" H 8500 6900 50  0001 C CNN
F 3 "http://cnctech.us/pdfs/3221-XX-0100-00.pdf" H 8500 6900 50  0001 C CNN
	1    8500 8100
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1200 8050 1750 8050
Connection ~ 1400 8050
Wire Wire Line
	1400 8200 1400 8050
Wire Wire Line
	1400 8400 1400 8650
Wire Wire Line
	1200 8650 1700 8650
Connection ~ 1400 8650
Wire Wire Line
	1600 8200 1600 8400
Wire Wire Line
	1600 8650 1600 8600
Wire Wire Line
	5650 700  6150 700 
Connection ~ 6050 700 
Connection ~ 5950 700 
Connection ~ 5850 700 
Connection ~ 5750 700 
Wire Wire Line
	1150 10000 2650 10000
Wire Wire Line
	1150 10000 1150 9950
Wire Wire Line
	1400 10000 1400 9950
Wire Wire Line
	1650 10000 1650 9950
Wire Wire Line
	1900 10000 1900 9950
Wire Wire Line
	2150 10000 2150 9950
Wire Wire Line
	2400 10000 2400 9950
Wire Wire Line
	2650 10000 2650 9950
Connection ~ 1650 9700
Connection ~ 1400 9700
Wire Wire Line
	1400 10000 1650 10000
Connection ~ 1650 10000
Connection ~ 1400 10000
Connection ~ 1900 10000
Connection ~ 2150 10000
Connection ~ 2400 10000
Wire Wire Line
	1400 9750 1400 9700
Wire Wire Line
	1650 9700 1650 9750
Wire Wire Line
	1150 9750 1150 9700
Wire Wire Line
	1900 9700 1900 9750
Wire Wire Line
	2150 9700 2150 9750
Connection ~ 2150 9700
Wire Wire Line
	2400 9700 2400 9750
Connection ~ 2400 9700
Wire Wire Line
	2650 9700 2650 9750
Connection ~ 1900 9700
Wire Wire Line
	1150 9700 2650 9700
Wire Wire Line
	1450 1600 700  1600
Wire Wire Line
	5350 8550 5350 8600
Wire Wire Line
	5350 8600 5700 8600
Wire Wire Line
	5350 8800 5350 8900
Wire Wire Line
	5350 8850 5600 8850
Wire Wire Line
	5600 8850 5600 8800
Connection ~ 5350 8850
Connection ~ 5600 8600
Connection ~ 5850 6600
Connection ~ 5950 6600
Connection ~ 6050 6600
Wire Wire Line
	5950 6600 5950 6650
Wire Wire Line
	5750 6600 6150 6600
Wire Wire Line
	3350 8500 3550 8500
Wire Wire Line
	3450 8550 3450 8500
Connection ~ 3450 8500
Wire Wire Line
	1600 8200 1750 8200
Wire Wire Line
	1700 8650 1700 8600
Wire Wire Line
	1750 8350 1700 8350
Wire Wire Line
	1700 8350 1700 8400
Connection ~ 1600 8650
Wire Wire Line
	5400 9650 5300 9650
Wire Wire Line
	5100 9650 5000 9650
Wire Wire Line
	5400 9850 5000 9850
Wire Wire Line
	5000 9650 5000 9550
Wire Wire Line
	5000 9550 4950 9550
Wire Wire Line
	5400 9650 5400 9550
Wire Wire Line
	5450 9300 5400 9300
Wire Wire Line
	5400 9300 5400 9350
Text GLabel 8250 7900 0    60   BiDi ~ 0
JTMS/SWDIO
Text GLabel 8250 8000 0    60   Output ~ 0
JTCK/SWCLK
Text GLabel 8250 8100 0    60   Input ~ 0
JTDO/SWO
Text GLabel 8250 8200 0    60   Output ~ 0
JTDI
Text GLabel 8250 8300 0    60   Output ~ 0
NRST
Wire Wire Line
	8950 8200 8750 8200
$Comp
L GND #PWR069
U 1 1 592312DC
P 8850 8450
F 0 "#PWR069" H 8850 8200 50  0001 C CNN
F 1 "GND" H 8850 8300 50  0000 C CNN
F 2 "" H 8850 8450 50  0001 C CNN
F 3 "" H 8850 8450 50  0001 C CNN
	1    8850 8450
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR070
U 1 1 59231779
P 8750 7900
F 0 "#PWR070" H 8750 7750 50  0001 C CNN
F 1 "VCC" H 8750 8050 50  0000 C CNN
F 2 "" H 8750 7900 50  0001 C CNN
F 3 "" H 8750 7900 50  0001 C CNN
	1    8750 7900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 8000 8850 8450
Wire Wire Line
	8850 8100 8750 8100
Wire Wire Line
	8950 8450 8950 8400
Connection ~ 8850 8450
Wire Wire Line
	8750 8300 8850 8300
Connection ~ 8850 8300
Wire Wire Line
	8850 8450 8950 8450
Wire Wire Line
	8750 8000 8850 8000
Connection ~ 8850 8100
NoConn ~ 1450 6100
NoConn ~ 1450 6000
NoConn ~ 1450 5900
NoConn ~ 1450 5800
NoConn ~ 1450 5700
NoConn ~ 1450 5600
NoConn ~ 1450 5300
NoConn ~ 1450 5400
NoConn ~ 1450 5500
NoConn ~ 1450 5100
NoConn ~ 1450 5000
NoConn ~ 1450 5200
NoConn ~ 1450 4900
NoConn ~ 1450 4400
NoConn ~ 1450 4300
NoConn ~ 1450 4200
NoConn ~ 1450 4100
NoConn ~ 1450 4000
NoConn ~ 1450 3900
NoConn ~ 1450 2900
NoConn ~ 1450 3000
NoConn ~ 1450 3100
NoConn ~ 1450 3200
NoConn ~ 1450 3700
NoConn ~ 10450 2100
NoConn ~ 10450 2200
NoConn ~ 10450 2300
NoConn ~ 10450 2400
NoConn ~ 10450 3900
NoConn ~ 10450 4000
NoConn ~ 10450 4600
NoConn ~ 10450 4800
NoConn ~ 10450 4900
NoConn ~ 10450 5300
NoConn ~ 10450 5400
NoConn ~ 10450 6000
NoConn ~ 10450 6100
NoConn ~ 10450 2900
NoConn ~ 10450 3500
$Comp
L VCC #PWR071
U 1 1 592E53BB
P 7900 7250
F 0 "#PWR071" H 7900 7100 50  0001 C CNN
F 1 "VCC" H 7900 7400 50  0000 C CNN
F 2 "" H 7900 7250 50  0001 C CNN
F 3 "" H 7900 7250 50  0001 C CNN
	1    7900 7250
	1    0    0    -1  
$EndComp
$Comp
L VDD #PWR072
U 1 1 592E5592
P 8100 7250
F 0 "#PWR072" H 8100 7100 50  0001 C CNN
F 1 "VDD" H 8100 7400 50  0000 C CNN
F 2 "" H 8100 7250 50  0001 C CNN
F 3 "" H 8100 7250 50  0001 C CNN
	1    8100 7250
	1    0    0    -1  
$EndComp
$Comp
L VDDA #PWR073
U 1 1 592E663C
P 7650 7500
F 0 "#PWR073" H 7650 7350 50  0001 C CNN
F 1 "VDDA" H 7650 7650 50  0000 C CNN
F 2 "" H 7650 7500 50  0001 C CNN
F 3 "" H 7650 7500 50  0001 C CNN
	1    7650 7500
	1    0    0    -1  
$EndComp
Text GLabel 1450 1800 0    60   Output ~ 0
VCAP_1
Text GLabel 1450 1900 0    60   Output ~ 0
VCAP_2
Wire Wire Line
	3350 7950 3350 8300
Wire Wire Line
	3350 8150 3200 8150
Wire Wire Line
	3200 8050 3750 8050
Wire Wire Line
	3550 8050 3550 8300
Text GLabel 3200 8050 0    60   Input ~ 0
VCAP_1
Text GLabel 3200 8150 0    60   Input ~ 0
VCAP_2
$Comp
L PWR_FLAG #FLG075
U 1 1 592E943D
P 3350 7950
F 0 "#FLG075" H 3350 8025 50  0001 C CNN
F 1 "PWR_FLAG" H 3350 8100 50  0000 C CNN
F 2 "" H 3350 7950 50  0001 C CNN
F 3 "" H 3350 7950 50  0001 C CNN
	1    3350 7950
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG076
U 1 1 592E98C6
P 3750 7950
F 0 "#FLG076" H 3750 8025 50  0001 C CNN
F 1 "PWR_FLAG" H 3750 8100 50  0000 C CNN
F 2 "" H 3750 7950 50  0001 C CNN
F 3 "" H 3750 7950 50  0001 C CNN
	1    3750 7950
	1    0    0    -1  
$EndComp
Connection ~ 3350 8150
Wire Wire Line
	3750 8050 3750 7950
Connection ~ 3550 8050
NoConn ~ 10450 1900
$Comp
L +3.3V #PWR077
U 1 1 5934B114
P 7650 7250
F 0 "#PWR077" H 7650 7100 50  0001 C CNN
F 1 "+3.3V" H 7650 7390 50  0000 C CNN
F 2 "" H 7650 7250 50  0001 C CNN
F 3 "" H 7650 7250 50  0001 C CNN
	1    7650 7250
	1    0    0    -1  
$EndComp
Connection ~ 7900 7250
Connection ~ 5200 9850
NoConn ~ 1450 3300
NoConn ~ 1450 3500
NoConn ~ 1450 3600
NoConn ~ 1450 3800
NoConn ~ 1450 4800
NoConn ~ 1450 4700
NoConn ~ 10450 5900
NoConn ~ 10450 5200
NoConn ~ 10450 4700
NoConn ~ 10450 3700
NoConn ~ 10450 3600
NoConn ~ 10450 3000
NoConn ~ 10450 1300
NoConn ~ 10450 1200
Wire Wire Line
	7650 7250 8100 7250
$Comp
L PWR_FLAG #FLG074
U 1 1 592E6772
P 8100 7500
F 0 "#FLG074" H 8100 7575 50  0001 C CNN
F 1 "PWR_FLAG" H 8100 7650 50  0000 C CNN
F 2 "" H 8100 7500 50  0001 C CNN
F 3 "" H 8100 7500 50  0001 C CNN
	1    8100 7500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 7500 7650 7500
$EndSCHEMATC
