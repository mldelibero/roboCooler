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
L Q_NMOS_DGS Q7
U 1 1 569B3E27
P 6900 5250
F 0 "Q7" H 7200 5300 50  0000 R CNN
F 1 "NMOS" H 7300 5200 50  0000 R CNN
F 2 "" H 7100 5350 29  0000 C CNN
F 3 "" H 6900 5250 60  0000 C CNN
	1    6900 5250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4400 5450 5100 5450
Wire Wire Line
	5100 5450 5500 5450
Wire Wire Line
	5500 5450 6400 5450
Wire Wire Line
	6400 5450 6800 5450
Wire Wire Line
	6800 5450 7500 5450
$Comp
L GND #PWR39
U 1 1 569B3E2F
P 5950 5450
F 0 "#PWR39" H 5950 5200 50  0001 C CNN
F 1 "GND" H 5950 5300 50  0000 C CNN
F 2 "" H 5950 5450 60  0000 C CNN
F 3 "" H 5950 5450 60  0000 C CNN
	1    5950 5450
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q6
U 1 1 569B3E35
P 6900 4850
F 0 "Q6" H 7200 4900 50  0000 R CNN
F 1 "PMOS" H 7300 4800 50  0000 R CNN
F 2 "" H 7100 4950 29  0000 C CNN
F 3 "" H 6900 4850 60  0000 C CNN
	1    6900 4850
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4950 4650 5100 4650
Wire Wire Line
	5100 4650 5500 4650
Wire Wire Line
	5500 4650 6400 4650
Wire Wire Line
	6400 4650 6800 4650
Wire Wire Line
	6800 4650 6950 4650
$Comp
L +12V #PWR38
U 1 1 569B3E3D
P 5950 4650
F 0 "#PWR38" H 5950 4500 50  0001 C CNN
F 1 "+12V" H 5950 4790 50  0000 C CNN
F 2 "" H 5950 4650 60  0000 C CNN
F 3 "" H 5950 4650 60  0000 C CNN
	1    5950 4650
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D3
U 1 1 569B3E43
P 5500 4850
F 0 "D3" H 5450 4930 50  0000 L CNN
F 1 "D_Schottky_Small" H 5220 4770 50  0001 L CNN
F 2 "" V 5500 4850 60  0000 C CNN
F 3 "" V 5500 4850 60  0000 C CNN
	1    5500 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	5100 5050 5500 5050
Wire Wire Line
	5500 5050 5850 5050
$Comp
L D_Schottky_Small D4
U 1 1 569B3E4B
P 5500 5250
F 0 "D4" H 5450 5330 50  0000 L CNN
F 1 "D_Schottky_Small" H 5220 5170 50  0001 L CNN
F 2 "" V 5500 5250 60  0000 C CNN
F 3 "" V 5500 5250 60  0000 C CNN
	1    5500 5250
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D6
U 1 1 569B3E52
P 6400 5250
F 0 "D6" H 6350 5330 50  0000 L CNN
F 1 "D_Schottky_Small" H 6120 5170 50  0001 L CNN
F 2 "" V 6400 5250 60  0000 C CNN
F 3 "" V 6400 5250 60  0000 C CNN
	1    6400 5250
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D5
U 1 1 569B3E59
P 6400 4850
F 0 "D5" H 6350 4930 50  0000 L CNN
F 1 "D_Schottky_Small" H 6120 4770 50  0001 L CNN
F 2 "" V 6400 4850 60  0000 C CNN
F 3 "" V 6400 4850 60  0000 C CNN
	1    6400 4850
	0    1    1    0   
$EndComp
Wire Wire Line
	5500 5350 5500 5450
Connection ~ 5500 5450
Wire Wire Line
	5500 4950 5500 5050
Wire Wire Line
	5500 5050 5500 5150
Connection ~ 5500 5050
Wire Wire Line
	5500 4750 5500 4650
Connection ~ 5500 4650
Wire Wire Line
	6050 5050 6400 5050
Wire Wire Line
	6400 5050 6800 5050
Wire Wire Line
	6400 4950 6400 5050
Wire Wire Line
	6400 5050 6400 5150
Connection ~ 6400 5050
Wire Wire Line
	6400 5350 6400 5450
Connection ~ 6400 5450
Wire Wire Line
	6400 4750 6400 4650
Connection ~ 6400 4650
Text Notes 3650 4700 0    60   ~ 0
LID MOTOR
Text GLabel 4100 5250 0    60   Input ~ 0
FWD_HI
Text GLabel 7800 5000 2    60   Input ~ 0
FWD_LO
Text GLabel 7800 5250 2    60   Input ~ 0
REV_HI
$Comp
L CONN_01X03 P11
U 1 1 569B3E71
P 5950 4850
F 0 "P11" H 5950 5050 50  0000 C CNN
F 1 "CONN_01X03" V 6050 4850 50  0000 C CNN
F 2 "" H 5950 4850 60  0000 C CNN
F 3 "" H 5950 4850 60  0000 C CNN
	1    5950 4850
	0    -1   -1   0   
$EndComp
$Comp
L Q_NMOS_DGS Q8
U 1 1 569B3E78
P 7600 5250
F 0 "Q8" H 7900 5300 50  0000 R CNN
F 1 "NMOS" H 8000 5200 50  0000 R CNN
F 2 "" H 7800 5350 29  0000 C CNN
F 3 "" H 7600 5250 60  0000 C CNN
	1    7600 5250
	-1   0    0    -1  
$EndComp
Connection ~ 6800 5450
Wire Wire Line
	7100 4850 7500 4850
Wire Wire Line
	7500 4650 7500 4850
Wire Wire Line
	7500 4850 7500 5050
$Comp
L R R3
U 1 1 569B3E82
P 7100 4650
F 0 "R3" V 7180 4650 50  0000 C CNN
F 1 "1k" V 7100 4650 50  0000 C CNN
F 2 "" V 7030 4650 30  0000 C CNN
F 3 "" H 7100 4650 30  0000 C CNN
	1    7100 4650
	0    1    1    0   
$EndComp
Connection ~ 6800 4650
Wire Wire Line
	7250 4650 7500 4650
Connection ~ 7500 4850
Wire Wire Line
	7800 5000 7100 5000
Wire Wire Line
	7100 5000 7100 5250
$Comp
L Q_NMOS_DGS Q5
U 1 1 569B3E8E
P 5000 5250
F 0 "Q5" H 5300 5300 50  0000 R CNN
F 1 "NMOS" H 5400 5200 50  0000 R CNN
F 2 "" H 5200 5350 29  0000 C CNN
F 3 "" H 5000 5250 60  0000 C CNN
	1    5000 5250
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q2
U 1 1 569B3E95
P 5000 4850
F 0 "Q2" H 5300 4900 50  0000 R CNN
F 1 "PMOS" H 5400 4800 50  0000 R CNN
F 2 "" H 5200 4950 29  0000 C CNN
F 3 "" H 5000 4850 60  0000 C CNN
	1    5000 4850
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q1
U 1 1 569B3E9C
P 4300 5250
F 0 "Q1" H 4600 5300 50  0000 R CNN
F 1 "NMOS" H 4700 5200 50  0000 R CNN
F 2 "" H 4500 5350 29  0000 C CNN
F 3 "" H 4300 5250 60  0000 C CNN
	1    4300 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 4850 4400 4850
Wire Wire Line
	4400 4650 4400 4850
Wire Wire Line
	4400 4850 4400 5050
$Comp
L R R2
U 1 1 569B3EA5
P 4800 4650
F 0 "R2" V 4880 4650 50  0000 C CNN
F 1 "1k" V 4800 4650 50  0000 C CNN
F 2 "" V 4730 4650 30  0000 C CNN
F 3 "" H 4800 4650 30  0000 C CNN
	1    4800 4650
	0    -1   1    0   
$EndComp
Wire Wire Line
	4650 4650 4400 4650
Connection ~ 4400 4850
Wire Wire Line
	4150 5000 4800 5000
Wire Wire Line
	4800 5000 4800 5250
Connection ~ 5100 4650
Connection ~ 5100 5450
Wire Wire Line
	4100 5250 4100 5250
Text GLabel 5450 2200 2    60   Input ~ 0
FWD_HI
Text GLabel 4150 5000 0    60   Input ~ 0
REV_LO
Text GLabel 3650 2450 0    60   Input ~ 0
POWER_GND
$Comp
L GND #PWR33
U 1 1 569B77C8
P 3650 2500
F 0 "#PWR33" H 3650 2250 50  0001 C CNN
F 1 "GND" H 3650 2350 50  0000 C CNN
F 2 "" H 3650 2500 60  0000 C CNN
F 3 "" H 3650 2500 60  0000 C CNN
	1    3650 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 2450 3650 2500
$Comp
L K847PH U2
U 2 1 569B8D17
P 5100 3400
F 0 "U2" H 5570 3550 60  0000 C CNN
F 1 "K847PH" H 5720 3250 60  0000 C CNN
F 2 "" H 5100 3400 60  0000 C CNN
F 3 "" H 5100 3400 60  0000 C CNN
	2    5100 3400
	1    0    0    -1  
$EndComp
Text GLabel 4950 2800 0    60   Input ~ 0
LID_REV_LO
$Comp
L GND #PWR37
U 1 1 569B8D1F
P 5350 3950
F 0 "#PWR37" H 5350 3700 50  0001 C CNN
F 1 "GND" H 5350 3800 50  0000 C CNN
F 2 "" H 5350 3950 60  0000 C CNN
F 3 "" H 5350 3950 60  0000 C CNN
	1    5350 3950
	1    0    0    -1  
$EndComp
Text GLabel 5450 3650 2    60   Input ~ 0
REV_LO
Text GLabel 4950 3650 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	4950 3650 4950 3600
Text GLabel 7250 2200 2    60   Input ~ 0
REV_HI
Text GLabel 7250 3650 2    60   Input ~ 0
FWD_LO
$Comp
L R R5
U 1 1 569A6239
P 4950 3000
F 0 "R5" V 5030 3000 50  0000 C CNN
F 1 "100" V 4950 3000 50  0000 C CNN
F 2 "" V 4880 3000 30  0000 C CNN
F 3 "" H 4950 3000 30  0000 C CNN
	1    4950 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2800 4950 2850
Wire Wire Line
	4950 3150 4950 3200
$Comp
L R R7
U 1 1 569A6B25
P 5350 3800
F 0 "R7" V 5430 3800 50  0000 C CNN
F 1 "1k" V 5350 3800 50  0000 C CNN
F 2 "" V 5280 3800 30  0000 C CNN
F 3 "" H 5350 3800 30  0000 C CNN
	1    5350 3800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR36
U 1 1 569A6C93
P 5350 3200
F 0 "#PWR36" H 5350 3050 50  0001 C CNN
F 1 "+12V" H 5350 3340 50  0000 C CNN
F 2 "" H 5350 3200 60  0000 C CNN
F 3 "" H 5350 3200 60  0000 C CNN
	1    5350 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3200 5350 3200
Wire Wire Line
	5350 3600 5350 3650
Wire Wire Line
	5350 3650 5450 3650
$Comp
L K847PH U3
U 3 1 569AAB60
P 6900 3400
F 0 "U3" H 7370 3550 60  0000 C CNN
F 1 "K847PH" H 7520 3250 60  0000 C CNN
F 2 "" H 6900 3400 60  0000 C CNN
F 3 "" H 6900 3400 60  0000 C CNN
	3    6900 3400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR43
U 1 1 569AAB67
P 7150 3950
F 0 "#PWR43" H 7150 3700 50  0001 C CNN
F 1 "GND" H 7150 3800 50  0000 C CNN
F 2 "" H 7150 3950 60  0000 C CNN
F 3 "" H 7150 3950 60  0000 C CNN
	1    7150 3950
	1    0    0    -1  
$EndComp
Text GLabel 6750 3650 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	6750 3650 6750 3600
$Comp
L R R9
U 1 1 569AAB70
P 6750 3000
F 0 "R9" V 6830 3000 50  0000 C CNN
F 1 "100" V 6750 3000 50  0000 C CNN
F 2 "" V 6680 3000 30  0000 C CNN
F 3 "" H 6750 3000 30  0000 C CNN
	1    6750 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2800 6750 2850
Wire Wire Line
	6750 3150 6750 3200
$Comp
L R R11
U 1 1 569AAB78
P 7150 3800
F 0 "R11" V 7230 3800 50  0000 C CNN
F 1 "1k" V 7150 3800 50  0000 C CNN
F 2 "" V 7080 3800 30  0000 C CNN
F 3 "" H 7150 3800 30  0000 C CNN
	1    7150 3800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR42
U 1 1 569AAB7E
P 7150 3200
F 0 "#PWR42" H 7150 3050 50  0001 C CNN
F 1 "+12V" H 7150 3340 50  0000 C CNN
F 2 "" H 7150 3200 60  0000 C CNN
F 3 "" H 7150 3200 60  0000 C CNN
	1    7150 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3200 7150 3200
Wire Wire Line
	7150 3600 7150 3650
Wire Wire Line
	7150 3650 7250 3650
$Comp
L K847PH U3
U 1 1 569AAE55
P 5100 1950
F 0 "U3" H 5570 2100 60  0000 C CNN
F 1 "K847PH" H 5720 1800 60  0000 C CNN
F 2 "" H 5100 1950 60  0000 C CNN
F 3 "" H 5100 1950 60  0000 C CNN
	1    5100 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR35
U 1 1 569AAE5C
P 5350 2500
F 0 "#PWR35" H 5350 2250 50  0001 C CNN
F 1 "GND" H 5350 2350 50  0000 C CNN
F 2 "" H 5350 2500 60  0000 C CNN
F 3 "" H 5350 2500 60  0000 C CNN
	1    5350 2500
	1    0    0    -1  
$EndComp
Text GLabel 4950 2200 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	4950 2200 4950 2150
$Comp
L R R4
U 1 1 569AAE65
P 4950 1550
F 0 "R4" V 5030 1550 50  0000 C CNN
F 1 "100" V 4950 1550 50  0000 C CNN
F 2 "" V 4880 1550 30  0000 C CNN
F 3 "" H 4950 1550 30  0000 C CNN
	1    4950 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 1350 4950 1400
Wire Wire Line
	4950 1700 4950 1750
$Comp
L R R6
U 1 1 569AAE6D
P 5350 2350
F 0 "R6" V 5430 2350 50  0000 C CNN
F 1 "1k" V 5350 2350 50  0000 C CNN
F 2 "" V 5280 2350 30  0000 C CNN
F 3 "" H 5350 2350 30  0000 C CNN
	1    5350 2350
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR34
U 1 1 569AAE73
P 5350 1750
F 0 "#PWR34" H 5350 1600 50  0001 C CNN
F 1 "+12V" H 5350 1890 50  0000 C CNN
F 2 "" H 5350 1750 60  0000 C CNN
F 3 "" H 5350 1750 60  0000 C CNN
	1    5350 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 1750 5350 1750
Wire Wire Line
	5350 2150 5350 2200
Wire Wire Line
	5350 2200 5450 2200
$Comp
L K847PH U3
U 2 1 569AAE7C
P 6900 1950
F 0 "U3" H 7370 2100 60  0000 C CNN
F 1 "K847PH" H 7520 1800 60  0000 C CNN
F 2 "" H 6900 1950 60  0000 C CNN
F 3 "" H 6900 1950 60  0000 C CNN
	2    6900 1950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR41
U 1 1 569AAE83
P 7150 2500
F 0 "#PWR41" H 7150 2250 50  0001 C CNN
F 1 "GND" H 7150 2350 50  0000 C CNN
F 2 "" H 7150 2500 60  0000 C CNN
F 3 "" H 7150 2500 60  0000 C CNN
	1    7150 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2200 6750 2150
$Comp
L R R8
U 1 1 569AAE8C
P 6750 1550
F 0 "R8" V 6830 1550 50  0000 C CNN
F 1 "100" V 6750 1550 50  0000 C CNN
F 2 "" V 6680 1550 30  0000 C CNN
F 3 "" H 6750 1550 30  0000 C CNN
	1    6750 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 1350 6750 1400
Wire Wire Line
	6750 1700 6750 1750
$Comp
L R R10
U 1 1 569AAE94
P 7150 2350
F 0 "R10" V 7230 2350 50  0000 C CNN
F 1 "1k" V 7150 2350 50  0000 C CNN
F 2 "" V 7080 2350 30  0000 C CNN
F 3 "" H 7150 2350 30  0000 C CNN
	1    7150 2350
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR40
U 1 1 569AAE9A
P 7150 1750
F 0 "#PWR40" H 7150 1600 50  0001 C CNN
F 1 "+12V" H 7150 1890 50  0000 C CNN
F 2 "" H 7150 1750 60  0000 C CNN
F 3 "" H 7150 1750 60  0000 C CNN
	1    7150 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 1750 7150 1750
Wire Wire Line
	7150 2150 7150 2200
Wire Wire Line
	7150 2200 7250 2200
Text GLabel 6750 2200 0    60   Input ~ 0
SIGNAL_GND
Text GLabel 6750 1350 0    60   Input ~ 0
LID_REV_HI
Text GLabel 6750 2800 0    60   Input ~ 0
LID_FWD_LO
Text GLabel 4950 1350 0    60   Input ~ 0
LID_FWD_HI
$EndSCHEMATC
