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
Sheet 1 1
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
L CONN_02X25 P1
U 1 1 5664C6E0
P 1450 2650
F 0 "P1" H 1450 3950 50  0000 C CNN
F 1 "CONN_02X25" V 1450 2650 50  0000 C CNN
F 2 "" H 1450 1900 60  0000 C CNN
F 3 "" H 1450 1900 60  0000 C CNN
	1    1450 2650
	1    0    0    -1  
$EndComp
$Comp
L CONN_02X25 P2
U 1 1 5664C828
P 3400 2650
F 0 "P2" H 3400 3950 50  0000 C CNN
F 1 "CONN_02X25" V 3400 2650 50  0000 C CNN
F 2 "" H 3400 1900 60  0000 C CNN
F 3 "" H 3400 1900 60  0000 C CNN
	1    3400 2650
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q6
U 1 1 5664CBFF
P 9400 1550
F 0 "Q6" H 9700 1600 50  0000 R CNN
F 1 "NMOS" H 9800 1500 50  0000 R CNN
F 2 "" H 9600 1650 29  0000 C CNN
F 3 "" H 9400 1550 60  0000 C CNN
	1    9400 1550
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6900 1750 7600 1750
Wire Wire Line
	7600 1750 8000 1750
Wire Wire Line
	8000 1750 8900 1750
Wire Wire Line
	8900 1750 9300 1750
Wire Wire Line
	9300 1750 10000 1750
$Comp
L GND #PWR34
U 1 1 5664CD30
P 8450 1750
F 0 "#PWR34" H 8450 1500 50  0001 C CNN
F 1 "GND" H 8450 1600 50  0000 C CNN
F 2 "" H 8450 1750 60  0000 C CNN
F 3 "" H 8450 1750 60  0000 C CNN
	1    8450 1750
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q5
U 1 1 5664CE1A
P 9400 1150
F 0 "Q5" H 9700 1200 50  0000 R CNN
F 1 "PMOS" H 9800 1100 50  0000 R CNN
F 2 "" H 9600 1250 29  0000 C CNN
F 3 "" H 9400 1150 60  0000 C CNN
	1    9400 1150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7450 950  7600 950 
Wire Wire Line
	7600 950  8000 950 
Wire Wire Line
	8000 950  8900 950 
Wire Wire Line
	8900 950  9300 950 
Wire Wire Line
	9300 950  9450 950 
$Comp
L +12V #PWR33
U 1 1 5664CE80
P 8450 950
F 0 "#PWR33" H 8450 800 50  0001 C CNN
F 1 "+12V" H 8450 1090 50  0000 C CNN
F 2 "" H 8450 950 60  0000 C CNN
F 3 "" H 8450 950 60  0000 C CNN
	1    8450 950 
	1    0    0    -1  
$EndComp
$Comp
L D_Schottky_Small D3
U 1 1 5664D252
P 8000 1150
F 0 "D3" H 7950 1230 50  0000 L CNN
F 1 "D_Schottky_Small" H 7720 1070 50  0001 L CNN
F 2 "" V 8000 1150 60  0000 C CNN
F 3 "" V 8000 1150 60  0000 C CNN
	1    8000 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	7600 1350 8000 1350
Wire Wire Line
	8000 1350 8350 1350
$Comp
L D_Schottky_Small D4
U 1 1 5664E2D8
P 8000 1550
F 0 "D4" H 7950 1630 50  0000 L CNN
F 1 "D_Schottky_Small" H 7720 1470 50  0001 L CNN
F 2 "" V 8000 1550 60  0000 C CNN
F 3 "" V 8000 1550 60  0000 C CNN
	1    8000 1550
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D6
U 1 1 5664E317
P 8900 1550
F 0 "D6" H 8850 1630 50  0000 L CNN
F 1 "D_Schottky_Small" H 8620 1470 50  0001 L CNN
F 2 "" V 8900 1550 60  0000 C CNN
F 3 "" V 8900 1550 60  0000 C CNN
	1    8900 1550
	0    1    1    0   
$EndComp
$Comp
L D_Schottky_Small D5
U 1 1 5664E35D
P 8900 1150
F 0 "D5" H 8850 1230 50  0000 L CNN
F 1 "D_Schottky_Small" H 8620 1070 50  0001 L CNN
F 2 "" V 8900 1150 60  0000 C CNN
F 3 "" V 8900 1150 60  0000 C CNN
	1    8900 1150
	0    1    1    0   
$EndComp
Wire Wire Line
	8000 1650 8000 1750
Connection ~ 8000 1750
Wire Wire Line
	8000 1250 8000 1350
Wire Wire Line
	8000 1350 8000 1450
Connection ~ 8000 1350
Wire Wire Line
	8000 1050 8000 950 
Connection ~ 8000 950 
Wire Wire Line
	8550 1350 8900 1350
Wire Wire Line
	8900 1350 9300 1350
Wire Wire Line
	8900 1250 8900 1350
Wire Wire Line
	8900 1350 8900 1450
Connection ~ 8900 1350
Wire Wire Line
	8900 1650 8900 1750
Connection ~ 8900 1750
Wire Wire Line
	8900 1050 8900 950 
Connection ~ 8900 950 
$Comp
L CONN_01X06 P8
U 1 1 5664F3ED
P 4350 4550
F 0 "P8" H 4350 4900 50  0000 C CNN
F 1 "CONN_01X06" V 4450 4550 50  0000 C CNN
F 2 "" H 4350 4550 60  0000 C CNN
F 3 "" H 4350 4550 60  0000 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X12 P12
U 1 1 5664F5C8
P 5350 4650
F 0 "P12" H 5350 5300 50  0000 C CNN
F 1 "CONN_01X12" V 5450 4650 50  0000 C CNN
F 2 "" H 5350 4650 60  0000 C CNN
F 3 "" H 5350 4650 60  0000 C CNN
	1    5350 4650
	1    0    0    -1  
$EndComp
Text Notes 6150 1000 0    60   ~ 0
LID MOTOR
Text Notes 3200 4600 0    60   ~ 0
CAP SENSE
$Comp
L D_Schottky_Small D2
U 1 1 56650333
P 4750 6900
F 0 "D2" H 4700 6980 50  0000 L CNN
F 1 "D_Schottky_Small" H 4470 6820 50  0001 L CNN
F 2 "" V 4750 6900 60  0000 C CNN
F 3 "" V 4750 6900 60  0000 C CNN
	1    4750 6900
	0    -1   1    0   
$EndComp
$Comp
L +12V #PWR31
U 1 1 56650D8D
P 4850 6800
F 0 "#PWR31" H 4850 6650 50  0001 C CNN
F 1 "+12V" H 4850 6940 50  0000 C CNN
F 2 "" H 4850 6800 60  0000 C CNN
F 3 "" H 4850 6800 60  0000 C CNN
	1    4850 6800
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q4
U 1 1 566512F1
P 4750 7250
F 0 "Q4" H 5050 7300 50  0000 R CNN
F 1 "NMOS" H 5150 7200 50  0000 R CNN
F 2 "" H 4950 7350 29  0000 C CNN
F 3 "" H 4750 7250 60  0000 C CNN
	1    4750 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 7050 4850 7000
Wire Wire Line
	4750 6800 4850 6800
Wire Wire Line
	4850 7000 4750 7000
Connection ~ 4850 7000
$Comp
L GND #PWR32
U 1 1 56651EDA
P 4850 7450
F 0 "#PWR32" H 4850 7200 50  0001 C CNN
F 1 "GND" H 4850 7300 50  0000 C CNN
F 2 "" H 4850 7450 60  0000 C CNN
F 3 "" H 4850 7450 60  0000 C CNN
	1    4850 7450
	1    0    0    -1  
$EndComp
Text Notes 3750 6950 0    60   ~ 0
PUMP
$Comp
L D_Schottky_Small D1
U 1 1 566526F5
P 4700 5750
F 0 "D1" H 4650 5830 50  0000 L CNN
F 1 "D_Schottky_Small" H 4420 5670 50  0001 L CNN
F 2 "" V 4700 5750 60  0000 C CNN
F 3 "" V 4700 5750 60  0000 C CNN
	1    4700 5750
	0    -1   1    0   
$EndComp
$Comp
L +12V #PWR29
U 1 1 56652701
P 4850 5650
F 0 "#PWR29" H 4850 5500 50  0001 C CNN
F 1 "+12V" H 4850 5790 50  0000 C CNN
F 2 "" H 4850 5650 60  0000 C CNN
F 3 "" H 4850 5650 60  0000 C CNN
	1    4850 5650
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q3
U 1 1 56652707
P 4750 6100
F 0 "Q3" H 5050 6150 50  0000 R CNN
F 1 "NMOS" H 5150 6050 50  0000 R CNN
F 2 "" H 4950 6200 29  0000 C CNN
F 3 "" H 4750 6100 60  0000 C CNN
	1    4750 6100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 5900 4850 5850
Wire Wire Line
	4700 5650 4850 5650
Wire Wire Line
	4850 5850 4700 5850
Connection ~ 4850 5850
$Comp
L GND #PWR30
U 1 1 56652712
P 4850 6300
F 0 "#PWR30" H 4850 6050 50  0001 C CNN
F 1 "GND" H 4850 6150 50  0000 C CNN
F 2 "" H 4850 6300 60  0000 C CNN
F 3 "" H 4850 6300 60  0000 C CNN
	1    4850 6300
	1    0    0    -1  
$EndComp
Text Notes 3750 5800 0    60   ~ 0
FAN
$Comp
L CONN_01X03 P3
U 1 1 56653340
P 7850 6000
F 0 "P3" H 7850 6200 50  0000 C CNN
F 1 "CONN_01X03" V 7950 6000 50  0000 C CNN
F 2 "" H 7850 6000 60  0000 C CNN
F 3 "" H 7850 6000 60  0000 C CNN
	1    7850 6000
	1    0    0    -1  
$EndComp
Text Notes 6500 5500 0    60   ~ 0
LED STRIP
$Comp
L 4069 U1
U 1 1 5665387C
P 6750 6000
F 0 "U1" H 6945 6115 60  0000 C CNN
F 1 "4069" H 6940 5875 60  0001 C CNN
F 2 "" H 6750 6000 60  0000 C CNN
F 3 "" H 6750 6000 60  0000 C CNN
	1    6750 6000
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 56653A46
P 7200 5850
F 0 "R1" V 7280 5850 50  0000 C CNN
F 1 "R" V 7200 5850 50  0000 C CNN
F 2 "" V 7130 5850 30  0000 C CNN
F 3 "" H 7200 5850 30  0000 C CNN
	1    7200 5850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR18
U 1 1 56653B39
P 7200 5700
F 0 "#PWR18" H 7200 5550 50  0001 C CNN
F 1 "+5V" H 7200 5840 50  0000 C CNN
F 2 "" H 7200 5700 60  0000 C CNN
F 3 "" H 7200 5700 60  0000 C CNN
	1    7200 5700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR20
U 1 1 56653BAF
P 7650 6100
F 0 "#PWR20" H 7650 5850 50  0001 C CNN
F 1 "GND" H 7650 5950 50  0000 C CNN
F 2 "" H 7650 6100 60  0000 C CNN
F 3 "" H 7650 6100 60  0000 C CNN
	1    7650 6100
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR19
U 1 1 56653C03
P 7650 5900
F 0 "#PWR19" H 7650 5750 50  0001 C CNN
F 1 "+5V" H 7650 6040 50  0000 C CNN
F 2 "" H 7650 5900 60  0000 C CNN
F 3 "" H 7650 5900 60  0000 C CNN
	1    7650 5900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 6000 7650 6000
$Comp
L CONN_01X03 P5
U 1 1 5665430D
P 2300 5250
F 0 "P5" H 2300 5450 50  0000 C CNN
F 1 "CONN_01X03" V 2400 5250 50  0000 C CNN
F 2 "" H 2300 5250 60  0000 C CNN
F 3 "" H 2300 5250 60  0000 C CNN
	1    2300 5250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR24
U 1 1 56654313
P 2100 5350
F 0 "#PWR24" H 2100 5100 50  0001 C CNN
F 1 "GND" H 2100 5200 50  0000 C CNN
F 2 "" H 2100 5350 60  0000 C CNN
F 3 "" H 2100 5350 60  0000 C CNN
	1    2100 5350
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR23
U 1 1 56654319
P 2100 5150
F 0 "#PWR23" H 2100 5000 50  0001 C CNN
F 1 "+5V" H 2100 5290 50  0000 C CNN
F 2 "" H 2100 5150 60  0000 C CNN
F 3 "" H 2100 5150 60  0000 C CNN
	1    2100 5150
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 5250 2100 5250
$Comp
L CONN_01X03 P4
U 1 1 566546C1
P 2300 4600
F 0 "P4" H 2300 4800 50  0000 C CNN
F 1 "CONN_01X03" V 2400 4600 50  0000 C CNN
F 2 "" H 2300 4600 60  0000 C CNN
F 3 "" H 2300 4600 60  0000 C CNN
	1    2300 4600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR22
U 1 1 566546C7
P 2100 4700
F 0 "#PWR22" H 2100 4450 50  0001 C CNN
F 1 "GND" H 2100 4550 50  0000 C CNN
F 2 "" H 2100 4700 60  0000 C CNN
F 3 "" H 2100 4700 60  0000 C CNN
	1    2100 4700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR21
U 1 1 566546CD
P 2100 4500
F 0 "#PWR21" H 2100 4350 50  0001 C CNN
F 1 "+5V" H 2100 4640 50  0000 C CNN
F 2 "" H 2100 4500 60  0000 C CNN
F 3 "" H 2100 4500 60  0000 C CNN
	1    2100 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 4600 2100 4600
Text Notes 700  4950 0    60   ~ 0
HALL SENSORS
$Comp
L GND #PWR25
U 1 1 56654C94
P 2100 6400
F 0 "#PWR25" H 2100 6150 50  0001 C CNN
F 1 "GND" H 2100 6250 50  0000 C CNN
F 2 "" H 2100 6400 60  0000 C CNN
F 3 "" H 2100 6400 60  0000 C CNN
	1    2100 6400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR26
U 1 1 56654CF4
P 2100 7200
F 0 "#PWR26" H 2100 6950 50  0001 C CNN
F 1 "GND" H 2100 7050 50  0000 C CNN
F 2 "" H 2100 7200 60  0000 C CNN
F 3 "" H 2100 7200 60  0000 C CNN
	1    2100 7200
	1    0    0    -1  
$EndComp
Text Notes 850  6700 0    60   ~ 0
MOM PUSH BUTTONS
Text GLabel 3150 2550 0    60   Input ~ 0
LED_UART
Text GLabel 6300 6000 0    60   Input ~ 0
LED_UART
Text GLabel 3150 2350 0    60   Input ~ 0
CS_SCL
Text GLabel 3650 2550 2    60   Input ~ 0
CS_SDA
Text GLabel 1200 2750 0    60   Input ~ 0
LID_FWD_HI
Text GLabel 1200 2850 0    60   Input ~ 0
LID_FWD_LO
Text GLabel 1200 2950 0    60   Input ~ 0
LID_REF_HI
Text GLabel 1700 2950 2    60   Input ~ 0
LID_REV_LO
Text GLabel 6600 1550 0    60   Input ~ 0
LID_FWD_HI
Text GLabel 10300 1300 2    60   Input ~ 0
LID_FWD_LO
Text GLabel 10300 1550 2    60   Input ~ 0
LID_REV_HI
Text GLabel 6650 1300 0    60   Input ~ 0
LID_REV_LO
Text GLabel 1200 3150 0    60   Input ~ 0
HALL_1
Text GLabel 1700 3150 2    60   Input ~ 0
HALL_2
Text GLabel 1650 4600 0    60   Input ~ 0
HALL_1
Text GLabel 1650 5250 0    60   Input ~ 0
HALL_2
Text GLabel 2100 6300 0    60   Input ~ 0
PUSH_1
Text GLabel 2100 7100 0    60   Input ~ 0
PUSH_2
Text GLabel 3150 3250 0    60   Input ~ 0
PUSH_1
Text GLabel 3150 3350 0    60   Input ~ 0
PUSH_2
Text GLabel 3150 2650 0    60   Input ~ 0
PUMP
Text GLabel 4550 7250 0    60   Input ~ 0
PUMP
Text GLabel 1700 2250 2    60   Input ~ 0
FAN
Text GLabel 4550 6100 0    60   Input ~ 0
FAN
Text GLabel 4150 4600 0    60   Input ~ 0
CS_SDA
Text GLabel 4150 4500 0    60   Input ~ 0
CS_SCL
$Comp
L GND #PWR28
U 1 1 566606B9
P 4150 4800
F 0 "#PWR28" H 4150 4550 50  0001 C CNN
F 1 "GND" H 4150 4650 50  0000 C CNN
F 2 "" H 4150 4800 60  0000 C CNN
F 3 "" H 4150 4800 60  0000 C CNN
	1    4150 4800
	1    0    0    -1  
$EndComp
Text GLabel 4150 4400 0    60   Input ~ 0
CS_IRQ
Text GLabel 3650 3650 2    60   Input ~ 0
CS_IRQ
$Comp
L +3.3V #PWR11
U 1 1 566628DD
P 3150 1650
F 0 "#PWR11" H 3150 1500 50  0001 C CNN
F 1 "+3.3V" V 3150 1900 50  0000 C CNN
F 2 "" H 3150 1650 60  0000 C CNN
F 3 "" H 3150 1650 60  0000 C CNN
	1    3150 1650
	0    -1   -1   0   
$EndComp
$Comp
L +3.3V #PWR15
U 1 1 56662C86
P 3650 1650
F 0 "#PWR15" H 3650 1500 50  0001 C CNN
F 1 "+3.3V" V 3650 1900 50  0000 C CNN
F 2 "" H 3650 1650 60  0000 C CNN
F 3 "" H 3650 1650 60  0000 C CNN
	1    3650 1650
	0    1    -1   0   
$EndComp
$Comp
L +5V #PWR14
U 1 1 56662DEF
P 3650 1550
F 0 "#PWR14" H 3650 1400 50  0001 C CNN
F 1 "+5V" V 3650 1750 50  0000 C CNN
F 2 "" H 3650 1550 60  0000 C CNN
F 3 "" H 3650 1550 60  0000 C CNN
	1    3650 1550
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR10
U 1 1 56662F8C
P 3150 1550
F 0 "#PWR10" H 3150 1400 50  0001 C CNN
F 1 "+5V" V 3150 1750 50  0000 C CNN
F 2 "" H 3150 1550 60  0000 C CNN
F 3 "" H 3150 1550 60  0000 C CNN
	1    3150 1550
	0    -1   1    0   
$EndComp
$Comp
L VDD #PWR2
U 1 1 566635F5
P 1200 1550
F 0 "#PWR2" H 1200 1400 50  0001 C CNN
F 1 "VDD" V 1200 1750 50  0000 C CNN
F 2 "" H 1200 1550 60  0000 C CNN
F 3 "" H 1200 1550 60  0000 C CNN
	1    1200 1550
	0    -1   -1   0   
$EndComp
$Comp
L VDD #PWR7
U 1 1 56663958
P 1700 1550
F 0 "#PWR7" H 1700 1400 50  0001 C CNN
F 1 "VDD" V 1700 1750 50  0000 C CNN
F 2 "" H 1700 1550 60  0000 C CNN
F 3 "" H 1700 1550 60  0000 C CNN
	1    1700 1550
	0    1    -1   0   
$EndComp
$Comp
L VDD #PWR16
U 1 1 56663A29
P 3650 2450
F 0 "#PWR16" H 3650 2300 50  0001 C CNN
F 1 "VDD" V 3650 2650 50  0000 C CNN
F 2 "" H 3650 2450 60  0000 C CNN
F 3 "" H 3650 2450 60  0000 C CNN
	1    3650 2450
	0    1    -1   0   
$EndComp
$Comp
L GND #PWR1
U 1 1 56663D28
P 1200 1450
F 0 "#PWR1" H 1200 1200 50  0001 C CNN
F 1 "GND" V 1200 1250 50  0000 C CNN
F 2 "" H 1200 1450 60  0000 C CNN
F 3 "" H 1200 1450 60  0000 C CNN
	1    1200 1450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR6
U 1 1 566646FF
P 1700 1450
F 0 "#PWR6" H 1700 1200 50  0001 C CNN
F 1 "GND" V 1700 1250 50  0000 C CNN
F 2 "" H 1700 1450 60  0000 C CNN
F 3 "" H 1700 1450 60  0000 C CNN
	1    1700 1450
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR3
U 1 1 566649A4
P 1200 1650
F 0 "#PWR3" H 1200 1400 50  0001 C CNN
F 1 "GND" V 1200 1450 50  0000 C CNN
F 2 "" H 1200 1650 60  0000 C CNN
F 3 "" H 1200 1650 60  0000 C CNN
	1    1200 1650
	0    1    1    0   
$EndComp
$Comp
L GND #PWR4
U 1 1 566649FD
P 1200 2550
F 0 "#PWR4" H 1200 2300 50  0001 C CNN
F 1 "GND" V 1200 2350 50  0000 C CNN
F 2 "" H 1200 2550 60  0000 C CNN
F 3 "" H 1200 2550 60  0000 C CNN
	1    1200 2550
	0    1    1    0   
$EndComp
$Comp
L GND #PWR5
U 1 1 56665054
P 1200 3850
F 0 "#PWR5" H 1200 3600 50  0001 C CNN
F 1 "GND" V 1200 3650 50  0000 C CNN
F 2 "" H 1200 3850 60  0000 C CNN
F 3 "" H 1200 3850 60  0000 C CNN
	1    1200 3850
	0    1    1    0   
$EndComp
$Comp
L GND #PWR8
U 1 1 56665BA5
P 1700 3850
F 0 "#PWR8" H 1700 3600 50  0001 C CNN
F 1 "GND" V 1700 3650 50  0000 C CNN
F 2 "" H 1700 3850 60  0000 C CNN
F 3 "" H 1700 3850 60  0000 C CNN
	1    1700 3850
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR13
U 1 1 56666438
P 3650 1450
F 0 "#PWR13" H 3650 1200 50  0001 C CNN
F 1 "GND" V 3650 1250 50  0000 C CNN
F 2 "" H 3650 1450 60  0000 C CNN
F 3 "" H 3650 1450 60  0000 C CNN
	1    3650 1450
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR9
U 1 1 56666B45
P 3150 1450
F 0 "#PWR9" H 3150 1200 50  0001 C CNN
F 1 "GND" V 3150 1250 50  0000 C CNN
F 2 "" H 3150 1450 60  0000 C CNN
F 3 "" H 3150 1450 60  0000 C CNN
	1    3150 1450
	0    1    1    0   
$EndComp
$Comp
L GND #PWR17
U 1 1 56667559
P 3650 3850
F 0 "#PWR17" H 3650 3600 50  0001 C CNN
F 1 "GND" V 3650 3650 50  0000 C CNN
F 2 "" H 3650 3850 60  0000 C CNN
F 3 "" H 3650 3850 60  0000 C CNN
	1    3650 3850
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR12
U 1 1 56667822
P 3150 3850
F 0 "#PWR12" H 3150 3600 50  0001 C CNN
F 1 "GND" V 3150 3650 50  0000 C CNN
F 2 "" H 3150 3850 60  0000 C CNN
F 3 "" H 3150 3850 60  0000 C CNN
	1    3150 3850
	0    1    1    0   
$EndComp
$Comp
L +3.3V #PWR27
U 1 1 56668F37
P 4150 4300
F 0 "#PWR27" H 4150 4150 50  0001 C CNN
F 1 "+3.3V" H 4150 4440 50  0000 C CNN
F 2 "" H 4150 4300 60  0000 C CNN
F 3 "" H 4150 4300 60  0000 C CNN
	1    4150 4300
	1    0    0    -1  
$EndComp
Text GLabel 5150 4100 0    60   Input ~ 0
CS_11
Text GLabel 5150 4200 0    60   Input ~ 0
CS_10
Text GLabel 5150 4300 0    60   Input ~ 0
CS_9
Text GLabel 5150 4400 0    60   Input ~ 0
CS_8
Text GLabel 5150 4500 0    60   Input ~ 0
CS_7
Text GLabel 5150 4600 0    60   Input ~ 0
CS_6
Text GLabel 5150 4700 0    60   Input ~ 0
CS_5
Text GLabel 5150 4800 0    60   Input ~ 0
CS_4
Text GLabel 5150 4900 0    60   Input ~ 0
CS_3
Text GLabel 5150 5000 0    60   Input ~ 0
CS_2
Text GLabel 5150 5100 0    60   Input ~ 0
CS_1
Text GLabel 5150 5200 0    60   Input ~ 0
CS_0
$Comp
L CONN_01X03 P?
U 1 1 5675D5BE
P 2300 6300
F 0 "P?" H 2300 6500 50  0000 C CNN
F 1 "CONN_01X03" V 2400 6300 50  0000 C CNN
F 2 "" H 2300 6300 60  0000 C CNN
F 3 "" H 2300 6300 60  0000 C CNN
	1    2300 6300
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 5675D90D
P 2300 7100
F 0 "P?" H 2300 7300 50  0000 C CNN
F 1 "CONN_01X03" V 2400 7100 50  0000 C CNN
F 2 "" H 2300 7100 60  0000 C CNN
F 3 "" H 2300 7100 60  0000 C CNN
	1    2300 7100
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 5675DCE4
P 5050 5750
F 0 "P?" H 5050 5950 50  0000 C CNN
F 1 "CONN_01X03" V 5150 5750 50  0000 C CNN
F 2 "" H 5050 5750 60  0000 C CNN
F 3 "" H 5050 5750 60  0000 C CNN
	1    5050 5750
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 5675E16B
P 5050 6900
F 0 "P?" H 5050 7100 50  0000 C CNN
F 1 "CONN_01X03" V 5150 6900 50  0000 C CNN
F 2 "" H 5050 6900 60  0000 C CNN
F 3 "" H 5050 6900 60  0000 C CNN
	1    5050 6900
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 P?
U 1 1 5675E81E
P 8450 1150
F 0 "P?" H 8450 1350 50  0000 C CNN
F 1 "CONN_01X03" V 8550 1150 50  0000 C CNN
F 2 "" H 8450 1150 60  0000 C CNN
F 3 "" H 8450 1150 60  0000 C CNN
	1    8450 1150
	0    -1   -1   0   
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 56789C4B
P 10100 1550
F 0 "Q?" H 10400 1600 50  0000 R CNN
F 1 "NMOS" H 10500 1500 50  0000 R CNN
F 2 "" H 10300 1650 29  0000 C CNN
F 3 "" H 10100 1550 60  0000 C CNN
	1    10100 1550
	-1   0    0    -1  
$EndComp
Connection ~ 9300 1750
Wire Wire Line
	9600 1150 10000 1150
Wire Wire Line
	10000 950  10000 1150
Wire Wire Line
	10000 1150 10000 1350
$Comp
L R R?
U 1 1 5678B128
P 9600 950
F 0 "R?" V 9680 950 50  0000 C CNN
F 1 "1k" V 9600 950 50  0000 C CNN
F 2 "" V 9530 950 30  0000 C CNN
F 3 "" H 9600 950 30  0000 C CNN
	1    9600 950 
	0    1    1    0   
$EndComp
Connection ~ 9300 950 
Wire Wire Line
	9750 950  10000 950 
Connection ~ 10000 1150
Wire Wire Line
	10300 1300 9600 1300
Wire Wire Line
	9600 1300 9600 1550
$Comp
L Q_NMOS_DGS Q?
U 1 1 5678CE18
P 7500 1550
F 0 "Q?" H 7800 1600 50  0000 R CNN
F 1 "NMOS" H 7900 1500 50  0000 R CNN
F 2 "" H 7700 1650 29  0000 C CNN
F 3 "" H 7500 1550 60  0000 C CNN
	1    7500 1550
	1    0    0    -1  
$EndComp
$Comp
L Q_PMOS_DGS Q?
U 1 1 5678CE1F
P 7500 1150
F 0 "Q?" H 7800 1200 50  0000 R CNN
F 1 "PMOS" H 7900 1100 50  0000 R CNN
F 2 "" H 7700 1250 29  0000 C CNN
F 3 "" H 7500 1150 60  0000 C CNN
	1    7500 1150
	1    0    0    -1  
$EndComp
$Comp
L Q_NMOS_DGS Q?
U 1 1 5678CE28
P 6800 1550
F 0 "Q?" H 7100 1600 50  0000 R CNN
F 1 "NMOS" H 7200 1500 50  0000 R CNN
F 2 "" H 7000 1650 29  0000 C CNN
F 3 "" H 6800 1550 60  0000 C CNN
	1    6800 1550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7300 1150 6900 1150
Wire Wire Line
	6900 950  6900 1150
Wire Wire Line
	6900 1150 6900 1350
$Comp
L R R?
U 1 1 5678CE30
P 7300 950
F 0 "R?" V 7380 950 50  0000 C CNN
F 1 "1k" V 7300 950 50  0000 C CNN
F 2 "" V 7230 950 30  0000 C CNN
F 3 "" H 7300 950 30  0000 C CNN
	1    7300 950 
	0    -1   1    0   
$EndComp
Wire Wire Line
	7150 950  6900 950 
Connection ~ 6900 1150
Wire Wire Line
	6650 1300 7300 1300
Wire Wire Line
	7300 1300 7300 1550
Connection ~ 7600 950 
Connection ~ 7600 1750
Wire Wire Line
	6600 1550 6600 1550
$EndSCHEMATC
