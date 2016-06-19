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
LIBS:roboCooler
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
P 6550 4700
F 0 "Q7" H 6850 4750 50  0000 R CNN
F 1 "NMOS" H 6950 4650 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 6750 4800 29  0001 C CNN
F 3 "" H 6550 4700 60  0000 C CNN
	1    6550 4700
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4050 4900 7150 4900
$Comp
L GND #PWR048
U 1 1 569B3E2F
P 5600 4900
F 0 "#PWR048" H 5600 4650 50  0001 C CNN
F 1 "GND" H 5600 4750 50  0000 C CNN
F 2 "" H 5600 4900 60  0000 C CNN
F 3 "" H 5600 4900 60  0000 C CNN
	1    5600 4900
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q6
U 1 1 569B3E35
P 6550 4300
F 0 "Q6" H 6850 4350 50  0000 R CNN
F 1 "PMOS" H 6950 4250 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 6750 4400 29  0001 C CNN
F 3 "" H 6550 4300 60  0000 C CNN
	1    6550 4300
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4600 4100 6600 4100
$Comp
L +12V #PWR049
U 1 1 569B3E3D
P 5600 4100
F 0 "#PWR049" H 5600 3950 50  0001 C CNN
F 1 "+12V" H 5600 4240 50  0000 C CNN
F 2 "" H 5600 4100 60  0000 C CNN
F 3 "" H 5600 4100 60  0000 C CNN
	1    5600 4100
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D3
U 1 1 569B3E43
P 5150 4300
F 0 "D3" H 5100 4380 50  0000 L CNN
F 1 "D_Schottky_Small" H 4870 4220 50  0001 L CNN
F 2 "Diodes_ThroughHole:Diode_P600_Vertical_AnodeUp" V 5150 4300 60  0001 C CNN
F 3 "" V 5150 4300 60  0000 C CNN
	1    5150 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	4750 4500 5500 4500
$Comp
L D_Schottky_Small D4
U 1 1 569B3E4B
P 5150 4700
F 0 "D4" H 5100 4780 50  0000 L CNN
F 1 "D_Schottky_Small" H 4870 4620 50  0001 L CNN
F 2 "Diodes_ThroughHole:Diode_P600_Vertical_AnodeUp" V 5150 4700 60  0001 C CNN
F 3 "" V 5150 4700 60  0000 C CNN
	1    5150 4700
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D6
U 1 1 569B3E52
P 6050 4700
F 0 "D6" H 6000 4780 50  0000 L CNN
F 1 "D_Schottky_Small" H 5770 4620 50  0001 L CNN
F 2 "Diodes_ThroughHole:Diode_P600_Vertical_AnodeUp" V 6050 4700 60  0001 C CNN
F 3 "" V 6050 4700 60  0000 C CNN
	1    6050 4700
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D5
U 1 1 569B3E59
P 6050 4300
F 0 "D5" H 6000 4380 50  0000 L CNN
F 1 "D_Schottky_Small" H 5770 4220 50  0001 L CNN
F 2 "Diodes_ThroughHole:Diode_P600_Vertical_AnodeUp" V 6050 4300 60  0001 C CNN
F 3 "" V 6050 4300 60  0000 C CNN
	1    6050 4300
	0    1    1    0   
$EndComp
Wire Wire Line
	5150 4800 5150 4900
Connection ~ 5150 4900
Wire Wire Line
	5150 4400 5150 4600
Connection ~ 5150 4500
Wire Wire Line
	5150 4200 5150 4100
Connection ~ 5150 4100
Wire Wire Line
	5700 4500 6450 4500
Wire Wire Line
	6050 4400 6050 4600
Connection ~ 6050 4500
Wire Wire Line
	6050 4800 6050 4900
Connection ~ 6050 4900
Wire Wire Line
	6050 4200 6050 4100
Connection ~ 6050 4100
Text Notes 3300 4150 0    60   ~ 0
LID MOTOR
Text GLabel 3750 4700 0    60   Input ~ 0
FWD_HI
Text GLabel 7450 4450 2    60   Input ~ 0
FWD_LO
Text GLabel 7450 4700 2    60   Input ~ 0
REV_HI
$Comp
L Q_NMOS_DGS Q8
U 1 1 569B3E78
P 7250 4700
F 0 "Q8" H 7550 4750 50  0000 R CNN
F 1 "NMOS" H 7650 4650 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 7450 4800 29  0001 C CNN
F 3 "" H 7250 4700 60  0000 C CNN
	1    7250 4700
	-1   0    0    -1  
$EndComp
Connection ~ 6450 4900
Wire Wire Line
	6750 4300 7150 4300
Wire Wire Line
	7150 4100 7150 4500
$Comp
L R R9
U 1 1 569B3E82
P 6750 4100
F 0 "R9" V 6830 4100 50  0000 C CNN
F 1 "1k" V 6750 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6680 4100 30  0001 C CNN
F 3 "" H 6750 4100 30  0000 C CNN
	1    6750 4100
	0    1    1    0   
$EndComp
Connection ~ 6450 4100
Wire Wire Line
	6900 4100 7150 4100
Connection ~ 7150 4300
Wire Wire Line
	7450 4450 6750 4450
Wire Wire Line
	6750 4450 6750 4700
$Comp
L Q_NMOS_DGS Q5
U 1 1 569B3E8E
P 4650 4700
F 0 "Q5" H 4950 4750 50  0000 R CNN
F 1 "NMOS" H 5050 4650 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 4850 4800 29  0001 C CNN
F 3 "" H 4650 4700 60  0000 C CNN
	1    4650 4700
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q4
U 1 1 569B3E95
P 4650 4300
F 0 "Q4" H 4950 4350 50  0000 R CNN
F 1 "PMOS" H 5050 4250 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 4850 4400 29  0001 C CNN
F 3 "" H 4650 4300 60  0000 C CNN
	1    4650 4300
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q3
U 1 1 569B3E9C
P 3950 4700
F 0 "Q3" H 4250 4750 50  0000 R CNN
F 1 "NMOS" H 4350 4650 50  0000 R CNN
F 2 "Transistors_OldSowjetAera:OldSowjetaera_Transistor_Type-II_BigPads" H 4150 4800 29  0001 C CNN
F 3 "" H 3950 4700 60  0000 C CNN
	1    3950 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4300 4050 4300
Wire Wire Line
	4050 4100 4050 4500
$Comp
L R R2
U 1 1 569B3EA5
P 4450 4100
F 0 "R2" V 4530 4100 50  0000 C CNN
F 1 "1k" V 4450 4100 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4380 4100 30  0001 C CNN
F 3 "" H 4450 4100 30  0000 C CNN
	1    4450 4100
	0    -1   1    0   
$EndComp
Wire Wire Line
	4300 4100 4050 4100
Connection ~ 4050 4300
Wire Wire Line
	3800 4450 4450 4450
Wire Wire Line
	4450 4450 4450 4700
Connection ~ 4750 4100
Connection ~ 4750 4900
Wire Wire Line
	3750 4700 3750 4700
Text GLabel 5100 1650 2    60   Input ~ 0
FWD_HI
Text GLabel 3800 4450 0    60   Input ~ 0
REV_LO
Text GLabel 3300 1900 0    60   Input ~ 0
POWER_GND
$Comp
L GND #PWR050
U 1 1 569B77C8
P 3300 1950
F 0 "#PWR050" H 3300 1700 50  0001 C CNN
F 1 "GND" H 3300 1800 50  0000 C CNN
F 2 "" H 3300 1950 60  0000 C CNN
F 3 "" H 3300 1950 60  0000 C CNN
	1    3300 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1900 3300 1950
$Comp
L K847PH U6
U 2 1 569B8D17
P 4750 2850
F 0 "U6" H 5220 3000 60  0000 C CNN
F 1 "K847PH" H 5370 2700 60  0000 C CNN
F 2 "" H 4750 2850 60  0001 C CNN
F 3 "" H 4750 2850 60  0000 C CNN
	2    4750 2850
	1    0    0    -1  
$EndComp
Text GLabel 4600 2250 0    60   Input ~ 0
LID_REV_LO
$Comp
L GND #PWR051
U 1 1 569B8D1F
P 5000 3400
F 0 "#PWR051" H 5000 3150 50  0001 C CNN
F 1 "GND" H 5000 3250 50  0000 C CNN
F 2 "" H 5000 3400 60  0000 C CNN
F 3 "" H 5000 3400 60  0000 C CNN
	1    5000 3400
	1    0    0    -1  
$EndComp
Text GLabel 5100 3100 2    60   Input ~ 0
REV_LO
Text GLabel 4600 3100 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	4600 3100 4600 3050
Text GLabel 6900 1650 2    60   Input ~ 0
REV_HI
Text GLabel 6900 3100 2    60   Input ~ 0
FWD_LO
$Comp
L R R4
U 1 1 569A6239
P 4600 2450
F 0 "R4" V 4680 2450 50  0000 C CNN
F 1 "100" V 4600 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4530 2450 30  0001 C CNN
F 3 "" H 4600 2450 30  0000 C CNN
	1    4600 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2250 4600 2300
Wire Wire Line
	4600 2600 4600 2650
$Comp
L R R6
U 1 1 569A6B25
P 5000 3250
F 0 "R6" V 5080 3250 50  0000 C CNN
F 1 "1k" V 5000 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4930 3250 30  0001 C CNN
F 3 "" H 5000 3250 30  0000 C CNN
	1    5000 3250
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR052
U 1 1 569A6C93
P 5000 2650
F 0 "#PWR052" H 5000 2500 50  0001 C CNN
F 1 "+12V" H 5000 2790 50  0000 C CNN
F 2 "" H 5000 2650 60  0000 C CNN
F 3 "" H 5000 2650 60  0000 C CNN
	1    5000 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 2650 5000 2650
Wire Wire Line
	5000 3050 5000 3100
Wire Wire Line
	5000 3100 5100 3100
$Comp
L K847PH U5
U 3 1 569AAB60
P 6550 2850
F 0 "U5" H 7020 3000 60  0000 C CNN
F 1 "K847PH" H 7170 2700 60  0000 C CNN
F 2 "" H 6550 2850 60  0001 C CNN
F 3 "" H 6550 2850 60  0000 C CNN
	3    6550 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR053
U 1 1 569AAB67
P 6800 3400
F 0 "#PWR053" H 6800 3150 50  0001 C CNN
F 1 "GND" H 6800 3250 50  0000 C CNN
F 2 "" H 6800 3400 60  0000 C CNN
F 3 "" H 6800 3400 60  0000 C CNN
	1    6800 3400
	1    0    0    -1  
$EndComp
Text GLabel 6400 3100 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	6400 3100 6400 3050
$Comp
L R R8
U 1 1 569AAB70
P 6400 2450
F 0 "R8" V 6480 2450 50  0000 C CNN
F 1 "100" V 6400 2450 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6330 2450 30  0001 C CNN
F 3 "" H 6400 2450 30  0000 C CNN
	1    6400 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 2250 6400 2300
Wire Wire Line
	6400 2600 6400 2650
$Comp
L R R11
U 1 1 569AAB78
P 6800 3250
F 0 "R11" V 6880 3250 50  0000 C CNN
F 1 "1k" V 6800 3250 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6730 3250 30  0001 C CNN
F 3 "" H 6800 3250 30  0000 C CNN
	1    6800 3250
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR054
U 1 1 569AAB7E
P 6800 2650
F 0 "#PWR054" H 6800 2500 50  0001 C CNN
F 1 "+12V" H 6800 2790 50  0000 C CNN
F 2 "" H 6800 2650 60  0000 C CNN
F 3 "" H 6800 2650 60  0000 C CNN
	1    6800 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2650 6800 2650
Wire Wire Line
	6800 3050 6800 3100
Wire Wire Line
	6800 3100 6900 3100
$Comp
L K847PH U5
U 1 1 569AAE55
P 4750 1400
F 0 "U5" H 5220 1550 60  0000 C CNN
F 1 "K847PH" H 5370 1250 60  0000 C CNN
F 2 "" H 4750 1400 60  0001 C CNN
F 3 "" H 4750 1400 60  0000 C CNN
	1    4750 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR055
U 1 1 569AAE5C
P 5000 1950
F 0 "#PWR055" H 5000 1700 50  0001 C CNN
F 1 "GND" H 5000 1800 50  0000 C CNN
F 2 "" H 5000 1950 60  0000 C CNN
F 3 "" H 5000 1950 60  0000 C CNN
	1    5000 1950
	1    0    0    -1  
$EndComp
Text GLabel 4600 1650 0    60   Input ~ 0
SIGNAL_GND
Wire Wire Line
	4600 1650 4600 1600
$Comp
L R R3
U 1 1 569AAE65
P 4600 1000
F 0 "R3" V 4680 1000 50  0000 C CNN
F 1 "100" V 4600 1000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4530 1000 30  0001 C CNN
F 3 "" H 4600 1000 30  0000 C CNN
	1    4600 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 800  4600 850 
Wire Wire Line
	4600 1150 4600 1200
$Comp
L R R5
U 1 1 569AAE6D
P 5000 1800
F 0 "R5" V 5080 1800 50  0000 C CNN
F 1 "1k" V 5000 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 4930 1800 30  0001 C CNN
F 3 "" H 5000 1800 30  0000 C CNN
	1    5000 1800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR056
U 1 1 569AAE73
P 5000 1200
F 0 "#PWR056" H 5000 1050 50  0001 C CNN
F 1 "+12V" H 5000 1340 50  0000 C CNN
F 2 "" H 5000 1200 60  0000 C CNN
F 3 "" H 5000 1200 60  0000 C CNN
	1    5000 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 1200 5000 1200
Wire Wire Line
	5000 1600 5000 1650
Wire Wire Line
	5000 1650 5100 1650
$Comp
L K847PH U5
U 2 1 569AAE7C
P 6550 1400
F 0 "U5" H 7020 1550 60  0000 C CNN
F 1 "K847PH" H 7170 1250 60  0000 C CNN
F 2 "" H 6550 1400 60  0001 C CNN
F 3 "" H 6550 1400 60  0000 C CNN
	2    6550 1400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR057
U 1 1 569AAE83
P 6800 1950
F 0 "#PWR057" H 6800 1700 50  0001 C CNN
F 1 "GND" H 6800 1800 50  0000 C CNN
F 2 "" H 6800 1950 60  0000 C CNN
F 3 "" H 6800 1950 60  0000 C CNN
	1    6800 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 1650 6400 1600
$Comp
L R R7
U 1 1 569AAE8C
P 6400 1000
F 0 "R7" V 6480 1000 50  0000 C CNN
F 1 "100" V 6400 1000 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6330 1000 30  0001 C CNN
F 3 "" H 6400 1000 30  0000 C CNN
	1    6400 1000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 800  6400 850 
Wire Wire Line
	6400 1150 6400 1200
$Comp
L R R10
U 1 1 569AAE94
P 6800 1800
F 0 "R10" V 6880 1800 50  0000 C CNN
F 1 "1k" V 6800 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_0805_HandSoldering" V 6730 1800 30  0001 C CNN
F 3 "" H 6800 1800 30  0000 C CNN
	1    6800 1800
	1    0    0    -1  
$EndComp
$Comp
L +12V #PWR058
U 1 1 569AAE9A
P 6800 1200
F 0 "#PWR058" H 6800 1050 50  0001 C CNN
F 1 "+12V" H 6800 1340 50  0000 C CNN
F 2 "" H 6800 1200 60  0000 C CNN
F 3 "" H 6800 1200 60  0000 C CNN
	1    6800 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 1200 6800 1200
Wire Wire Line
	6800 1600 6800 1650
Wire Wire Line
	6800 1650 6900 1650
Text GLabel 6400 1650 0    60   Input ~ 0
SIGNAL_GND
Text GLabel 6400 800  0    60   Input ~ 0
LID_REV_HI
Text GLabel 6400 2250 0    60   Input ~ 0
LID_FWD_LO
Text GLabel 4600 800  0    60   Input ~ 0
LID_FWD_HI
Text GLabel 5500 4500 1    60   Input ~ 0
MTR_HI
Text GLabel 5700 4500 1    60   Input ~ 0
MTR_LO
Text GLabel 4150 5750 0    60   Input ~ 0
MTR_HI
Text GLabel 4150 5850 0    60   Input ~ 0
MTR_LO
Wire Notes Line
	4950 5800 6100 5800
$Comp
L CONN_01X02 J16
U 1 1 569F335E
P 4350 5800
F 0 "J16" H 4350 5950 50  0000 C CNN
F 1 "CONN_01X02" V 4450 5800 50  0000 C CNN
F 2 "" H 4350 5800 60  0001 C CNN
F 3 "" H 4350 5800 60  0000 C CNN
	1    4350 5800
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P16
U 1 1 569F3504
P 4700 5800
F 0 "P16" H 4700 5950 50  0000 C CNN
F 1 "CONN_01X02" V 4800 5800 50  0000 C CNN
F 2 "" H 4700 5800 60  0001 C CNN
F 3 "" H 4700 5800 60  0000 C CNN
	1    4700 5800
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X02 J17
U 1 1 569F38A2
P 6700 5800
F 0 "J17" H 6700 5950 50  0000 C CNN
F 1 "CONN_01X02" V 6800 5800 50  0000 C CNN
F 2 "" H 6700 5800 60  0001 C CNN
F 3 "" H 6700 5800 60  0000 C CNN
	1    6700 5800
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X02 P17
U 1 1 569F38A8
P 6350 5800
F 0 "P17" H 6350 5950 50  0000 C CNN
F 1 "CONN_01X02" V 6450 5800 50  0000 C CNN
F 2 "" H 6350 5800 60  0001 C CNN
F 3 "" H 6350 5800 60  0000 C CNN
	1    6350 5800
	1    0    0    -1  
$EndComp
Text Notes 6950 5850 0    60   ~ 0
MOTOR
$EndSCHEMATC
