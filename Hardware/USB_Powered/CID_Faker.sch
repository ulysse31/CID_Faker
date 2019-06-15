EESchema Schematic File Version 4
EELAYER 29 0
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
Text GLabel 3600 1300 1    60   Input ~ 0
MISO
Text GLabel 3700 1300 1    60   Input ~ 0
MOSI
Text GLabel 3500 1300 1    60   Input ~ 0
CS
Text GLabel 3400 1300 1    60   Input ~ 0
GND
Text GLabel 3300 1300 1    60   Input ~ 0
VCC
Text GLabel 4300 2400 2    60   Input ~ 0
VCC
Text GLabel 3900 1300 1    60   Input ~ 0
INT
Text GLabel 3800 1300 1    60   Input ~ 0
SCK
Text GLabel 4300 2900 2    60   Input ~ 0
SCK
Text GLabel 4300 3000 2    60   Input ~ 0
MISO
Text GLabel 4300 3100 2    60   Input ~ 0
MOSI
Text GLabel 2900 2800 0    60   Input ~ 0
CS
Text GLabel 2900 2500 0    60   Input ~ 0
INT
NoConn ~ 4300 2800
NoConn ~ 4300 2700
NoConn ~ 4300 2600
NoConn ~ 4300 2500
NoConn ~ 4300 2300
NoConn ~ 2900 2200
NoConn ~ 2900 2100
NoConn ~ 2900 2700
NoConn ~ 2900 2600
NoConn ~ 2900 2900
NoConn ~ 2900 3000
NoConn ~ 2900 3100
NoConn ~ 2900 3200
NoConn ~ 4300 3200
NoConn ~ 4300 2100
$Comp
L promicro:ProMicro U1
U 1 1 5CFEB39A
P 3600 2850
F 0 "U1" H 3600 3887 60  0000 C CNN
F 1 "ProMicro" H 3600 3781 60  0000 C CNN
F 2 "promicro:ProMicro" H 3700 1800 60  0001 C CNN
F 3 "" H 3700 1800 60  0000 C CNN
	1    3600 2850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x07_Female J1
U 1 1 5CFEC3BA
P 3600 1500
F 0 "J1" V 3673 1480 50  0000 C CNN
F 1 "CAN1" V 3764 1480 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x07_P2.54mm_Vertical" H 3600 1500 50  0001 C CNN
F 3 "~" H 3600 1500 50  0001 C CNN
	1    3600 1500
	0    1    1    0   
$EndComp
Text GLabel 2900 2400 0    50   Input ~ 0
GND
Text GLabel 2900 2300 0    50   Input ~ 0
GND
NoConn ~ 4300 2200
$EndSCHEMATC
