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
P 7050 2950
F 0 "Q?" H 7350 3000 50  0000 R CNN
F 1 "NMOS" H 7450 2900 50  0000 R CNN
F 2 "" H 7250 3050 29  0000 C CNN
F 3 "" H 7050 2950 60  0000 C CNN
	1    7050 2950
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4550 3150 7650 3150
$Comp
L GND #PWR?
U 1 1 569B3E2F
P 6100 3150
F 0 "#PWR?" H 6100 2900 50  0001 C CNN
F 1 "GND" H 6100 3000 50  0000 C CNN
F 2 "" H 6100 3150 60  0000 C CNN
F 3 "" H 6100 3150 60  0000 C CNN
	1    6100 3150
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 569B3E35
P 7050 2550
F 0 "Q?" H 7350 2600 50  0000 R CNN
F 1 "PMOS" H 7450 2500 50  0000 R CNN
F 2 "" H 7250 2650 29  0000 C CNN
F 3 "" H 7050 2550 60  0000 C CNN
	1    7050 2550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	5100 2350 7100 2350
$Comp
L +12V #PWR?
U 1 1 569B3E3D
P 6100 2350
F 0 "#PWR?" H 6100 2200 50  0001 C CNN
F 1 "+12V" H 6100 2490 50  0000 C CNN
F 2 "" H 6100 2350 60  0000 C CNN
F 3 "" H 6100 2350 60  0000 C CNN
	1    6100 2350
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E43
P 5650 2550
F 0 "D?" H 5600 2630 50  0000 L CNN
F 1 "D_Schottky_Small" H 5370 2470 50  0001 L CNN
F 2 "" V 5650 2550 60  0000 C CNN
F 3 "" V 5650 2550 60  0000 C CNN
	1    5650 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	5250 2750 6000 2750
$Comp
L D_Schottky_Small D?
U 1 1 569B3E4B
P 5650 2950
F 0 "D?" H 5600 3030 50  0000 L CNN
F 1 "D_Schottky_Small" H 5370 2870 50  0001 L CNN
F 2 "" V 5650 2950 60  0000 C CNN
F 3 "" V 5650 2950 60  0000 C CNN
	1    5650 2950
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E52
P 6550 2950
F 0 "D?" H 6500 3030 50  0000 L CNN
F 1 "D_Schottky_Small" H 6270 2870 50  0001 L CNN
F 2 "" V 6550 2950 60  0000 C CNN
F 3 "" V 6550 2950 60  0000 C CNN
	1    6550 2950
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D?
U 1 1 569B3E59
P 6550 2550
F 0 "D?" H 6500 2630 50  0000 L CNN
F 1 "D_Schottky_Small" H 6270 2470 50  0001 L CNN
F 2 "" V 6550 2550 60  0000 C CNN
F 3 "" V 6550 2550 60  0000 C CNN
	1    6550 2550
	0    1    1    0   
$EndComp
Wire Wire Line
	5650 3050 5650 3150
Connection ~ 5650 3150
Wire Wire Line
	5650 2650 5650 2850
Connection ~ 5650 2750
Wire Wire Line
	5650 2450 5650 2350
Connection ~ 5650 2350
Wire Wire Line
	6200 2750 6950 2750
Wire Wire Line
	6550 2650 6550 2850
Connection ~ 6550 2750
Wire Wire Line
	6550 3050 6550 3150
Connection ~ 6550 3150
Wire Wire Line
	6550 2450 6550 2350
Connection ~ 6550 2350
Text Notes 3800 2400 0    60   ~ 0
LID MOTOR
Text GLabel 4250 2950 0    60   Input ~ 0
LID_FWD_HI
Text GLabel 7950 2700 2    60   Input ~ 0
LID_FWD_LO
Text GLabel 7950 2950 2    60   Input ~ 0
LID_REV_HI
$Comp
L CONN_01X03 P?
U 1 1 569B3E71
P 6100 2550
F 0 "P?" H 6100 2750 50  0000 C CNN
F 1 "CONN_01X03" V 6200 2550 50  0000 C CNN
F 2 "" H 6100 2550 60  0000 C CNN
F 3 "" H 6100 2550 60  0000 C CNN
	1    6100 2550
	0    -1   -1   0   
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E78
P 7750 2950
F 0 "Q?" H 8050 3000 50  0000 R CNN
F 1 "NMOS" H 8150 2900 50  0000 R CNN
F 2 "" H 7950 3050 29  0000 C CNN
F 3 "" H 7750 2950 60  0000 C CNN
	1    7750 2950
	-1   0    0    -1  
$EndComp
Connection ~ 6950 3150
Wire Wire Line
	7250 2550 7650 2550
Wire Wire Line
	7650 2350 7650 2750
$Comp
L R R?
U 1 1 569B3E82
P 7250 2350
F 0 "R?" V 7330 2350 50  0000 C CNN
F 1 "1k" V 7250 2350 50  0000 C CNN
F 2 "" V 7180 2350 30  0000 C CNN
F 3 "" H 7250 2350 30  0000 C CNN
	1    7250 2350
	0    1    1    0   
$EndComp
Connection ~ 6950 2350
Wire Wire Line
	7400 2350 7650 2350
Connection ~ 7650 2550
Wire Wire Line
	7950 2700 7250 2700
Wire Wire Line
	7250 2700 7250 2950
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E8E
P 5150 2950
F 0 "Q?" H 5450 3000 50  0000 R CNN
F 1 "NMOS" H 5550 2900 50  0000 R CNN
F 2 "" H 5350 3050 29  0000 C CNN
F 3 "" H 5150 2950 60  0000 C CNN
	1    5150 2950
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 569B3E95
P 5150 2550
F 0 "Q?" H 5450 2600 50  0000 R CNN
F 1 "PMOS" H 5550 2500 50  0000 R CNN
F 2 "" H 5350 2650 29  0000 C CNN
F 3 "" H 5150 2550 60  0000 C CNN
	1    5150 2550
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 569B3E9C
P 4450 2950
F 0 "Q?" H 4750 3000 50  0000 R CNN
F 1 "NMOS" H 4850 2900 50  0000 R CNN
F 2 "" H 4650 3050 29  0000 C CNN
F 3 "" H 4450 2950 60  0000 C CNN
	1    4450 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2550 4550 2550
Wire Wire Line
	4550 2350 4550 2750
$Comp
L R R?
U 1 1 569B3EA5
P 4950 2350
F 0 "R?" V 5030 2350 50  0000 C CNN
F 1 "1k" V 4950 2350 50  0000 C CNN
F 2 "" V 4880 2350 30  0000 C CNN
F 3 "" H 4950 2350 30  0000 C CNN
	1    4950 2350
	0    -1   1    0   
$EndComp
Wire Wire Line
	4800 2350 4550 2350
Connection ~ 4550 2550
Wire Wire Line
	4300 2700 4950 2700
Wire Wire Line
	4950 2700 4950 2950
Connection ~ 5250 2350
Connection ~ 5250 3150
Wire Wire Line
	4250 2950 4250 2950
$Comp
L K847PH U?
U 1 1 569B3EB3
P 4750 3600
F 0 "U?" H 5220 3750 60  0000 C CNN
F 1 "K847PH" H 5370 3450 60  0000 C CNN
F 2 "" H 4750 3600 60  0000 C CNN
F 3 "" H 4750 3600 60  0000 C CNN
	1    4750 3600
	1    0    0    -1  
$EndComp
$Comp
L K847PH U?
U 1 1 569B3EBA
P 6950 3600
F 0 "U?" H 7420 3750 60  0000 C CNN
F 1 "K847PH" H 7570 3450 60  0000 C CNN
F 2 "" H 6950 3600 60  0000 C CNN
F 3 "" H 6950 3600 60  0000 C CNN
	1    6950 3600
	1    0    0    -1  
$EndComp
$Comp
L K847PH U?
U 1 1 569B3EC1
P 5650 3600
F 0 "U?" H 6120 3750 60  0000 C CNN
F 1 "K847PH" H 6270 3450 60  0000 C CNN
F 2 "" H 5650 3600 60  0000 C CNN
F 3 "" H 5650 3600 60  0000 C CNN
	1    5650 3600
	1    0    0    -1  
$EndComp
$Comp
L K847PH U?
U 1 1 569B3EC8
P 6350 3600
F 0 "U?" H 6820 3750 60  0000 C CNN
F 1 "K847PH" H 6970 3450 60  0000 C CNN
F 2 "" H 6350 3600 60  0000 C CNN
F 3 "" H 6350 3600 60  0000 C CNN
	1    6350 3600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 569B3ECF
P 4600 3800
F 0 "#PWR?" H 4600 3550 50  0001 C CNN
F 1 "GND" H 4600 3650 50  0000 C CNN
F 2 "" H 4600 3800 60  0000 C CNN
F 3 "" H 4600 3800 60  0000 C CNN
	1    4600 3800
	1    0    0    -1  
$EndComp
Text GLabel 4600 3350 0    60   Input ~ 0
LID_REV_LO
Wire Wire Line
	4600 3350 4600 3400
$Comp
L GND #PWR?
U 1 1 569B3ED7
P 5000 3800
F 0 "#PWR?" H 5000 3550 50  0001 C CNN
F 1 "GND" H 5000 3650 50  0000 C CNN
F 2 "" H 5000 3800 60  0000 C CNN
F 3 "" H 5000 3800 60  0000 C CNN
	1    5000 3800
	1    0    0    -1  
$EndComp
Text GLabel 5000 3350 2    60   Input ~ 0
REV_LO
Wire Wire Line
	5000 3350 5000 3400
Text GLabel 4300 2700 0    60   Input ~ 0
REV_LO
$EndSCHEMATC
