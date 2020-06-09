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
Wire Wire Line
	2100 3640 2100 3900
Wire Wire Line
	950  3650 950  4050
Connection ~ 2100 4190
Wire Wire Line
	2100 4190 2300 4190
Wire Wire Line
	2870 4390 2870 4600
Wire Wire Line
	2500 3990 2500 4190
Wire Wire Line
	2590 3990 2500 3990
Connection ~ 2500 4190
Wire Wire Line
	2500 4190 2570 4190
Wire Wire Line
	2870 3650 2870 3700
$Comp
L power:+5V #PWR02
U 1 1 5EB3F4D9
P 2870 3650
F 0 "#PWR02" H 2870 3500 50  0001 C CNN
F 1 "+5V" H 2885 3823 50  0000 C CNN
F 2 "" H 2870 3650 50  0001 C CNN
F 3 "" H 2870 3650 50  0001 C CNN
	1    2870 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R5
U 1 1 5EB3F4B3
P 2690 3990
F 0 "R5" V 2840 4030 50  0000 L CNN
F 1 "100k" V 2770 3940 50  0000 L CNN
F 2 "" H 2690 3990 50  0001 C CNN
F 3 "~" H 2690 3990 50  0001 C CNN
	1    2690 3990
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5EB3F4AC
P 2870 4700
F 0 "R7" H 2929 4746 50  0000 L CNN
F 1 "1k" H 2929 4655 50  0000 L CNN
F 2 "" H 2870 4700 50  0001 C CNN
F 3 "~" H 2870 4700 50  0001 C CNN
	1    2870 4700
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BEC Q2
U 1 1 5EB3F4A6
P 2770 4190
F 0 "Q2" H 2961 4236 50  0000 L CNN
F 1 "NPN" H 2961 4145 50  0000 L CNN
F 2 "" H 2970 4290 50  0001 C CNN
F 3 "~" H 2770 4190 50  0001 C CNN
	1    2770 4190
	1    0    0    -1  
$EndComp
Wire Wire Line
	2870 3990 3170 3990
$Comp
L Device:CP1_Small C3
U 1 1 5EB3F49E
P 3270 3990
F 0 "C3" V 3498 3990 50  0000 C CNN
F 1 "10uf" V 3407 3990 50  0000 C CNN
F 2 "" H 3270 3990 50  0001 C CNN
F 3 "~" H 3270 3990 50  0001 C CNN
	1    3270 3990
	0    -1   -1   0   
$EndComp
Connection ~ 2870 3990
Wire Wire Line
	2870 3990 2870 3900
$Comp
L Device:R_Small R6
U 1 1 5EB3F490
P 2870 3800
F 0 "R6" H 2929 3846 50  0000 L CNN
F 1 "10k" H 2929 3755 50  0000 L CNN
F 2 "" H 2870 3800 50  0001 C CNN
F 3 "~" H 2870 3800 50  0001 C CNN
	1    2870 3800
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR03
U 1 1 5EB3F48A
P 2870 4800
F 0 "#PWR03" H 2870 4550 50  0001 C CNN
F 1 "GND" H 2875 4627 50  0000 C CNN
F 2 "" H 2870 4800 50  0001 C CNN
F 3 "" H 2870 4800 50  0001 C CNN
	1    2870 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	2870 3990 2790 3990
$Comp
L power:+5V #PWR01
U 1 1 5EB466B9
P 2100 3640
F 0 "#PWR01" H 2100 3490 50  0001 C CNN
F 1 "+5V" H 2115 3813 50  0000 C CNN
F 2 "" H 2100 3640 50  0001 C CNN
F 3 "" H 2100 3640 50  0001 C CNN
	1    2100 3640
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  4390 950  4400
Connection ~ 950  4390
Wire Wire Line
	1280 4390 950  4390
$Comp
L power:GND #PWR0102
U 1 1 5EB2BBD1
P 950 4800
F 0 "#PWR0102" H 950 4550 50  0001 C CNN
F 1 "GND" H 955 4627 50  0000 C CNN
F 2 "" H 950 4800 50  0001 C CNN
F 3 "" H 950 4800 50  0001 C CNN
	1    950  4800
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5EB2E0D5
P 950 3650
F 0 "#PWR0103" H 950 3500 50  0001 C CNN
F 1 "+5V" H 965 3823 50  0000 C CNN
F 2 "" H 950 3650 50  0001 C CNN
F 3 "" H 950 3650 50  0001 C CNN
	1    950  3650
	1    0    0    -1  
$EndComp
$Comp
L Device:Microphone MK1
U 1 1 5EB245CF
P 950 4600
F 0 "MK1" H 1080 4646 50  0000 L CNN
F 1 "MIC" H 1080 4555 50  0000 L CNN
F 2 "" V 950 4700 50  0001 C CNN
F 3 "~" V 950 4700 50  0001 C CNN
	1    950  4600
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5EB3EDFD
P 950 4150
F 0 "R1" H 1009 4196 50  0000 L CNN
F 1 "6.8k" H 1009 4105 50  0000 L CNN
F 2 "" H 950 4150 50  0001 C CNN
F 3 "~" H 950 4150 50  0001 C CNN
	1    950  4150
	-1   0    0    1   
$EndComp
Wire Wire Line
	950  4250 950  4390
Connection ~ 1600 4390
Wire Wire Line
	1600 4390 1800 4390
Wire Wire Line
	1600 4190 1600 4390
Wire Wire Line
	1820 4190 1600 4190
$Comp
L Device:R_Small R2
U 1 1 5EB41476
P 1920 4190
F 0 "R2" V 2070 4230 50  0000 L CNN
F 1 "100k" V 2000 4140 50  0000 L CNN
F 2 "" H 1920 4190 50  0001 C CNN
F 3 "~" H 1920 4190 50  0001 C CNN
	1    1920 4190
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1480 4390 1600 4390
$Comp
L Device:R_Small R4
U 1 1 5EB3FFDB
P 2100 4690
F 0 "R4" H 2159 4736 50  0000 L CNN
F 1 "1k" H 2159 4645 50  0000 L CNN
F 2 "" H 2100 4690 50  0001 C CNN
F 3 "~" H 2100 4690 50  0001 C CNN
	1    2100 4690
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C2
U 1 1 5EB248DC
P 2400 4190
F 0 "C2" V 2628 4190 50  0000 C CNN
F 1 "10uf" V 2537 4190 50  0000 C CNN
F 2 "" H 2400 4190 50  0001 C CNN
F 3 "~" H 2400 4190 50  0001 C CNN
	1    2400 4190
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2100 4190 2100 4100
$Comp
L Device:R_Small R3
U 1 1 5EB2C146
P 2100 4000
F 0 "R3" H 2159 4046 50  0000 L CNN
F 1 "10k" H 2159 3955 50  0000 L CNN
F 2 "" H 2100 4000 50  0001 C CNN
F 3 "~" H 2100 4000 50  0001 C CNN
	1    2100 4000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 5EB2B7BB
P 2100 4790
F 0 "#PWR0101" H 2100 4540 50  0001 C CNN
F 1 "GND" H 2105 4617 50  0000 C CNN
F 2 "" H 2100 4790 50  0001 C CNN
F 3 "" H 2100 4790 50  0001 C CNN
	1    2100 4790
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 4190 2020 4190
$Comp
L Device:CP1_Small C1
U 1 1 5EB25AD7
P 1380 4390
F 0 "C1" V 1608 4390 50  0000 C CNN
F 1 "10uf" V 1517 4390 50  0000 C CNN
F 2 "" H 1380 4390 50  0001 C CNN
F 3 "~" H 1380 4390 50  0001 C CNN
	1    1380 4390
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3370 3990 4250 3990
Text Label 4250 3990 2    50   ~ 0
MIC_IN
$Comp
L Regulator_Linear:AP2204K-ADJ U2
U 1 1 5EC19F82
P 3840 2350
F 0 "U2" H 3840 2692 50  0000 C CNN
F 1 "NCP718A" H 3840 2601 50  0000 C CNN
F 2 "Footprints:SON65P200X200X80-7N" H 3840 2675 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCP718-D.PDF" H 3840 2450 50  0001 C CNN
	1    3840 2350
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C6
U 1 1 5EBF422C
P 950 2690
F 0 "C6" H 800 2730 50  0000 C CNN
F 1 "100pf" H 770 2650 50  0000 C CNN
F 2 "" H 950 2690 50  0001 C CNN
F 3 "~" H 950 2690 50  0001 C CNN
	1    950  2690
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C7
U 1 1 5EBF45B7
P 2550 2890
F 0 "C7" H 2400 2930 50  0000 C CNN
F 1 "470uf" H 2370 2850 50  0000 C CNN
F 2 "" H 2550 2890 50  0001 C CNN
F 3 "~" H 2550 2890 50  0001 C CNN
	1    2550 2890
	1    0    0    -1  
$EndComp
$Comp
L Regulator_Switching:MC33063AD U1
U 1 1 5EC189CB
P 1450 2390
F 0 "U1" H 1480 3010 50  0000 C CNN
F 1 "MC33063AD" H 1470 2910 50  0000 C CNN
F 2 "Package_SO:SOIC-8_3.9x4.9mm_P1.27mm" H 1500 1940 50  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/mc33063a.pdf?HQS=TI-null-null-digikeymode-df-pf-null-wwe&ts=1589576128690" H 1950 2290 50  0001 C CNN
	1    1450 2390
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5EC0E35A
P 1850 2890
F 0 "R8" H 1910 2920 50  0000 L CNN
F 1 "3k" H 1900 2850 50  0000 L CNN
F 2 "" H 1850 2890 50  0001 C CNN
F 3 "~" H 1850 2890 50  0001 C CNN
	1    1850 2890
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R11
U 1 1 5EC0F8F1
P 2210 2790
F 0 "R11" V 2080 2730 50  0000 L CNN
F 1 "24k" V 2140 2740 50  0000 L CNN
F 2 "" H 2210 2790 50  0001 C CNN
F 3 "~" H 2210 2790 50  0001 C CNN
	1    2210 2790
	0    1    1    0   
$EndComp
Wire Wire Line
	940  2190 1050 2190
Wire Wire Line
	1050 2590 950  2590
$Comp
L power:GND #PWR05
U 1 1 5EC1C77E
P 940 2390
F 0 "#PWR05" H 940 2140 50  0001 C CNN
F 1 "GND" H 940 2250 50  0000 C CNN
F 2 "" H 940 2390 50  0001 C CNN
F 3 "" H 940 2390 50  0001 C CNN
	1    940  2390
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR06
U 1 1 5EC1CBD7
P 950 2990
F 0 "#PWR06" H 950 2740 50  0001 C CNN
F 1 "GND" H 950 2840 50  0000 C CNN
F 2 "" H 950 2990 50  0001 C CNN
F 3 "" H 950 2990 50  0001 C CNN
	1    950  2990
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R10
U 1 1 5EBF3B2A
P 2060 2290
F 0 "R10" V 2020 2070 50  0000 L CNN
F 1 "180" V 2100 2060 50  0000 L CNN
F 2 "" H 2060 2290 50  0001 C CNN
F 3 "~" H 2060 2290 50  0001 C CNN
	1    2060 2290
	0    1    1    0   
$EndComp
Wire Wire Line
	1850 2290 1960 2290
Wire Wire Line
	1850 2190 1960 2190
Wire Wire Line
	2160 2190 2160 1990
Wire Wire Line
	2160 1990 940  1990
Connection ~ 940  2190
$Comp
L Device:L_Core_Iron L1
U 1 1 5EBF2278
P 2400 2290
F 0 "L1" V 2625 2290 50  0000 C CNN
F 1 "23uh" V 2534 2290 50  0000 C CNN
F 2 "" H 2400 2290 50  0001 C CNN
F 3 "~" H 2400 2290 50  0001 C CNN
	1    2400 2290
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2160 2290 2250 2290
Connection ~ 2250 2290
$Comp
L Device:D_Zener D1
U 1 1 5EBF58AF
P 2550 2540
F 0 "D1" V 2596 2461 50  0000 R CNN
F 1 "1N5819" V 2505 2461 50  0000 R CNN
F 2 "" H 2550 2540 50  0001 C CNN
F 3 "~" H 2550 2540 50  0001 C CNN
	1    2550 2540
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2550 2290 2550 2390
Wire Wire Line
	1850 2390 2550 2390
Connection ~ 2550 2390
$Comp
L power:GND #PWR07
U 1 1 5EC10D2A
P 1450 2990
F 0 "#PWR07" H 1450 2740 50  0001 C CNN
F 1 "GND" H 1455 2817 50  0000 C CNN
F 2 "" H 1450 2990 50  0001 C CNN
F 3 "" H 1450 2990 50  0001 C CNN
	1    1450 2990
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR09
U 1 1 5EC3117A
P 1960 2590
F 0 "#PWR09" H 1960 2340 50  0001 C CNN
F 1 "GND" H 1960 2450 50  0000 C CNN
F 2 "" H 1960 2590 50  0001 C CNN
F 3 "" H 1960 2590 50  0001 C CNN
	1    1960 2590
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 2590 1960 2590
Wire Wire Line
	1850 2690 1850 2790
Wire Wire Line
	2550 2690 2550 2790
$Comp
L power:GND #PWR010
U 1 1 5EC3F85A
P 2550 2990
F 0 "#PWR010" H 2550 2740 50  0001 C CNN
F 1 "GND" H 2555 2817 50  0000 C CNN
F 2 "" H 2550 2990 50  0001 C CNN
F 3 "" H 2550 2990 50  0001 C CNN
	1    2550 2990
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR08
U 1 1 5EC40663
P 1850 2990
F 0 "#PWR08" H 1850 2740 50  0001 C CNN
F 1 "GND" H 1855 2817 50  0000 C CNN
F 2 "" H 1850 2990 50  0001 C CNN
F 3 "" H 1850 2990 50  0001 C CNN
	1    1850 2990
	1    0    0    -1  
$EndComp
Wire Wire Line
	2110 2790 1850 2790
Connection ~ 1850 2790
Wire Wire Line
	2310 2790 2550 2790
$Comp
L power:+BATT #PWR04
U 1 1 5EC45A84
P 940 1780
F 0 "#PWR04" H 940 1630 50  0001 C CNN
F 1 "+BATT" H 940 1950 50  0000 C CNN
F 2 "" H 940 1780 50  0001 C CNN
F 3 "" H 940 1780 50  0001 C CNN
	1    940  1780
	1    0    0    -1  
$EndComp
Wire Wire Line
	940  1990 940  2190
Wire Wire Line
	940  1990 940  1780
Connection ~ 940  1990
Wire Wire Line
	3540 2250 3440 2250
Wire Wire Line
	2550 2790 3020 2790
Wire Wire Line
	3020 2250 3020 2790
Connection ~ 2550 2790
Wire Wire Line
	3540 2350 3440 2350
Wire Wire Line
	3440 2350 3440 2250
Connection ~ 3440 2250
Wire Wire Line
	3440 2250 3240 2250
$Comp
L power:GND #PWR012
U 1 1 5EC54D79
P 3840 2990
F 0 "#PWR012" H 3840 2740 50  0001 C CNN
F 1 "GND" H 3845 2817 50  0000 C CNN
F 2 "" H 3840 2990 50  0001 C CNN
F 3 "" H 3840 2990 50  0001 C CNN
	1    3840 2990
	1    0    0    -1  
$EndComp
Text Notes 610  1290 0    50   ~ 0
Design Requirements:\n\nC9 close to U2\nC10 & C11 close to U3\nFeedback line on U1 as short as possible
$Comp
L Device:C_Small C8
U 1 1 5EC610C6
P 3240 2350
F 0 "C8" H 3170 2570 50  0000 L CNN
F 1 "1uf" H 3160 2500 50  0000 L CNN
F 2 "" H 3240 2350 50  0001 C CNN
F 3 "~" H 3240 2350 50  0001 C CNN
	1    3240 2350
	1    0    0    -1  
$EndComp
Connection ~ 3240 2250
Wire Wire Line
	3240 2250 3020 2250
$Comp
L Device:R_Small R13
U 1 1 5EC63F48
P 4280 2550
F 0 "R13" H 4340 2580 50  0000 L CNN
F 1 "68k" H 4330 2510 50  0000 L CNN
F 2 "" H 4280 2550 50  0001 C CNN
F 3 "~" H 4280 2550 50  0001 C CNN
	1    4280 2550
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R12
U 1 1 5EC64877
P 4280 2350
F 0 "R12" H 4340 2380 50  0000 L CNN
F 1 "205k" H 4330 2310 50  0000 L CNN
F 2 "" H 4280 2350 50  0001 C CNN
F 3 "~" H 4280 2350 50  0001 C CNN
	1    4280 2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4140 2250 4280 2250
Wire Wire Line
	4140 2350 4140 2450
Wire Wire Line
	4140 2450 4280 2450
Connection ~ 4280 2450
$Comp
L power:GND #PWR013
U 1 1 5EC685AD
P 4280 2980
F 0 "#PWR013" H 4280 2730 50  0001 C CNN
F 1 "GND" H 4285 2807 50  0000 C CNN
F 2 "" H 4280 2980 50  0001 C CNN
F 3 "" H 4280 2980 50  0001 C CNN
	1    4280 2980
	1    0    0    -1  
$EndComp
Wire Wire Line
	4280 2250 4620 2250
Connection ~ 4280 2250
$Comp
L power:GND #PWR014
U 1 1 5EC6FFEA
P 4620 2980
F 0 "#PWR014" H 4620 2730 50  0001 C CNN
F 1 "GND" H 4625 2807 50  0000 C CNN
F 2 "" H 4620 2980 50  0001 C CNN
F 3 "" H 4620 2980 50  0001 C CNN
	1    4620 2980
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR016
U 1 1 5EC728F7
P 5140 1790
F 0 "#PWR016" H 5140 1640 50  0001 C CNN
F 1 "+5V" H 5155 1963 50  0000 C CNN
F 2 "" H 5140 1790 50  0001 C CNN
F 3 "" H 5140 1790 50  0001 C CNN
	1    5140 1790
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR011
U 1 1 5EC732D0
P 3240 2990
F 0 "#PWR011" H 3240 2740 50  0001 C CNN
F 1 "GND" H 3245 2817 50  0000 C CNN
F 2 "" H 3240 2990 50  0001 C CNN
F 3 "" H 3240 2990 50  0001 C CNN
	1    3240 2990
	1    0    0    -1  
$EndComp
Text Notes 1760 1610 0    50   ~ 0
Power Delivery\n
Text Notes 1730 3360 0    50   ~ 0
Microphone Pre Amplifier
Text Notes 2210 5180 0    50   ~ 0
Voltage Sensing\n
Text Notes 3450 5200 0    50   ~ 0
Temperature Sensing
$Comp
L Device:C_Small C10
U 1 1 5EC62A87
P 7185 3035
F 0 "C10" H 7115 3255 50  0000 L CNN
F 1 "10uf" H 7105 3185 50  0000 L CNN
F 2 "" H 7185 3035 50  0001 C CNN
F 3 "~" H 7185 3035 50  0001 C CNN
	1    7185 3035
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5EC989DA
P 7495 3035
F 0 "C11" H 7435 3255 50  0000 L CNN
F 1 ".1uf" H 7435 3185 50  0000 L CNN
F 2 "" H 7495 3035 50  0001 C CNN
F 3 "~" H 7495 3035 50  0001 C CNN
	1    7495 3035
	1    0    0    -1  
$EndComp
Text Notes 1470 5090 0    50   ~ 0
Button\n
$Comp
L power:+12V #PWR022
U 1 1 5EC9D5BE
P 3020 1800
F 0 "#PWR022" H 3020 1650 50  0001 C CNN
F 1 "+12V" H 3035 1973 50  0000 C CNN
F 2 "" H 3020 1800 50  0001 C CNN
F 3 "" H 3020 1800 50  0001 C CNN
	1    3020 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	950  2790 950  2990
Wire Wire Line
	1450 2890 1450 2990
Wire Wire Line
	3240 2450 3240 2990
Wire Wire Line
	3840 2990 3840 2650
Wire Wire Line
	4280 2650 4280 2980
$Comp
L Device:R_Small R14
U 1 1 5ECB70F4
P 1590 5570
F 0 "R14" H 1650 5600 50  0000 L CNN
F 1 "10k" H 1640 5530 50  0000 L CNN
F 2 "" H 1590 5570 50  0001 C CNN
F 3 "~" H 1590 5570 50  0001 C CNN
	1    1590 5570
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5ECB83BC
P 1590 5470
F 0 "#PWR019" H 1590 5320 50  0001 C CNN
F 1 "+5V" H 1605 5643 50  0000 C CNN
F 2 "" H 1590 5470 50  0001 C CNN
F 3 "" H 1590 5470 50  0001 C CNN
	1    1590 5470
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Open_Dual_x2 SW1
U 1 1 5ECC37E1
P 1290 5760
F 0 "SW1" H 1270 5970 50  0000 C CNN
F 1 "Momentary" H 1270 5900 50  0000 C CNN
F 2 "" H 1290 5960 50  0001 C CNN
F 3 "~" H 1290 5960 50  0001 C CNN
	1    1290 5760
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR018
U 1 1 5ECCEA82
P 940 5970
F 0 "#PWR018" H 940 5720 50  0001 C CNN
F 1 "GND" H 945 5797 50  0000 C CNN
F 2 "" H 940 5970 50  0001 C CNN
F 3 "" H 940 5970 50  0001 C CNN
	1    940  5970
	1    0    0    -1  
$EndComp
Wire Wire Line
	940  5760 1090 5760
Text Label 1940 5760 2    50   ~ 0
MODE
Connection ~ 3020 2250
Wire Wire Line
	4620 2450 4620 2980
$Comp
L Device:C_Small C9
U 1 1 5EC62516
P 4620 2350
F 0 "C9" H 4550 2570 50  0000 L CNN
F 1 "1uf" H 4540 2500 50  0000 L CNN
F 2 "" H 4620 2350 50  0001 C CNN
F 3 "~" H 4620 2350 50  0001 C CNN
	1    4620 2350
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR020
U 1 1 5EBF7B66
P 2230 5470
F 0 "#PWR020" H 2230 5320 50  0001 C CNN
F 1 "+BATT" H 2230 5640 50  0000 C CNN
F 2 "" H 2230 5470 50  0001 C CNN
F 3 "" H 2230 5470 50  0001 C CNN
	1    2230 5470
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR024
U 1 1 5EC17BFF
P 4050 5960
F 0 "#PWR024" H 4050 5710 50  0001 C CNN
F 1 "GND" H 4055 5787 50  0000 C CNN
F 2 "" H 4050 5960 50  0001 C CNN
F 3 "" H 4050 5960 50  0001 C CNN
	1    4050 5960
	1    0    0    -1  
$EndComp
Wire Wire Line
	3920 5770 4050 5770
Wire Wire Line
	4050 5770 4050 5960
Wire Wire Line
	3320 5770 3320 5480
$Comp
L Transistor_FET:CSD16342Q5A Q3
U 1 1 5EC1B2F5
P 4950 5830
F 0 "Q3" V 5199 5830 50  0000 C CNN
F 1 "A04484" V 5290 5830 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TDSON-8-1" H 5150 5755 50  0001 L CIN
F 3 "http://www.ti.com/lit/gpn/csd16342q5a" V 4950 5830 50  0001 L CNN
	1    4950 5830
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R20
U 1 1 5EC41317
P 4680 5630
F 0 "R20" V 4540 5570 50  0000 L CNN
F 1 "10k" V 4600 5560 50  0000 L CNN
F 2 "" H 4680 5630 50  0001 C CNN
F 3 "~" H 4680 5630 50  0001 C CNN
	1    4680 5630
	0    1    1    0   
$EndComp
Wire Wire Line
	4780 5630 4950 5630
Wire Wire Line
	4580 5630 4500 5630
$Comp
L Device:R_Small R19
U 1 1 5EC4B1C2
P 4500 5780
F 0 "R19" H 4320 5740 50  0000 L CNN
F 1 "10k" H 4320 5810 50  0000 L CNN
F 2 "" H 4500 5780 50  0001 C CNN
F 3 "~" H 4500 5780 50  0001 C CNN
	1    4500 5780
	-1   0    0    1   
$EndComp
Wire Wire Line
	4750 5930 4500 5930
Wire Wire Line
	4500 5630 4500 5440
Wire Wire Line
	4500 5440 5160 5440
$Comp
L Connector:TestPoint TP1
U 1 1 5EC5EAC3
P 5300 5930
F 0 "TP1" V 5260 5860 50  0000 L CNN
F 1 "LED-" V 5360 5830 50  0000 L CNN
F 2 "" H 5500 5930 50  0001 C CNN
F 3 "~" H 5500 5930 50  0001 C CNN
	1    5300 5930
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 5EC60427
P 5710 5930
F 0 "TP2" V 5750 5930 50  0000 C CNN
F 1 "LED+" V 5650 5930 50  0000 C CNN
F 2 "" H 5910 5930 50  0001 C CNN
F 3 "~" H 5910 5930 50  0001 C CNN
	1    5710 5930
	0    -1   -1   0   
$EndComp
$Comp
L power:+12V #PWR026
U 1 1 5EC2A521
P 6000 5470
F 0 "#PWR026" H 6000 5320 50  0001 C CNN
F 1 "+12V" H 6015 5643 50  0000 C CNN
F 2 "" H 6000 5470 50  0001 C CNN
F 3 "" H 6000 5470 50  0001 C CNN
	1    6000 5470
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 5930 5300 5930
Wire Wire Line
	5710 5930 6000 5930
$Comp
L power:GND #PWR025
U 1 1 5EC70D4C
P 4500 5960
F 0 "#PWR025" H 4500 5710 50  0001 C CNN
F 1 "GND" H 4505 5787 50  0000 C CNN
F 2 "" H 4500 5960 50  0001 C CNN
F 3 "" H 4500 5960 50  0001 C CNN
	1    4500 5960
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 5880 4500 5930
Wire Wire Line
	4500 5930 4500 5960
Connection ~ 4500 5930
Wire Wire Line
	4500 5630 4500 5680
Connection ~ 4500 5630
Wire Wire Line
	6000 5470 6000 5930
Text Label 5160 5440 2    50   ~ 0
LED
$Comp
L Device:Q_NPN_BEC Q1
U 1 1 5EB26D32
P 2000 4390
F 0 "Q1" H 2191 4436 50  0000 L CNN
F 1 "NPN" H 2191 4345 50  0000 L CNN
F 2 "" H 2200 4490 50  0001 C CNN
F 3 "~" H 2000 4390 50  0001 C CNN
	1    2000 4390
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R9
U 1 1 5EBF339E
P 2060 2190
F 0 "R9" V 2180 2140 50  0000 L CNN
F 1 "20mohm" V 2120 2100 50  0000 L CNN
F 2 "" H 2060 2190 50  0001 C CNN
F 3 "~" H 2060 2190 50  0001 C CNN
	1    2060 2190
	0    -1   -1   0   
$EndComp
Text Label 2600 3010 0    50   ~ 0
Test_This!
$Comp
L Device:CP1_Small C5
U 1 1 5EC0C8BD
P 940 2290
F 0 "C5" H 790 2330 50  0000 C CNN
F 1 "100uf" H 760 2250 50  0000 C CNN
F 2 "" H 940 2290 50  0001 C CNN
F 3 "~" H 940 2290 50  0001 C CNN
	1    940  2290
	1    0    0    -1  
$EndComp
Text Label 4500 5630 2    50   ~ 0
test_this
Wire Wire Line
	1970 2190 1970 2240
Wire Wire Line
	1970 2240 2250 2240
Wire Wire Line
	2250 2240 2250 2290
Wire Wire Line
	1970 2190 1960 2190
Connection ~ 1960 2190
$Comp
L power:+5V #PWR021
U 1 1 5EDAE4D4
P 3320 5480
F 0 "#PWR021" H 3320 5330 50  0001 C CNN
F 1 "+5V" H 3335 5653 50  0000 C CNN
F 2 "" H 3320 5480 50  0001 C CNN
F 3 "" H 3320 5480 50  0001 C CNN
	1    3320 5480
	1    0    0    -1  
$EndComp
Text Label 4240 5510 2    50   ~ 0
Temp_Sense
Wire Wire Line
	3720 5770 3720 5510
Connection ~ 3720 5770
Wire Wire Line
	3720 5510 4240 5510
$Comp
L Device:R_Small R18
U 1 1 5EC17007
P 3820 5770
F 0 "R18" V 3680 5710 50  0000 L CNN
F 1 "10k" V 3740 5700 50  0000 L CNN
F 2 "" H 3820 5770 50  0001 C CNN
F 3 "~" H 3820 5770 50  0001 C CNN
	1    3820 5770
	0    1    1    0   
$EndComp
$Comp
L Device:Thermistor TH1
U 1 1 5EC1537F
P 3520 5770
F 0 "TH1" V 3762 5770 50  0000 C CNN
F 1 "Thermistor" V 3671 5770 50  0000 C CNN
F 2 "" H 3520 5770 50  0001 C CNN
F 3 "~" H 3520 5770 50  0001 C CNN
	1    3520 5770
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2230 5470 2230 5760
Wire Wire Line
	2660 5760 3140 5760
Text Label 3140 5760 2    50   ~ 0
Pack_Sense
Wire Wire Line
	2460 5760 2230 5760
$Comp
L Device:R_Small R17
U 1 1 5EBF9002
P 2560 5760
F 0 "R17" V 2420 5680 50  0000 L CNN
F 1 "1M" V 2480 5690 50  0000 L CNN
F 2 "" H 2560 5760 50  0001 C CNN
F 3 "~" H 2560 5760 50  0001 C CNN
	1    2560 5760
	0    1    1    0   
$EndComp
Wire Wire Line
	940  5760 940  5970
Wire Wire Line
	1590 5670 1590 5760
Wire Wire Line
	1490 5760 1590 5760
Wire Wire Line
	1590 5760 1940 5760
Connection ~ 1590 5760
$Comp
L power:+BATT #PWR030
U 1 1 5EDC1E29
P 6550 4005
F 0 "#PWR030" H 6550 3855 50  0001 C CNN
F 1 "+BATT" H 6550 4175 50  0000 C CNN
F 2 "" H 6550 4005 50  0001 C CNN
F 3 "" H 6550 4005 50  0001 C CNN
	1    6550 4005
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 5EDCB754
P 5250 4110
F 0 "D2" H 5250 4305 50  0000 R CNN
F 1 "1N5819" H 5395 4375 50  0000 R CNN
F 2 "" H 5250 4110 50  0001 C CNN
F 3 "~" H 5250 4110 50  0001 C CNN
	1    5250 4110
	1    0    0    -1  
$EndComp
$Comp
L power:+12V #PWR023
U 1 1 5EDDA84D
P 4825 3910
F 0 "#PWR023" H 4825 3760 50  0001 C CNN
F 1 "+12V" H 4840 4083 50  0000 C CNN
F 2 "" H 4825 3910 50  0001 C CNN
F 3 "" H 4825 3910 50  0001 C CNN
	1    4825 3910
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4500 6335 4500
NoConn ~ 6050 4370
$Comp
L Device:L_Core_Iron L2
U 1 1 5EDC6B02
P 5895 4110
F 0 "L2" V 6120 4110 50  0000 C CNN
F 1 "23uh" V 6029 4110 50  0000 C CNN
F 2 "" H 5895 4110 50  0001 C CNN
F 3 "~" H 5895 4110 50  0001 C CNN
	1    5895 4110
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6045 4110 6335 4110
Wire Wire Line
	6550 4005 6550 4110
Wire Wire Line
	6335 4110 6335 4500
Wire Wire Line
	5745 4110 5400 4110
Wire Wire Line
	5400 4110 5400 4375
Connection ~ 5400 4110
Wire Wire Line
	4825 4110 4825 3910
Wire Wire Line
	6335 4110 6550 4110
Connection ~ 6335 4110
$Comp
L Device:C_Small C12
U 1 1 5EE38BEE
P 6550 4210
F 0 "C12" H 6680 4270 50  0000 L CNN
F 1 "uf" H 6645 4195 50  0000 L CNN
F 2 "" H 6550 4210 50  0001 C CNN
F 3 "~" H 6550 4210 50  0001 C CNN
	1    6550 4210
	1    0    0    -1  
$EndComp
Connection ~ 6550 4110
$Comp
L power:GND #PWR031
U 1 1 5EE3A491
P 6550 4310
F 0 "#PWR031" H 6550 4060 50  0001 C CNN
F 1 "GND" H 6555 4137 50  0000 C CNN
F 2 "" H 6550 4310 50  0001 C CNN
F 3 "" H 6550 4310 50  0001 C CNN
	1    6550 4310
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5EE3CF1B
P 4825 4210
F 0 "C4" H 4955 4270 50  0000 L CNN
F 1 "uf" H 4920 4195 50  0000 L CNN
F 2 "" H 4825 4210 50  0001 C CNN
F 3 "~" H 4825 4210 50  0001 C CNN
	1    4825 4210
	1    0    0    -1  
$EndComp
Connection ~ 4825 4110
$Comp
L power:GND #PWR027
U 1 1 5EE3D901
P 4825 4310
F 0 "#PWR027" H 4825 4060 50  0001 C CNN
F 1 "GND" H 4830 4137 50  0000 C CNN
F 2 "" H 4825 4310 50  0001 C CNN
F 3 "" H 4825 4310 50  0001 C CNN
	1    4825 4310
	1    0    0    -1  
$EndComp
Wire Wire Line
	4825 4110 5080 4110
$Comp
L Device:R_Small R15
U 1 1 5EE51AD9
P 5080 4525
F 0 "R15" H 5140 4555 50  0000 L CNN
F 1 "3k" H 5130 4485 50  0000 L CNN
F 2 "" H 5080 4525 50  0001 C CNN
F 3 "~" H 5080 4525 50  0001 C CNN
	1    5080 4525
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4625 5080 4625
$Comp
L Device:R_Small R16
U 1 1 5EE57D10
P 5080 4725
F 0 "R16" H 5140 4755 50  0000 L CNN
F 1 "3k" H 5130 4685 50  0000 L CNN
F 2 "" H 5080 4725 50  0001 C CNN
F 3 "~" H 5080 4725 50  0001 C CNN
	1    5080 4725
	1    0    0    -1  
$EndComp
Connection ~ 5080 4625
$Comp
L power:GND #PWR028
U 1 1 5EE584C6
P 5080 4825
F 0 "#PWR028" H 5080 4575 50  0001 C CNN
F 1 "GND" H 5085 4652 50  0000 C CNN
F 2 "" H 5080 4825 50  0001 C CNN
F 3 "" H 5080 4825 50  0001 C CNN
	1    5080 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	5080 4425 5080 4110
Connection ~ 5080 4110
Wire Wire Line
	5080 4110 5100 4110
$Comp
L power:GND #PWR029
U 1 1 5EE5C32A
P 5400 4500
F 0 "#PWR029" H 5400 4250 50  0001 C CNN
F 1 "GND" H 5405 4327 50  0000 C CNN
F 2 "" H 5400 4500 50  0001 C CNN
F 3 "" H 5400 4500 50  0001 C CNN
	1    5400 4500
	1    0    0    -1  
$EndComp
$Comp
L New_Library:MT3608 U4
U 1 1 5EDAF2E5
P 4800 3475
F 0 "U4" H 5660 3495 50  0000 C CNN
F 1 "MT3608" H 5780 3315 50  0000 C CNN
F 2 "" H 6100 2625 50  0001 C CNN
F 3 "" H 6100 2625 50  0001 C CNN
	1    4800 3475
	1    0    0    -1  
$EndComp
Wire Wire Line
	6050 4625 6830 4625
Text Label 6830 4625 2    50   ~ 0
POWER
$Comp
L MCU_Microchip_ATtiny:ATtiny814-SS U?
U 1 1 5EE6BDE9
P 8400 4045
F 0 "U?" H 8400 4926 50  0000 C CNN
F 1 "ATtiny814-SS" H 8400 4835 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 8400 4045 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001912A.pdf" H 8400 4045 50  0001 C CNN
	1    8400 4045
	1    0    0    -1  
$EndComp
Text Label 7335 3945 0    50   ~ 0
LED
Text Label 7335 3645 0    50   ~ 0
MIC_IN
Text Label 7335 3745 0    50   ~ 0
TEMP_SENSE
Wire Wire Line
	7335 3745 7800 3745
Wire Wire Line
	7335 3945 7800 3945
Wire Wire Line
	7335 3645 7800 3645
Wire Wire Line
	7800 3845 7335 3845
Text Label 7335 3845 0    50   ~ 0
MODE
Wire Wire Line
	9000 3745 9465 3745
Text Label 9465 3745 2    50   ~ 0
PACK_SENSE
Wire Wire Line
	9000 3845 9470 3845
Text Label 9470 3845 2    50   ~ 0
POWER
$Comp
L power:GND #PWR?
U 1 1 5EED066F
P 8400 4825
F 0 "#PWR?" H 8400 4575 50  0001 C CNN
F 1 "GND" H 8405 4652 50  0000 C CNN
F 2 "" H 8400 4825 50  0001 C CNN
F 3 "" H 8400 4825 50  0001 C CNN
	1    8400 4825
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 4745 8400 4825
Wire Wire Line
	8400 3345 8400 2935
Wire Wire Line
	8400 2935 7495 2935
Wire Wire Line
	7495 2935 7185 2935
Connection ~ 7495 2935
Wire Wire Line
	7185 3135 7185 3245
Wire Wire Line
	7495 3135 7495 3245
$Comp
L power:GND #PWR?
U 1 1 5EF1ABBA
P 7185 3245
F 0 "#PWR?" H 7185 2995 50  0001 C CNN
F 1 "GND" H 7190 3072 50  0000 C CNN
F 2 "" H 7185 3245 50  0001 C CNN
F 3 "" H 7185 3245 50  0001 C CNN
	1    7185 3245
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR?
U 1 1 5EF1B36C
P 7495 3245
F 0 "#PWR?" H 7495 2995 50  0001 C CNN
F 1 "GND" H 7500 3072 50  0000 C CNN
F 2 "" H 7495 3245 50  0001 C CNN
F 3 "" H 7495 3245 50  0001 C CNN
	1    7495 3245
	1    0    0    -1  
$EndComp
Wire Wire Line
	7185 2935 7025 2935
Wire Wire Line
	7025 2935 7025 2665
Connection ~ 7185 2935
$Comp
L power:+5V #PWR?
U 1 1 5EF1FE62
P 7025 2665
F 0 "#PWR?" H 7025 2515 50  0001 C CNN
F 1 "+5V" H 7040 2838 50  0000 C CNN
F 2 "" H 7025 2665 50  0001 C CNN
F 3 "" H 7025 2665 50  0001 C CNN
	1    7025 2665
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 3645 9465 3645
Text Label 9465 3645 2    50   ~ 0
PRMG
$Comp
L Device:D_Zener D?
U 1 1 5EDA6065
P 4060 1430
F 0 "D?" H 4100 1160 50  0000 R CNN
F 1 "1N5819" H 4175 1295 50  0000 R CNN
F 2 "" H 4060 1430 50  0001 C CNN
F 3 "~" H 4060 1430 50  0001 C CNN
	1    4060 1430
	-1   0    0    1   
$EndComp
Wire Wire Line
	3020 1800 3020 2250
Wire Wire Line
	5140 1790 5140 2250
Wire Wire Line
	4210 1430 4210 1790
Wire Wire Line
	4210 1790 5140 1790
Connection ~ 5140 1790
Wire Wire Line
	3910 1430 1165 1430
Wire Wire Line
	1165 1430 1165 1780
Wire Wire Line
	1165 1780 940  1780
Connection ~ 940  1780
$Comp
L Device:D_Zener D?
U 1 1 5EDD461B
P 4905 2250
F 0 "D?" H 4945 2055 50  0000 R CNN
F 1 "???" H 4965 2155 50  0000 R CNN
F 2 "" H 4905 2250 50  0001 C CNN
F 3 "~" H 4905 2250 50  0001 C CNN
	1    4905 2250
	-1   0    0    1   
$EndComp
Wire Wire Line
	4620 2250 4755 2250
Connection ~ 4620 2250
Wire Wire Line
	5055 2250 5140 2250
Text Label 4835 2390 0    50   ~ 0
test_this
Text Label 5315 4350 0    50   ~ 0
1
Text Label 5320 4490 0    50   ~ 0
2
Text Label 5290 4765 0    50   ~ 0
3
Text Label 6005 4705 0    50   ~ 0
6
Text Label 6050 4505 0    50   ~ 0
7
Text Label 5990 4305 0    50   ~ 0
8
Text Label 6465 3720 0    50   ~ 0
input
Text Label 4740 3660 0    50   ~ 0
output
$EndSCHEMATC
