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
LIBS:Humidity-cache
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
L Conn_01x04_Female J1
U 1 1 5AC535F7
P 3000 1600
F 0 "J1" H 3000 1800 50  0000 C CNN
F 1 "VCC_S" H 3000 1300 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 3000 1600 50  0001 C CNN
F 3 "" H 3000 1600 50  0001 C CNN
	1    3000 1600
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x04_Female J3
U 1 1 5AC53666
P 4400 1600
F 0 "J3" H 4400 1800 50  0000 C CNN
F 1 "GND_S" H 4400 1300 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x04_Pitch2.54mm" H 4400 1600 50  0001 C CNN
F 3 "" H 4400 1600 50  0001 C CNN
	1    4400 1600
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x02_Female J2
U 1 1 5AC536F6
P 3800 3350
F 0 "J2" H 3800 3450 50  0000 C CNN
F 1 "VCC/GND" H 3800 3150 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x02_Pitch2.54mm" H 3800 3350 50  0001 C CNN
F 3 "" H 3800 3350 50  0001 C CNN
	1    3800 3350
	0    1    1    0   
$EndComp
Wire Wire Line
	4600 3150 4600 1800
Wire Wire Line
	4500 3150 4500 1800
Connection ~ 4500 3150
Wire Wire Line
	4400 3150 4400 1800
Connection ~ 4400 3150
Wire Wire Line
	4300 3150 4300 1800
Connection ~ 4300 3150
Wire Wire Line
	2900 3150 2900 1800
Wire Wire Line
	3000 1800 3000 3150
Connection ~ 3000 3150
Wire Wire Line
	3100 1800 3100 3150
Connection ~ 3100 3150
Wire Wire Line
	3200 1800 3200 3150
Connection ~ 3200 3150
$Comp
L PWR_FLAG #FLG01
U 1 1 5AC537B3
P 3350 3150
F 0 "#FLG01" H 3350 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 3350 3300 50  0000 C CNN
F 2 "" H 3350 3150 50  0001 C CNN
F 3 "" H 3350 3150 50  0001 C CNN
	1    3350 3150
	-1   0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG02
U 1 1 5AC537CD
P 4100 3150
F 0 "#FLG02" H 4100 3225 50  0001 C CNN
F 1 "PWR_FLAG" H 4100 3300 50  0000 C CNN
F 2 "" H 4100 3150 50  0001 C CNN
F 3 "" H 4100 3150 50  0001 C CNN
	1    4100 3150
	-1   0    0    1   
$EndComp
Wire Wire Line
	2900 3150 3700 3150
Connection ~ 3350 3150
Wire Wire Line
	3800 3150 4600 3150
Connection ~ 4100 3150
$EndSCHEMATC
