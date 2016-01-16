EESchema Schematic File Version 2
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
LIBS:roboCooler-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
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
L Q_NMOS_DGS Q?
U 1 1 569B3E27
P 6800 4300
F 0 "Q?" H 7100 4350 50  0000 R CNN
F 1 "NMOS" H 7200 4250 50  0000 R CNN
F 2 "" H 7000 4400 29  0000 C CNN
F 3 "" H 6800 4300 60  0000 C CNN
	1    6800 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4300 4500 7400 4500
$Comp
L GND #PWR?
U 1 1 569B3E2F
P 5850 4500
F 0 "#PWR?" H 5850 4250 50  0001 C CNN
F 1 "GND" H 5850 4350 50  0000 C CNN
F 2 "" H 5850 4500 60  0000 C CNN
F 3 "" H 5850 4500 60  0000 C CNN
	1    5850 4500
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 569B3E35
P 6800 3900
F 0 "Q?" H 7100 3950 50  0000 R CNN
F 1 "PMOS" H 7200 3850 50  0000 R CNN
F 2 "" H 7000 4000 29  0000 C CNN
F 3 "" H 6800 3900 60  0000 C CNN
	1    6800 3900
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4850 3700 6850 3700
$Comp
L +12V #PWR?
U 1 1 569B3E3D
P 5850 3700
F 0 "#PWR?" H 5850 3550 50  0001 C CNN
F 1 "+12V" H 5850 3840 50  0000 C CNN
F 2 "" H 5850 3700 60  0000 C CNN
F 3 "" H 5850 3700 60  0000 C CNN
	1    5850 3700
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E43
P 5400 3900
F 0 "D?" H 5350 3980 50  0000 L CNN
F 1 "D_Schottky_Small" H 5120 3820 50  0001 L CNN
F 2 "" V 5400 3900 60  0000 C CNN
F 3 "" V 5400 3900 60  0000 C CNN
	1    5400 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	5000 4100 5750 4100
$Comp
L D_Schottky_Small D?
U 1 1 569B3E4B
P 5400 4300
F 0 "D?" H 5350 4380 50  0000 L CNN
F 1 "D_Schottky_Small" H 5120 4220 50  0001 L CNN
F 2 "" V 5400 4300 60  0000 C CNN
F 3 "" V 5400 4300 60  0000 C CNN
	1    5400 4300
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E52
P 6300 4300
F 0 "D?" H 6250 4380 50  0000 L CNN
F 1 "D_Schottky_Small" H 6020 4220 50  0001 L CNN
F 2 "" V 6300 4300 60  0000 C CNN
F 3 "" V 6300 4300 60  0000 C CNN
	1    6300 4300
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E59
P 6300 3900
F 0 "D?" H 6250 3980 50  0000 L CNN
F 1 "D_Schottky_Small" H 6020 3820 50  0001 L CNN
F 2 "" V 6300 3900 60  0000 C CNN
F 3 "" V 6300 3900 60  0000 C CNN
	1    6300 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 4400 5400 4500
Connection ~ 5400 4500
Wire Wire Line
	5400 4000 5400 4200
Connection ~ 5400 4100
Wire Wire Line
	5400 3800 5400 3700
Connection ~ 5400 3700
Wire Wire Line
	5950 4100 6700 4100
Wire Wire Line
	6300 4000 6300 4200
Connection ~ 6300 4100
Wire Wire Line
	6300 4400 6300 4500
Connection ~ 6300 4500
Wire Wire Line
	6300 3800 6300 3700
Connection ~ 6300 3700
Text Notes 3550 3750 0    60   ~ 0
LID MOTOR
Text GLabel 4000 4300 0    60   Input ~ 0
FWD_HI
Text GLabel 7700 4050 2    60   Input ~ 0
FWD_LO
Text GLabel 7700 4300 2    60   Input ~ 0
REV_HI
$Comp
L CONN_01X03 P?
U 1 1 569B3E71
P 5850 3900
F 0 "P?" H 5850 4100 50  0000 C CNN
F 1 "CONN_01X03" V 5950 3900 50  0000 C CNN
F 2 "" H 5850 3900 60  0000 C CNN
F 3 "" H 5850 3900 60  0000 C CNN
	1    5850 3900
	0    -1   -1   0   
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E78
P 7500 4300
F 0 "Q?" H 7800 4350 50  0000 R CNN
F 1 "NMOS" H 7900 4250 50  0000 R CNN
F 2 "" H 7700 4400 29  0000 C CNN
F 3 "" H 7500 4300 60  0000 C CNN
	1    7500 4300
	-1   0    0    -1  
$EndComp
Connection ~ 6700 4500
Wire Wire Line
	7000 3900 7400 3900
Wire Wire Line
	7400 3700 7400 4100
$Comp
L R R?
U 1 1 569B3E82
P 7000 3700
F 0 "R?" V 7080 3700 50  0000 C CNN
F 1 "1k" V 7000 3700 50  0000 C CNN
F 2 "" V 6930 3700 30  0000 C CNN
F 3 "" H 7000 3700 30  0000 C CNN
	1    7000 3700
	0    1    1    0   
$EndComp
Connection ~ 6700 3700
Wire Wire Line
	7150 3700 7400 3700
Connection ~ 7400 3900
Wire Wire Line
	7700 4050 7000 4050
Wire Wire Line
	7000 4050 7000 4300
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E8E
P 4900 4300
F 0 "Q?" H 5200 4350 50  0000 R CNN
F 1 "NMOS" H 5300 4250 50  0000 R CNN
F 2 "" H 5100 4400 29  0000 C CNN
F 3 "" H 4900 4300 60  0000 C CNN
	1    4900 4300
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 569B3E95
P 4900 3900
F 0 "Q?" H 5200 3950 50  0000 R CNN
F 1 "PMOS" H 5300 3850 50  0000 R CNN
F 2 "" H 5100 4000 29  0000 C CNN
F 3 "" H 4900 3900 60  0000 C CNN
	1    4900 3900
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E9C
P 4200 4300
F 0 "Q?" H 4500 4350 50  0000 R CNN
F 1 "NMOS" H 4600 4250 50  0000 R CNN
F 2 "" H 4400 4400 29  0000 C CNN
F 3 "" H 4200 4300 60  0000 C CNN
	1    4200 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 3900 4300 3900
Wire Wire Line
	4300 3700 4300 4100
$Comp
L R R?
U 1 1 569B3EA5
P 4700 3700
F 0 "R?" V 4780 3700 50  0000 C CNN
F 1 "1k" V 4700 3700 50  0000 C CNN
F 2 "" V 4630 3700 30  0000 C CNN
F 3 "" H 4700 3700 30  0000 C CNN
	1    4700 3700
	0    -1   1    0   
$EndComp
Wire Wire Line
	4550 3700 4300 3700
Connection ~ 4300 3900
Wire Wire Line
	4050 4050 4700 4050
Wire Wire Line
	4700 4050 4700 4300
Connection ~ 5000 3700
Connection ~ 5000 4500
Wire Wire Line
	4000 4300 4000 4300
$Comp
L K847PH U?
U 1 1 569B3EB3
P 5000 1900
F 0 "U?" H 5470 2050 60  0000 C CNN
F 1 "K847PH" H 5620 1750 60  0000 C CNN
F 2 "" H 5000 1900 60  0000 C CNN
F 3 "" H 5000 1900 60  0000 C CNN
	1    5000 1900
	1    0    0    -1  
$EndComp
Text GLabel 4850 1650 0    60   Input ~ 0
LID_FWD_HI
Wire Wire Line
	4850 1650 4850 1700
$Comp
L GND #PWR?
U 1 1 569B3ED7
P 5250 2100
F 0 "#PWR?" H 5250 1850 50  0001 C CNN
F 1 "GND" H 5250 1950 50  0000 C CNN
F 2 "" H 5250 2100 60  0000 C CNN
F 3 "" H 5250 2100 60  0000 C CNN
	1    5250 2100
	1    0    0    -1  
$EndComp
Text GLabel 5250 1650 2    60   Input ~ 0
FWD_HI
Wire Wire Line
	5250 1650 5250 1700
Text GLabel 4050 4050 0    60   Input ~ 0
REV_LO
Text GLabel 4850 2150 0    60   Input ~ 0
SIGNAL_GND
Text GLabel 2750 3000 0    60   Input ~ 0
POWER_GND
$Comp
L GND #PWR?
U 1 1 569B77C8
P 2750 3050
F 0 "#PWR?" H 2750 2800 50  0001 C CNN
F 1 "GND" H 2750 2900 50  0000 C CNN
F 2 "" H 2750 3050 60  0000 C CNN
F 3 "" H 2750 3050 60  0000 C CNN
	1    2750 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 3000 2750 3050
Wire Wire Line
	4850 2150 4850 2100
$Comp
L K847PH U?
U 3 1 569B8D17
P 5000 2650
F 0 "U?" H 5470 2800 60  0000 C CNN
F 1 "K847PH" H 5620 2500 60  0000 C CNN
F 2 "" H 5000 2650 60  0000 C CNN
F 3 "" H 5000 2650 60  0000 C CNN
	3    5000 2650
	1    0    0    -1  
$EndComp
Text GLabel 4850 2400 0    60   Input ~ 0
LID_REV_LO
Wire Wire Line
	4850 2400 4850 2450
$Comp
L GND #PWR?
U 1 1 569B8D1F
P 5250 2850
F 0 "#PWR?" H 5250 2600 50  0001 C CNN
F 1 "GND" H 5250 2700 50  0000 C CNN
F 2 "" H 5250 2850 60  0000 C CNN
F 3 "" H 5250 2850 60  0000 C CNN
	1    5250 2850
	1    0    0    -1  
$EndComp
Text GLabel 5250 2400 2    60   Input ~ 0
REV_LO
Wire Wire Line
	5250 2400 5250 2450
Text GLabel 4850 2900 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	4850 2900 4850 2850
$Comp
L K847PH U?
U 2 1 569B9119
P 6800 1900
F 0 "U?" H 7270 2050 60  0000 C CNN
F 1 "K847PH" H 7420 1750 60  0000 C CNN
F 2 "" H 6800 1900 60  0000 C CNN
F 3 "" H 6800 1900 60  0000 C CNN
	2    6800 1900
	1    0    0    -1  
$EndComp
Text GLabel 6650 1650 0    60   Input ~ 0
LID_REV_HI
Wire Wire Line
	6650 1650 6650 1700
$Comp
L GND #PWR?
U 1 1 569B9121
P 7050 2100
F 0 "#PWR?" H 7050 1850 50  0001 C CNN
F 1 "GND" H 7050 1950 50  0000 C CNN
F 2 "" H 7050 2100 60  0000 C CNN
F 3 "" H 7050 2100 60  0000 C CNN
	1    7050 2100
	1    0    0    -1  
$EndComp
Text GLabel 7050 1650 2    60   Input ~ 0
REV_HI
Wire Wire Line
	7050 1650 7050 1700
Text GLabel 6650 2150 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	6650 2150 6650 2100
$Comp
L K847PH U?
U 4 1 569B912B
P 6800 2650
F 0 "U?" H 7270 2800 60  0000 C CNN
F 1 "K847PH" H 7420 2500 60  0000 C CNN
F 2 "" H 6800 2650 60  0000 C CNN
F 3 "" H 6800 2650 60  0000 C CNN
	4    6800 2650
	1    0    0    -1  
$EndComp
Text GLabel 6650 2400 0    60   Input ~ 0
LID_FWD_LO
Wire Wire Line
	6650 2400 6650 2450
$Comp
L GND #PWR?
U 1 1 569B9133
P 7050 2850
F 0 "#PWR?" H 7050 2600 50  0001 C CNN
F 1 "GND" H 7050 2700 50  0000 C CNN
F 2 "" H 7050 2850 60  0000 C CNN
F 3 "" H 7050 2850 60  0000 C CNN
	1    7050 2850
	1    0    0    -1  
$EndComp
Text GLabel 7050 2400 2    60   Input ~ 0
FWD_LO
Wire Wire Line
	7050 2400 7050 2450
Text GLabel 6650 2900 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	6650 2900 6650 2850
$EndSCHEMATC
