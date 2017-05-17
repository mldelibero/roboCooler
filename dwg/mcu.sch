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
L STM32F407VGTx U?
U 1 1 591CDE4B
P 5700 3750
F 0 "U?" H 1400 6575 50  0000 L BNN
F 1 "STM32F407VGTx" H 10000 6575 50  0000 R BNN
F 2 "LQFP100" H 10000 6525 50  0001 R TNN
F 3 "" H 5700 3750 50  0001 C CNN
	1    5700 3750
	1    0    0    -1  
$EndComp
Text HLabel 10200 4750 2    60   Input ~ 0
LED_0
Text HLabel 10200 1350 2    60   Input ~ 0
LED_1
Text HLabel 10200 1550 2    60   Input ~ 0
LED_2
Text HLabel 10200 1950 2    60   Input ~ 0
LED_3
Text HLabel 10200 5150 2    60   Input ~ 0
LED_4
Text HLabel 10200 3050 2    60   Input ~ 0
LED_5
Text HLabel 1200 3650 0    60   Input ~ 0
LED_6
Text HLabel 1200 3850 0    60   Input ~ 0
LED_7
Text HLabel 10200 1450 2    60   Input ~ 0
LED_UART
Text HLabel 1200 3550 0    60   Input ~ 0
HAL_1
Text HLabel 1200 3350 0    60   Input ~ 0
HAL_2
Text HLabel 1200 3450 0    60   Input ~ 0
PUSH_1
Text HLabel 10200 5950 2    60   Input ~ 0
PUSH_2
Text HLabel 1200 3150 0    60   Input ~ 0
CS_IRQ
Text HLabel 10200 3750 2    60   Input ~ 0
CS_SCL
Text HLabel 10200 3650 2    60   Input ~ 0
CS_SDA
Text HLabel 1200 4850 0    60   Input ~ 0
MOTOR_SB
Text HLabel 1200 4650 0    60   Input ~ 0
MOTOR_FWD
Text HLabel 10200 5750 2    60   Input ~ 0
MOTOR_REV
Text HLabel 10200 2050 2    60   Input ~ 0
MOTOR_PWM
Text HLabel 10200 5250 2    60   Input ~ 0
FAN_PWM
Text HLabel 10200 5550 2    60   Input ~ 0
PUMP_PWM
$Comp
L C_Small C?
U 1 1 591EE19D
P 1050 1550
F 0 "C?" H 1060 1620 50  0000 L CNN
F 1 "0.1uF" H 1060 1470 50  0000 L CNN
F 2 "Capacitors_SMD:C_0805_HandSoldering" H 1050 1550 50  0001 C CNN
F 3 "" H 1050 1550 50  0001 C CNN
	1    1050 1550
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 591EE235
P 850 1850
F 0 "#PWR?" H 850 1600 50  0001 C CNN
F 1 "GND" H 850 1700 50  0000 C CNN
F 2 "" H 850 1850 50  0001 C CNN
F 3 "" H 850 1850 50  0001 C CNN
	1    850  1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	650  1250 1200 1250
$Comp
L SW_PUSH SW?
U 1 1 591EE4D9
P 650 1550
F 0 "SW?" H 800 1660 50  0000 C CNN
F 1 "SW_PUSH" H 650 1470 50  0000 C CNN
F 2 "" H 650 1550 50  0000 C CNN
F 3 "" H 650 1550 50  0000 C CNN
	1    650  1550
	0    -1   -1   0   
$EndComp
Connection ~ 1050 1250
Wire Wire Line
	1050 1450 1050 1250
Wire Wire Line
	1050 1850 1050 1650
Wire Wire Line
	650  1850 1050 1850
Connection ~ 850  1850
$EndSCHEMATC
