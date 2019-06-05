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
LIBS:promicro
LIBS:Connector
LIBS:Connector_Generic
LIBS:Interface_CAN_LIN
LIBS:MCU_AnalogDevices
LIBS:MCU_Microchip_ATmega
LIBS:MCU_Microchip_ATtiny
LIBS:MCU_Microchip_AVR
LIBS:MCU_Module
LIBS:MCU_ST_STM32F1
LIBS:MCU_ST_STM32F3
LIBS:Reference_Voltage
LIBS:Regulator_Linear
LIBS:references
LIBS:sensors
LIBS:stm32
LIBS:CID_Faker-cache
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
L ProMicro U1
U 1 1 5CEFF4F8
P 3600 2850
F 0 "U1" H 3600 3800 60  0000 C CNN
F 1 "ProMicro" H 3600 2300 60  0000 C CNN
F 2 "promicro:ProMicro" H 3700 1800 60  0001 C CNN
F 3 "" H 3700 1800 60  0000 C CNN
	1    3600 2850
	1    0    0    -1  
$EndComp
Text GLabel 5250 3100 0    60   Input ~ 0
GND
Text GLabel 5250 3000 0    60   Input ~ 0
VIN
Text GLabel 3600 1300 1    60   Input ~ 0
MISO
Text GLabel 3700 1300 1    60   Input ~ 0
MOSI
$Comp
L Conn_01x02_Male J1
U 1 1 5CEFFD1E
P 5450 3100
F 0 "J1" H 5450 3200 50  0000 C CNN
F 1 "PWR" H 5450 2900 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Angled_1x02_Pitch2.54mm" H 5450 3100 50  0001 C CNN
F 3 "" H 5450 3100 50  0001 C CNN
	1    5450 3100
	-1   0    0    1   
$EndComp
$Comp
L Conn_01x07_Female J2
U 1 1 5CEFFEED
P 3600 1500
F 0 "J2" H 3600 1900 50  0000 C CNN
F 1 "CAN" H 3600 1100 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x07_Pitch2.54mm" H 3600 1500 50  0001 C CNN
F 3 "" H 3600 1500 50  0001 C CNN
	1    3600 1500
	0    1    1    0   
$EndComp
Text GLabel 3500 1300 1    60   Input ~ 0
CS
Text GLabel 3400 1300 1    60   Input ~ 0
GND
Text GLabel 3300 1300 1    60   Input ~ 0
VCC
Text GLabel 4300 2400 2    60   Input ~ 0
VCC
Text GLabel 4300 2200 2    60   Input ~ 0
GND
Text GLabel 4600 1650 0    60   Input ~ 0
VIN
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
Text GLabel 2900 2400 0    60   Input ~ 0
GND
Text GLabel 2900 2300 0    60   Input ~ 0
GND
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
$Comp
L LF80_TO220 U2
U 1 1 5CF0100D
P 4900 1650
F 0 "U2" H 4750 1775 50  0000 C CNN
F 1 "LF80_TO220" H 4900 1775 50  0000 L CNN
F 2 "Power_Integrations:TO-220" H 4900 1875 50  0001 C CIN
F 3 "" H 4900 1600 50  0001 C CNN
	1    4900 1650
	1    0    0    -1  
$EndComp
Text GLabel 4300 2100 2    60   Input ~ 0
RAW
Text GLabel 5200 1650 2    60   Input ~ 0
RAW
Text GLabel 4900 1950 3    60   Input ~ 0
GND
$EndSCHEMATC
