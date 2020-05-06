EESchema Schematic File Version 4
EELAYER 30 0
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
L Device:Microphone MK1
U 1 1 5EB245CF
P 1830 2620
F 0 "MK1" H 1960 2666 50  0000 L CNN
F 1 "MIC" H 1960 2575 50  0000 L CNN
F 2 "" V 1830 2720 50  0001 C CNN
F 3 "~" V 1830 2720 50  0001 C CNN
	1    1830 2620
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5EB2537B
P 1830 2320
F 0 "R1" H 1889 2366 50  0000 L CNN
F 1 "10k" H 1889 2275 50  0000 L CNN
F 2 "" H 1830 2320 50  0001 C CNN
F 3 "~" H 1830 2320 50  0001 C CNN
	1    1830 2320
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C1
U 1 1 5EB25AD7
P 2540 2420
F 0 "C1" V 2768 2420 50  0000 C CNN
F 1 "10uf" V 2677 2420 50  0000 C CNN
F 2 "" H 2540 2420 50  0001 C CNN
F 3 "~" H 2540 2420 50  0001 C CNN
	1    2540 2420
	0    -1   -1   0   
$EndComp
$Comp
L Device:Q_NPN_BEC Q1
U 1 1 5EB26D32
P 2840 2420
F 0 "Q1" H 3031 2466 50  0000 L CNN
F 1 "NPN" H 3031 2375 50  0000 L CNN
F 2 "" H 3040 2520 50  0001 C CNN
F 3 "~" H 2840 2420 50  0001 C CNN
	1    2840 2420
	1    0    0    -1  
$EndComp
Wire Wire Line
	2440 2420 1830 2420
Connection ~ 1830 2420
Wire Wire Line
	2640 2420 2640 2220
Wire Wire Line
	2640 2220 2660 2220
$Comp
L Device:R_Small R2
U 1 1 5EB2A582
P 2760 2220
F 0 "R2" V 2564 2220 50  0000 C CNN
F 1 "100k" V 2655 2220 50  0000 C CNN
F 2 "" H 2760 2220 50  0001 C CNN
F 3 "~" H 2760 2220 50  0001 C CNN
	1    2760 2220
	0    1    1    0   
$EndComp
Wire Wire Line
	2940 2220 2860 2220
Connection ~ 2640 2420
$Comp
L Device:R_Small R4
U 1 1 5EB2B017
P 2940 2720
F 0 "R4" H 2999 2766 50  0000 L CNN
F 1 "1k" H 2999 2675 50  0000 L CNN
F 2 "" H 2940 2720 50  0001 C CNN
F 3 "~" H 2940 2720 50  0001 C CNN
	1    2940 2720
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5EB2B7BB
P 2940 2820
F 0 "#PWR0101" H 2940 2570 50  0001 C CNN
F 1 "GND" H 2945 2647 50  0000 C CNN
F 2 "" H 2940 2820 50  0001 C CNN
F 3 "" H 2940 2820 50  0001 C CNN
	1    2940 2820
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5EB2BBD1
P 1830 2820
F 0 "#PWR0102" H 1830 2570 50  0001 C CNN
F 1 "GND" H 1835 2647 50  0000 C CNN
F 2 "" H 1830 2820 50  0001 C CNN
F 3 "" H 1830 2820 50  0001 C CNN
	1    1830 2820
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R3
U 1 1 5EB2C146
P 2940 2030
F 0 "R3" H 2999 2076 50  0000 L CNN
F 1 "10k" H 2999 1985 50  0000 L CNN
F 2 "" H 2940 2030 50  0001 C CNN
F 3 "~" H 2940 2030 50  0001 C CNN
	1    2940 2030
	1    0    0    -1  
$EndComp
Wire Wire Line
	2940 2220 2940 2130
Wire Wire Line
	2940 1930 1830 1930
Wire Wire Line
	1830 1930 1830 2220
$Comp
L Connector:TestPoint TP1
U 1 1 5EB2D6D6
P 3640 2220
F 0 "TP1" V 3594 2408 50  0000 L CNN
F 1 "OUTPUT" V 3685 2408 50  0000 L CNN
F 2 "" H 3840 2220 50  0001 C CNN
F 3 "~" H 3840 2220 50  0001 C CNN
	1    3640 2220
	0    1    1    0   
$EndComp
Wire Wire Line
	2940 2220 3640 2220
Connection ~ 2940 2220
$Comp
L power:+5V #PWR0103
U 1 1 5EB2E0D5
P 1830 1930
F 0 "#PWR0103" H 1830 1780 50  0001 C CNN
F 1 "+5V" H 1845 2103 50  0000 C CNN
F 2 "" H 1830 1930 50  0001 C CNN
F 3 "" H 1830 1930 50  0001 C CNN
	1    1830 1930
	1    0    0    -1  
$EndComp
Connection ~ 1830 1930
$EndSCHEMATC
