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
	2210 4110 2210 4370
Connection ~ 2210 4660
Wire Wire Line
	2210 4660 2410 4660
Wire Wire Line
	2980 4860 2980 5070
Wire Wire Line
	2610 4460 2610 4660
Wire Wire Line
	2700 4460 2610 4460
Connection ~ 2610 4660
Wire Wire Line
	2610 4660 2680 4660
Wire Wire Line
	2980 4120 2980 4170
$Comp
L Device:R_Small R5
U 1 1 5EB3F4B3
P 2800 4460
F 0 "R5" V 2950 4500 50  0000 L CNN
F 1 "100k" V 2880 4410 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2800 4460 50  0001 C CNN
F 3 "~" H 2800 4460 50  0001 C CNN
	1    2800 4460
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5EB3F4AC
P 2980 5170
F 0 "R7" H 3039 5216 50  0000 L CNN
F 1 "1k" H 3039 5125 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2980 5170 50  0001 C CNN
F 3 "~" H 2980 5170 50  0001 C CNN
	1    2980 5170
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BEC Q2
U 1 1 5EB3F4A6
P 2880 4660
F 0 "Q2" H 3071 4706 50  0000 L CNN
F 1 "MMBT3904-TP" H 3071 4615 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 3080 4760 50  0001 C CNN
F 3 "~" H 2880 4660 50  0001 C CNN
	1    2880 4660
	1    0    0    -1  
$EndComp
Wire Wire Line
	2980 4460 3280 4460
$Comp
L Device:CP1_Small C3
U 1 1 5EB3F49E
P 3380 4460
F 0 "C3" V 3608 4460 50  0000 C CNN
F 1 "10uf" V 3517 4460 50  0000 C CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.3" H 3380 4460 50  0001 C CNN
F 3 "~" H 3380 4460 50  0001 C CNN
	1    3380 4460
	0    -1   -1   0   
$EndComp
Connection ~ 2980 4460
Wire Wire Line
	2980 4460 2980 4370
$Comp
L Device:R_Small R6
U 1 1 5EB3F490
P 2980 4270
F 0 "R6" H 3039 4316 50  0000 L CNN
F 1 "10k" H 3039 4225 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2980 4270 50  0001 C CNN
F 3 "~" H 2980 4270 50  0001 C CNN
	1    2980 4270
	1    0    0    -1  
$EndComp
Wire Wire Line
	2980 4460 2900 4460
$Comp
L Device:R_Small R1
U 1 1 5EB3EDFD
P 1060 4620
F 0 "R1" H 890 4575 50  0000 L CNN
F 1 "6.8k" H 840 4640 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1060 4620 50  0001 C CNN
F 3 "~" H 1060 4620 50  0001 C CNN
	1    1060 4620
	-1   0    0    1   
$EndComp
Connection ~ 1710 4860
Wire Wire Line
	1710 4860 1910 4860
Wire Wire Line
	1710 4660 1710 4860
Wire Wire Line
	1930 4660 1710 4660
$Comp
L Device:R_Small R2
U 1 1 5EB41476
P 2030 4660
F 0 "R2" V 2180 4700 50  0000 L CNN
F 1 "100k" V 2110 4610 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2030 4660 50  0001 C CNN
F 3 "~" H 2030 4660 50  0001 C CNN
	1    2030 4660
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1590 4860 1710 4860
$Comp
L Device:R_Small R4
U 1 1 5EB3FFDB
P 2210 5160
F 0 "R4" H 2269 5206 50  0000 L CNN
F 1 "1k" H 2269 5115 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2210 5160 50  0001 C CNN
F 3 "~" H 2210 5160 50  0001 C CNN
	1    2210 5160
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C2
U 1 1 5EB248DC
P 2510 4660
F 0 "C2" V 2738 4660 50  0000 C CNN
F 1 "10uf" V 2647 4660 50  0000 C CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.3" H 2510 4660 50  0001 C CNN
F 3 "~" H 2510 4660 50  0001 C CNN
	1    2510 4660
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2210 4660 2210 4570
$Comp
L Device:R_Small R3
U 1 1 5EB2C146
P 2210 4470
F 0 "R3" H 2269 4516 50  0000 L CNN
F 1 "10k" H 2269 4425 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2210 4470 50  0001 C CNN
F 3 "~" H 2210 4470 50  0001 C CNN
	1    2210 4470
	1    0    0    -1  
$EndComp
Wire Wire Line
	2210 4660 2130 4660
Wire Wire Line
	3480 4460 4045 4460
Text Label 4360 4460 2    50   ~ 0
MIC_IN
$Comp
L Device:C_Small C8
U 1 1 5EC610C6
P 3765 2680
F 0 "C8" H 3795 2615 50  0000 L CNN
F 1 "1uf" H 3790 2550 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 3765 2680 50  0001 C CNN
F 3 "~" H 3765 2680 50  0001 C CNN
	1    3765 2680
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R13
U 1 1 5EC63F48
P 4805 2880
F 0 "R13" H 4865 2910 50  0000 L CNN
F 1 "68k" H 4855 2840 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4805 2880 50  0001 C CNN
F 3 "~" H 4805 2880 50  0001 C CNN
	1    4805 2880
	1    0    0    -1  
$EndComp
Wire Wire Line
	4665 2680 4665 2780
Wire Wire Line
	4665 2780 4805 2780
Connection ~ 4805 2780
$Comp
L power:+5V #PWR016
U 1 1 5EC728F7
P 5675 2360
F 0 "#PWR016" H 5675 2210 50  0001 C CNN
F 1 "+5V" H 5690 2533 50  0000 C CNN
F 2 "" H 5675 2360 50  0001 C CNN
F 3 "" H 5675 2360 50  0001 C CNN
	1    5675 2360
	1    0    0    -1  
$EndComp
Text Notes 1570 3875 0    50   ~ 0
Microphone Pre Amplifier
Text Notes 2005 5785 0    50   ~ 0
Voltage Sensing\n
Text Notes 3245 5805 0    50   ~ 0
Temperature Sensing
Text Notes 1265 5695 0    50   ~ 0
Button\n
$Comp
L Switch:SW_Push_Open_Dual_x2 SW1
U 1 1 5ECC37E1
P 920 6365
F 0 "SW1" H 900 6575 50  0000 C CNN
F 1 "Momentary" H 900 6505 50  0000 C CNN
F 2 "Main Board1:tactile" H 920 6565 50  0001 C CNN
F 3 "~" H 920 6565 50  0001 C CNN
	1    920  6365
	1    0    0    -1  
$EndComp
Text Label 1765 6365 2    50   ~ 0
MODE
$Comp
L Device:C_Small C9
U 1 1 5EC62516
P 5145 2680
F 0 "C9" H 5225 2675 50  0000 L CNN
F 1 "1uf" H 5230 2595 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5145 2680 50  0001 C CNN
F 3 "~" H 5145 2680 50  0001 C CNN
	1    5145 2680
	1    0    0    -1  
$EndComp
$Comp
L power:+BATT #PWR020
U 1 1 5EBF7B66
P 2025 6065
F 0 "#PWR020" H 2025 5915 50  0001 C CNN
F 1 "+BATT" H 2025 6235 50  0000 C CNN
F 2 "" H 2025 6065 50  0001 C CNN
F 3 "" H 2025 6065 50  0001 C CNN
	1    2025 6065
	1    0    0    -1  
$EndComp
Wire Wire Line
	3715 6365 3845 6365
Wire Wire Line
	3845 6365 3845 6555
Wire Wire Line
	3115 6365 3115 6075
$Comp
L Device:R_Small R20
U 1 1 5EC41317
P 4475 6225
F 0 "R20" V 4335 6165 50  0000 L CNN
F 1 "220R" V 4395 6155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4475 6225 50  0001 C CNN
F 3 "~" H 4475 6225 50  0001 C CNN
	1    4475 6225
	0    1    1    0   
$EndComp
Wire Wire Line
	4375 6225 4295 6225
$Comp
L Device:R_Small R19
U 1 1 5EC4B1C2
P 4295 6375
F 0 "R19" H 4115 6335 50  0000 L CNN
F 1 "10k" H 4115 6405 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4295 6375 50  0001 C CNN
F 3 "~" H 4295 6375 50  0001 C CNN
	1    4295 6375
	-1   0    0    1   
$EndComp
Wire Wire Line
	4545 6525 4295 6525
Wire Wire Line
	4295 6225 4295 6035
Wire Wire Line
	4295 6035 4955 6035
$Comp
L Connector:TestPoint TP1
U 1 1 5EC5EAC3
P 5095 6525
F 0 "TP1" V 5055 6455 50  0000 L CNN
F 1 "LED-" V 5155 6425 50  0000 L CNN
F 2 "TestPoint:TestPoint_Pad_3.0x3.0mm" H 5295 6525 50  0001 C CNN
F 3 "~" H 5295 6525 50  0001 C CNN
	1    5095 6525
	0    1    1    0   
$EndComp
$Comp
L Connector:TestPoint TP2
U 1 1 5EC60427
P 5505 6525
F 0 "TP2" V 5545 6525 50  0000 C CNN
F 1 "LED+" V 5445 6525 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_3.0x3.0mm" H 5705 6525 50  0001 C CNN
F 3 "~" H 5705 6525 50  0001 C CNN
	1    5505 6525
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4945 6525 5095 6525
Wire Wire Line
	5505 6525 5795 6525
Wire Wire Line
	4295 6475 4295 6525
Wire Wire Line
	4295 6225 4295 6275
Connection ~ 4295 6225
Text Label 4955 6035 2    50   ~ 0
LED
$Comp
L Device:Q_NPN_BEC Q1
U 1 1 5EB26D32
P 2110 4860
F 0 "Q1" H 2301 4906 50  0000 L CNN
F 1 "MMBT3904-TP" H 2301 4815 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 2310 4960 50  0001 C CNN
F 3 "~" H 2110 4860 50  0001 C CNN
	1    2110 4860
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR021
U 1 1 5EDAE4D4
P 3115 6075
F 0 "#PWR021" H 3115 5925 50  0001 C CNN
F 1 "+5V" H 3130 6248 50  0000 C CNN
F 2 "" H 3115 6075 50  0001 C CNN
F 3 "" H 3115 6075 50  0001 C CNN
	1    3115 6075
	1    0    0    -1  
$EndComp
Text Label 4035 6105 2    50   ~ 0
TEMP_SENSE
Wire Wire Line
	3515 6365 3515 6105
Connection ~ 3515 6365
Wire Wire Line
	3515 6105 4035 6105
$Comp
L Device:R_Small R18
U 1 1 5EC17007
P 3615 6365
F 0 "R18" V 3475 6305 50  0000 L CNN
F 1 "10k" V 3535 6295 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 3615 6365 50  0001 C CNN
F 3 "~" H 3615 6365 50  0001 C CNN
	1    3615 6365
	0    1    1    0   
$EndComp
$Comp
L Device:Thermistor TH1
U 1 1 5EC1537F
P 3315 6365
F 0 "TH1" V 3557 6365 50  0000 C CNN
F 1 "Thermistor" V 3466 6365 50  0000 C CNN
F 2 "Capacitor_SMD:C_0805_2012Metric" H 3315 6365 50  0001 C CNN
F 3 "~" H 3315 6365 50  0001 C CNN
	1    3315 6365
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2025 6065 2025 6355
Wire Wire Line
	2455 6355 2935 6355
Text Label 2935 6355 2    50   ~ 0
PACK_SENSE
Wire Wire Line
	2255 6355 2025 6355
$Comp
L Device:R_Small R17
U 1 1 5EBF9002
P 2355 6355
F 0 "R17" V 2215 6275 50  0000 L CNN
F 1 "1M" V 2275 6285 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2355 6355 50  0001 C CNN
F 3 "~" H 2355 6355 50  0001 C CNN
	1    2355 6355
	0    1    1    0   
$EndComp
Wire Wire Line
	1120 6365 1220 6365
$Comp
L Device:D_Zener D3
U 1 1 5EDD461B
P 5430 2580
F 0 "D3" H 5470 2385 50  0000 R CNN
F 1 "1N5819" H 5555 2485 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-323" H 5430 2580 50  0001 C CNN
F 3 "~" H 5430 2580 50  0001 C CNN
	1    5430 2580
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small R12
U 1 1 5EC64877
P 4805 2680
F 0 "R12" H 4865 2710 50  0000 L CNN
F 1 "205k" H 4855 2640 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 4805 2680 50  0001 C CNN
F 3 "~" H 4805 2680 50  0001 C CNN
	1    4805 2680
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 5EB3F4D9
P 2980 4120
F 0 "#PWR02" H 2980 3970 50  0001 C CNN
F 1 "+5V" H 2995 4293 50  0000 C CNN
F 2 "" H 2980 4120 50  0001 C CNN
F 3 "" H 2980 4120 50  0001 C CNN
	1    2980 4120
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5EB466B9
P 2210 4110
F 0 "#PWR01" H 2210 3960 50  0001 C CNN
F 1 "+5V" H 2225 4283 50  0000 C CNN
F 2 "" H 2210 4110 50  0001 C CNN
F 3 "" H 2210 4110 50  0001 C CNN
	1    2210 4110
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5EB2E0D5
P 1060 4120
F 0 "#PWR0103" H 1060 3970 50  0001 C CNN
F 1 "+5V" H 1075 4293 50  0000 C CNN
F 2 "" H 1060 4120 50  0001 C CNN
F 3 "" H 1060 4120 50  0001 C CNN
	1    1060 4120
	1    0    0    -1  
$EndComp
Connection ~ 890  2580
$Comp
L Device:L_Core_Iron L1
U 1 1 5EDC6B02
P 1545 2580
F 0 "L1" V 1770 2580 50  0000 C CNN
F 1 "10uh" V 1679 2580 50  0000 C CNN
F 2 "Inductor_SMD:L_Sunlord_MWSA0518_5.4x5.2mm" H 1545 2580 50  0001 C CNN
F 3 "~" H 1545 2580 50  0001 C CNN
	1    1545 2580
	0    1    -1   0   
$EndComp
$Comp
L power:GNDPWR #PWR03
U 1 1 5EF7E5EB
P 890 3295
F 0 "#PWR03" H 890 3095 50  0001 C CNN
F 1 "GNDPWR" H 894 3141 50  0000 C CNN
F 2 "" H 890 3245 50  0001 C CNN
F 3 "" H 890 3245 50  0001 C CNN
	1    890  3295
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR06
U 1 1 5EF83271
P 2125 2945
F 0 "#PWR06" H 2125 2745 50  0001 C CNN
F 1 "GNDPWR" H 2200 2985 50  0000 C CNN
F 2 "" H 2125 2895 50  0001 C CNN
F 3 "" H 2125 2895 50  0001 C CNN
	1    2125 2945
	1    0    0    -1  
$EndComp
Wire Wire Line
	2040 2945 2125 2945
$Comp
L power:+10V #PWR010
U 1 1 5EF7B517
P 2975 2355
F 0 "#PWR010" H 2975 2205 50  0001 C CNN
F 1 "+10V" H 2990 2528 50  0000 C CNN
F 2 "" H 2975 2355 50  0001 C CNN
F 3 "" H 2975 2355 50  0001 C CNN
	1    2975 2355
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R15
U 1 1 5EE51AD9
P 2430 2995
F 0 "R15" H 2200 3075 50  0000 L CNN
F 1 "43k" H 2210 2985 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2430 2995 50  0001 C CNN
F 3 "~" H 2430 2995 50  0001 C CNN
	1    2430 2995
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R16
U 1 1 5EE57D10
P 2430 3195
F 0 "R16" H 2210 3240 50  0000 L CNN
F 1 "2.7k" H 2190 3140 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 2430 3195 50  0001 C CNN
F 3 "~" H 2430 3195 50  0001 C CNN
	1    2430 3195
	-1   0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5EE3CF1B
P 2765 2680
F 0 "C4" H 2595 2580 50  0000 L CNN
F 1 "22uf" H 2525 2495 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 2765 2680 50  0001 C CNN
F 3 "~" H 2765 2680 50  0001 C CNN
	1    2765 2680
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR09
U 1 1 5F00F1BE
P 2765 3300
F 0 "#PWR09" H 2765 3100 50  0001 C CNN
F 1 "GNDPWR" H 2780 3120 50  0000 C CNN
F 2 "" H 2765 3250 50  0001 C CNN
F 3 "" H 2765 3250 50  0001 C CNN
	1    2765 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2040 3095 2430 3095
Wire Wire Line
	2430 2580 2765 2580
Wire Wire Line
	2385 2580 2430 2580
Wire Wire Line
	2430 2580 2430 2585
Connection ~ 2430 2580
Connection ~ 2430 3095
Wire Wire Line
	2430 2580 2430 2895
Wire Wire Line
	1390 3095 1260 3095
Wire Wire Line
	1260 3095 1260 3395
Wire Wire Line
	1260 3395 2125 3395
Text Label 2125 3395 2    50   ~ 0
EN
$Comp
L Device:L_Core_Iron L2
U 1 1 5F1204AE
P 3235 2580
F 0 "L2" V 3405 2555 50  0000 C CNN
F 1 "1uh" V 3335 2585 50  0000 C CNN
F 2 "Inductor_SMD:L_0805_2012Metric" H 3235 2580 50  0001 C CNN
F 3 "~" H 3235 2580 50  0001 C CNN
	1    3235 2580
	0    1    -1   0   
$EndComp
$Comp
L power:GNDA #PWR012
U 1 1 5F1609AA
P 3515 3290
F 0 "#PWR012" H 3515 3040 50  0001 C CNN
F 1 "GNDA" H 3520 3117 50  0000 C CNN
F 2 "" H 3515 3290 50  0001 C CNN
F 3 "" H 3515 3290 50  0001 C CNN
	1    3515 3290
	1    0    0    -1  
$EndComp
Connection ~ 2765 2580
Wire Wire Line
	2765 2580 2975 2580
Connection ~ 2975 2580
Wire Wire Line
	2975 2580 3085 2580
$Comp
L Device:CP1_Small C5
U 1 1 5F13F3D9
P 3515 2680
F 0 "C5" H 3295 2670 50  0000 L CNN
F 1 "100uf" H 3265 2590 50  0000 L CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x7.7" H 3515 2680 50  0001 C CNN
F 3 "~" H 3515 2680 50  0001 C CNN
	1    3515 2680
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 5EDCB754
P 2235 2580
F 0 "D2" H 2380 2755 50  0000 R CNN
F 1 "1N5819" H 2385 2685 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-323" H 2235 2580 50  0001 C CNN
F 3 "~" H 2235 2580 50  0001 C CNN
	1    2235 2580
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3385 2580 3515 2580
Connection ~ 3515 2580
$Comp
L power:GNDA #PWR013
U 1 1 5F1FD2F8
P 3765 3290
F 0 "#PWR013" H 3765 3040 50  0001 C CNN
F 1 "GNDA" H 3770 3117 50  0000 C CNN
F 2 "" H 3765 3290 50  0001 C CNN
F 3 "" H 3765 3290 50  0001 C CNN
	1    3765 3290
	1    0    0    -1  
$EndComp
Wire Wire Line
	3765 2780 3765 3290
$Comp
L power:GNDA #PWR015
U 1 1 5F201A91
P 4362 3292
F 0 "#PWR015" H 4362 3042 50  0001 C CNN
F 1 "GNDA" H 4367 3119 50  0000 C CNN
F 2 "" H 4362 3292 50  0001 C CNN
F 3 "" H 4362 3292 50  0001 C CNN
	1    4362 3292
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR018
U 1 1 5F2069CD
P 4805 3300
F 0 "#PWR018" H 4805 3050 50  0001 C CNN
F 1 "GNDA" H 4810 3127 50  0000 C CNN
F 2 "" H 4805 3300 50  0001 C CNN
F 3 "" H 4805 3300 50  0001 C CNN
	1    4805 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4805 2980 4805 3300
$Comp
L power:GNDA #PWR022
U 1 1 5F20C7C4
P 5145 3300
F 0 "#PWR022" H 5145 3050 50  0001 C CNN
F 1 "GNDA" H 5150 3127 50  0000 C CNN
F 2 "" H 5145 3300 50  0001 C CNN
F 3 "" H 5145 3300 50  0001 C CNN
	1    5145 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5145 2775 5145 2780
Connection ~ 5145 2780
Wire Wire Line
	5145 2780 5145 3300
$Comp
L power:GNDPWR #PWR017
U 1 1 5F219DC9
P 4295 6555
F 0 "#PWR017" H 4295 6355 50  0001 C CNN
F 1 "GNDPWR" H 4299 6401 50  0000 C CNN
F 2 "" H 4295 6505 50  0001 C CNN
F 3 "" H 4295 6505 50  0001 C CNN
	1    4295 6555
	1    0    0    -1  
$EndComp
Connection ~ 4295 6525
Wire Wire Line
	4295 6525 4295 6555
$Comp
L power:GNDA #PWR014
U 1 1 5F238051
P 3845 6555
F 0 "#PWR014" H 3845 6305 50  0001 C CNN
F 1 "GNDA" H 3850 6382 50  0000 C CNN
F 2 "" H 3845 6555 50  0001 C CNN
F 3 "" H 3845 6555 50  0001 C CNN
	1    3845 6555
	1    0    0    -1  
$EndComp
Text Notes 7030 7110 0    79   ~ 16
Michael Madi | David Roberts | www.flaketechnologies.ca\n
Text Notes 7350 7510 0    79   ~ 16
Rave Lights Main Board\n
Wire Wire Line
	5580 2580 5675 2580
Wire Wire Line
	2765 2780 2765 3205
$Comp
L Device:Ferrite_Bead_Small FB1
U 1 1 5F30A8DC
P 3135 3205
F 0 "FB1" V 2898 3205 50  0000 C CNN
F 1 "ACML-0805-190-T" V 2989 3205 50  0000 C CNN
F 2 "Resistor_SMD:R_0603_1608Metric" V 3065 3205 50  0001 C CNN
F 3 "~" H 3135 3205 50  0001 C CNN
	1    3135 3205
	0    1    1    0   
$EndComp
Connection ~ 2765 3205
Wire Wire Line
	2765 3205 2765 3300
Wire Wire Line
	3515 2780 3515 3205
Wire Wire Line
	2765 3205 3035 3205
Wire Wire Line
	3235 3205 3515 3205
Connection ~ 3515 3205
Wire Wire Line
	3515 3205 3515 3290
$Comp
L Device:D_Zener D1
U 1 1 5F336FEA
P 3868 2092
F 0 "D1" H 3908 1897 50  0000 R CNN
F 1 "1N5819" H 3993 1997 50  0000 R CNN
F 2 "Diode_SMD:D_SOD-323" H 3868 2092 50  0001 C CNN
F 3 "~" H 3868 2092 50  0001 C CNN
	1    3868 2092
	-1   0    0    1   
$EndComp
$Comp
L power:GNDA #PWR05
U 1 1 5F38954F
P 1060 5270
F 0 "#PWR05" H 1060 5020 50  0001 C CNN
F 1 "GNDA" H 1065 5097 50  0000 C CNN
F 2 "" H 1060 5270 50  0001 C CNN
F 3 "" H 1060 5270 50  0001 C CNN
	1    1060 5270
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR011
U 1 1 5F38C701
P 2980 5270
F 0 "#PWR011" H 2980 5020 50  0001 C CNN
F 1 "GNDA" H 2985 5097 50  0000 C CNN
F 2 "" H 2980 5270 50  0001 C CNN
F 3 "" H 2980 5270 50  0001 C CNN
	1    2980 5270
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR07
U 1 1 5F38CB69
P 2210 5260
F 0 "#PWR07" H 2210 5010 50  0001 C CNN
F 1 "GNDA" H 2215 5087 50  0000 C CNN
F 2 "" H 2210 5260 50  0001 C CNN
F 3 "" H 2210 5260 50  0001 C CNN
	1    2210 5260
	1    0    0    -1  
$EndComp
Connection ~ 5880 3585
Wire Wire Line
	5880 3580 5880 3585
Wire Wire Line
	5730 3580 5880 3580
Wire Wire Line
	5880 3585 6190 3585
Wire Wire Line
	6190 3585 7410 3585
Connection ~ 6190 3585
$Comp
L Device:C_Small C10
U 1 1 5EC62A87
P 5880 3685
F 0 "C10" H 5810 3935 50  0000 L CNN
F 1 "10uf" H 5800 3860 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 5880 3685 50  0001 C CNN
F 3 "~" H 5880 3685 50  0001 C CNN
	1    5880 3685
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5EC989DA
P 6190 3685
F 0 "C11" H 6125 3940 50  0000 L CNN
F 1 ".1uf" H 6115 3865 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6190 3685 50  0001 C CNN
F 3 "~" H 6190 3685 50  0001 C CNN
	1    6190 3685
	1    0    0    -1  
$EndComp
Text Label 6345 4300 0    50   ~ 0
LED
Text Label 8475 4300 2    50   ~ 0
MIC_IN
Text Label 8475 4600 2    50   ~ 0
TEMP_SENSE
Wire Wire Line
	8475 4600 8010 4600
Wire Wire Line
	6345 4300 6810 4300
Wire Wire Line
	8475 4300 8010 4300
Wire Wire Line
	8010 4500 8475 4500
Text Label 8915 4700 2    50   ~ 0
EN
Wire Wire Line
	7410 5100 7410 5180
Wire Wire Line
	5880 3785 5880 3895
Wire Wire Line
	6190 3785 6190 3895
Wire Wire Line
	5730 3580 5730 3310
$Comp
L power:+5V #PWR024
U 1 1 5EF1FE62
P 5730 3310
F 0 "#PWR024" H 5730 3160 50  0001 C CNN
F 1 "+5V" H 5745 3483 50  0000 C CNN
F 2 "" H 5730 3310 50  0001 C CNN
F 3 "" H 5730 3310 50  0001 C CNN
	1    5730 3310
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R8
U 1 1 5F2B9B1E
P 8920 4810
F 0 "R8" H 8985 4780 50  0000 L CNN
F 1 "1M" H 8990 4845 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8920 4810 50  0001 C CNN
F 3 "~" H 8920 4810 50  0001 C CNN
	1    8920 4810
	-1   0    0    1   
$EndComp
Wire Wire Line
	8920 4700 8920 4710
Wire Wire Line
	8010 4700 8920 4700
$Comp
L power:GNDA #PWR025
U 1 1 5F2DDF4B
P 5880 3895
F 0 "#PWR025" H 5880 3645 50  0001 C CNN
F 1 "GNDA" H 5885 3722 50  0000 C CNN
F 2 "" H 5880 3895 50  0001 C CNN
F 3 "" H 5880 3895 50  0001 C CNN
	1    5880 3895
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR026
U 1 1 5F2E1016
P 6190 3895
F 0 "#PWR026" H 6190 3645 50  0001 C CNN
F 1 "GNDA" H 6195 3722 50  0000 C CNN
F 2 "" H 6190 3895 50  0001 C CNN
F 3 "" H 6190 3895 50  0001 C CNN
	1    6190 3895
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR027
U 1 1 5F2E1CBF
P 7410 5180
F 0 "#PWR027" H 7410 4930 50  0001 C CNN
F 1 "GNDA" H 7415 5007 50  0000 C CNN
F 2 "" H 7410 5180 50  0001 C CNN
F 3 "" H 7410 5180 50  0001 C CNN
	1    7410 5180
	1    0    0    -1  
$EndComp
Wire Wire Line
	1060 4120 1060 4195
Connection ~ 1060 4195
Wire Wire Line
	1060 4195 1060 4520
$Comp
L power:GNDA #PWR029
U 1 1 5EE88359
P 770 5264
F 0 "#PWR029" H 770 5014 50  0001 C CNN
F 1 "GNDA" H 775 5091 50  0000 C CNN
F 2 "" H 770 5264 50  0001 C CNN
F 3 "" H 770 5264 50  0001 C CNN
	1    770  5264
	1    0    0    -1  
$EndComp
Wire Wire Line
	770  4395 770  5264
$Comp
L Connector:TestPoint TP4
U 1 1 5EEB7C53
P 5310 4645
F 0 "TP4" V 5300 5100 50  0000 C CNN
F 1 "GND" V 5310 4895 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 5510 4645 50  0001 C CNN
F 3 "~" H 5510 4645 50  0001 C CNN
	1    5310 4645
	0    -1   -1   0   
$EndComp
$Comp
L power:GNDA #PWR031
U 1 1 5EEE8CA3
P 5310 4745
F 0 "#PWR031" H 5310 4495 50  0001 C CNN
F 1 "GNDA" H 5315 4572 50  0000 C CNN
F 2 "" H 5310 4745 50  0001 C CNN
F 3 "" H 5310 4745 50  0001 C CNN
	1    5310 4745
	1    0    0    -1  
$EndComp
Wire Wire Line
	5310 4645 5310 4745
$Comp
L Connector:TestPoint TP5
U 1 1 5EEBD3EB
P 5315 4385
F 0 "TP5" V 5310 4845 50  0000 C CNN
F 1 "5V" V 5310 4610 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 5515 4385 50  0001 C CNN
F 3 "~" H 5515 4385 50  0001 C CNN
	1    5315 4385
	0    -1   -1   0   
$EndComp
$Comp
L power:+5V #PWR032
U 1 1 5EF46672
P 5315 4270
F 0 "#PWR032" H 5315 4120 50  0001 C CNN
F 1 "+5V" H 5330 4443 50  0000 C CNN
F 2 "" H 5315 4270 50  0001 C CNN
F 3 "" H 5315 4270 50  0001 C CNN
	1    5315 4270
	1    0    0    -1  
$EndComp
Wire Wire Line
	5315 4385 5315 4270
Text Notes 4930 4005 0    50   ~ 0
JTAG Interface \n
$Comp
L power:+10V #PWR023
U 1 1 5F378EC4
P 5795 6065
F 0 "#PWR023" H 5795 5915 50  0001 C CNN
F 1 "+10V" H 5810 6238 50  0000 C CNN
F 2 "" H 5795 6065 50  0001 C CNN
F 3 "" H 5795 6065 50  0001 C CNN
	1    5795 6065
	1    0    0    -1  
$EndComp
Wire Wire Line
	5795 6065 5795 6525
Text Notes 2225 1980 0    50   ~ 0
Dynamic Power Delivery
Wire Wire Line
	5675 2360 5675 2580
Wire Wire Line
	2975 2355 2975 2580
$Comp
L Device:C_Small C7
U 1 1 5EF7EC11
P 1420 6465
F 0 "C7" H 1180 6425 50  0000 L CNN
F 1 ".1uf" H 1140 6325 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 1420 6465 50  0001 C CNN
F 3 "~" H 1420 6465 50  0001 C CNN
	1    1420 6465
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR0101
U 1 1 5EF7FD8D
P 1420 6575
F 0 "#PWR0101" H 1420 6325 50  0001 C CNN
F 1 "GNDA" H 1425 6402 50  0000 C CNN
F 2 "" H 1420 6575 50  0001 C CNN
F 3 "" H 1420 6575 50  0001 C CNN
	1    1420 6575
	1    0    0    -1  
$EndComp
Wire Wire Line
	1420 6565 1420 6575
$Comp
L Device:C_Small C12
U 1 1 5EE38BEE
P 890 2680
F 0 "C12" H 1020 2740 50  0000 L CNN
F 1 "22uf" H 985 2665 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 890 2680 50  0001 C CNN
F 3 "~" H 890 2680 50  0001 C CNN
	1    890  2680
	-1   0    0    -1  
$EndComp
Wire Wire Line
	770  4195 1060 4195
Wire Wire Line
	890  2350 890  2580
$Comp
L Connector:TestPoint TP8
U 1 1 5EF8F245
P 4045 4460
F 0 "TP8" H 4035 4745 50  0000 C CNN
F 1 "MIC " H 4060 4670 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D2.0mm" H 4245 4460 50  0001 C CNN
F 3 "~" H 4245 4460 50  0001 C CNN
	1    4045 4460
	1    0    0    -1  
$EndComp
Connection ~ 4045 4460
Wire Wire Line
	4045 4460 4360 4460
Wire Wire Line
	4362 2980 4362 3292
Text Label 4000 3176 1    50   ~ 0
EN
Wire Wire Line
	4062 2680 4000 2680
Wire Wire Line
	4000 2680 4000 3176
Wire Wire Line
	3515 2580 3765 2580
Connection ~ 3765 2580
Wire Wire Line
	3765 2580 4062 2580
Wire Wire Line
	4662 2580 4774 2580
Connection ~ 4805 2580
Wire Wire Line
	4805 2580 5145 2580
Connection ~ 5145 2580
Wire Wire Line
	5145 2580 5280 2580
Wire Wire Line
	4774 2092 4774 2580
Wire Wire Line
	4018 2092 4774 2092
Connection ~ 4774 2580
Wire Wire Line
	4774 2580 4805 2580
$Comp
L Main-Board-rescue:AP2127K-ADJ U2
U 1 1 5EC19F82
P 4362 2680
F 0 "U2" H 4242 2985 50  0000 C CNN
F 1 "NCP718A" H 4357 2910 50  0000 C CNN
F 2 "Footprints:SON65P200X200X80-7N" H 4362 3005 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCP718-D.PDF" H 4362 2780 50  0001 C CNN
	1    4362 2680
	1    0    0    -1  
$EndComp
Wire Wire Line
	4662 2680 4665 2680
Connection ~ 4665 2680
Wire Wire Line
	4665 2680 4666 2680
Connection ~ 770  5264
Wire Wire Line
	770  5264 770  5265
Wire Wire Line
	7410 3585 7410 3700
$Comp
L Main-Board-rescue:ATtiny814-SS-MCU_Microchip_ATtiny U3
U 1 1 5EE6BDE9
P 7410 4400
F 0 "U3" H 6845 5115 50  0000 C CNN
F 1 "ATtiny1614" H 7060 5045 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 7410 4400 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001912A.pdf" H 7410 4400 50  0001 C CNN
	1    7410 4400
	1    0    0    -1  
$EndComp
NoConn ~ 1390 2795
Wire Wire Line
	1148 2092 3718 2092
$Comp
L power:+3.3V #PWR030
U 1 1 5EFBD8F3
P 890 2350
F 0 "#PWR030" H 890 2200 50  0001 C CNN
F 1 "+3.3V" H 905 2523 50  0000 C CNN
F 2 "" H 890 2350 50  0001 C CNN
F 3 "" H 890 2350 50  0001 C CNN
	1    890  2350
	1    0    0    -1  
$EndComp
Wire Wire Line
	890  2780 890  3295
Wire Wire Line
	1060 4720 1060 4858
Wire Wire Line
	1060 4858 1060 4860
Connection ~ 1060 4858
$Comp
L Connector:TestPoint TP14
U 1 1 5F02BA9C
P 1060 4858
F 0 "TP14" H 1214 5108 50  0000 C CNN
F 1 "MIC+" H 920 4976 50  0000 C CNN
F 2 "TestPoint:TestPoint_Keystone_5019_Minature" H 1260 4858 50  0001 C CNN
F 3 "~" H 1260 4858 50  0001 C CNN
	1    1060 4858
	-1   0    0    1   
$EndComp
$Comp
L Connector:TestPoint TP15
U 1 1 5F02D592
P 1060 5270
F 0 "TP15" H 916 5658 50  0000 C CNN
F 1 "MIC-" H 1206 5372 50  0000 C CNN
F 2 "TestPoint:TestPoint_Keystone_5019_Minature" H 1260 5270 50  0001 C CNN
F 3 "~" H 1260 5270 50  0001 C CNN
	1    1060 5270
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR036
U 1 1 5EFFB1C2
P 8260 2245
F 0 "#PWR036" H 8260 2045 50  0001 C CNN
F 1 "GNDPWR" H 8264 2091 50  0000 C CNN
F 2 "" H 8260 2195 50  0001 C CNN
F 3 "" H 8260 2195 50  0001 C CNN
	1    8260 2245
	1    0    0    -1  
$EndComp
Wire Wire Line
	8260 2145 8260 2245
Wire Wire Line
	8010 2145 8260 2145
Wire Wire Line
	8260 1995 8260 1845
Wire Wire Line
	8010 1995 8260 1995
$Comp
L power:+3.3V #PWR035
U 1 1 5EFC1B62
P 8260 1845
F 0 "#PWR035" H 8260 1695 50  0001 C CNN
F 1 "+3.3V" H 8275 2018 50  0000 C CNN
F 2 "" H 8260 1845 50  0001 C CNN
F 3 "" H 8260 1845 50  0001 C CNN
	1    8260 1845
	1    0    0    -1  
$EndComp
$Comp
L New_Library:MT3608 U1
U 1 1 5EDAF2E5
P 2640 1945
F 0 "U1" H 3655 1250 50  0000 C CNN
F 1 "MT3608" H 3555 1180 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6" H 3940 1095 50  0001 C CNN
F 3 "" H 3940 1095 50  0001 C CNN
	1    2640 1945
	-1   0    0    -1  
$EndComp
Text Label 6355 4100 0    50   ~ 0
PACK_SENSE
Wire Wire Line
	1390 2945 1115 2945
Wire Wire Line
	1115 2945 1115 2580
Wire Wire Line
	890  2580 1115 2580
Connection ~ 1115 2580
Connection ~ 1148 2580
Wire Wire Line
	1115 2580 1148 2580
Wire Wire Line
	1395 2580 1148 2580
Wire Wire Line
	1148 2092 1148 2580
Wire Wire Line
	2040 2795 2040 2580
Wire Wire Line
	1695 2580 2040 2580
Wire Wire Line
	2040 2580 2085 2580
Connection ~ 2040 2580
Wire Wire Line
	8010 4000 8475 4000
Wire Wire Line
	5310 4530 5500 4530
$Comp
L Connector:TestPoint TP3
U 1 1 5EEBD8E0
P 5310 4530
F 0 "TP3" V 5305 4985 50  0000 C CNN
F 1 "UDPI" V 5305 4795 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_D2.5mm" H 5510 4530 50  0001 C CNN
F 3 "~" H 5510 4530 50  0001 C CNN
	1    5310 4530
	0    -1   -1   0   
$EndComp
Text Label 8475 4000 2    50   ~ 0
PRGM
Text Label 5500 4530 2    50   ~ 0
PRGM
Text Notes 740  1460 0    50   ~ 0
Design Requirements:\n\nR15 & R16 Close to U1. Feedback line short as possible. Short and wide traces\n\nC8 & C9 close to U2\n\nC10 & C11 close to U3\n\nC6 as close to pre amp as possible\n\n
$Comp
L power:GNDPWR #PWR0102
U 1 1 5F1F8B1A
P 2430 3295
F 0 "#PWR0102" H 2430 3095 50  0001 C CNN
F 1 "GNDPWR" H 2445 3115 50  0000 C CNN
F 2 "" H 2430 3245 50  0001 C CNN
F 3 "" H 2430 3245 50  0001 C CNN
	1    2430 3295
	1    0    0    -1  
$EndComp
NoConn ~ 4662 2830
Text Label 4745 6225 0    50   ~ 0
G
Text Label 4545 6525 2    50   ~ 0
S
Wire Wire Line
	4575 6225 4745 6225
$Comp
L Transistor_FET:CSD16342Q5A Q3
U 1 1 5EC1B2F5
P 4745 6425
F 0 "Q3" V 4994 6425 50  0000 C CNN
F 1 "AO4484" V 5085 6425 50  0000 C CNN
F 2 "Main Board1:SOIC-8_3.9x4.9mm_P1.27mm" H 4945 6350 50  0001 L CIN
F 3 "http://www.ti.com/lit/gpn/csd16342q5a" V 4745 6425 50  0001 L CNN
	1    4745 6425
	0    1    1    0   
$EndComp
Text Label 4946 6525 0    50   ~ 0
D
$Comp
L Connector:TestPoint TP7
U 1 1 5F1B2984
P 7085 1876
F 0 "TP7" V 7159 1986 50  0000 C CNN
F 1 "Battery+" V 7079 2201 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_3.0x3.0mm" H 7285 1876 50  0001 C CNN
F 3 "~" H 7285 1876 50  0001 C CNN
	1    7085 1876
	0    1    1    0   
$EndComp
Wire Wire Line
	7085 1876 7085 1870
Connection ~ 7085 1876
$Comp
L power:+BATT #PWR08
U 1 1 5F1B298E
P 7085 1870
F 0 "#PWR08" H 7085 1720 50  0001 C CNN
F 1 "+BATT" H 7085 2040 50  0000 C CNN
F 2 "" H 7085 1870 50  0001 C CNN
F 3 "" H 7085 1870 50  0001 C CNN
	1    7085 1870
	-1   0    0    -1  
$EndComp
Wire Wire Line
	7085 1995 7085 1876
Wire Wire Line
	6860 1995 7085 1995
$Comp
L Main-Board-rescue:TP4056 U4
U 1 1 5F19CB5C
P 7510 1845
F 0 "U4" H 7435 2045 50  0000 L CNN
F 1 "TP4056" H 7415 2110 50  0000 L CNN
F 2 "Main Board1:charger" H 7510 1845 50  0001 C CNN
F 3 "" H 7510 1845 50  0001 C CNN
	1    7510 1845
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint TP9
U 1 1 5F208168
P 7085 2270
F 0 "TP9" V 7015 2380 50  0000 C CNN
F 1 "Battery-" V 7086 2595 50  0000 C CNN
F 2 "TestPoint:TestPoint_Pad_3.0x3.0mm" H 7285 2270 50  0001 C CNN
F 3 "~" H 7285 2270 50  0001 C CNN
	1    7085 2270
	0    1    1    0   
$EndComp
Wire Wire Line
	6860 2145 7085 2145
$Comp
L power:GNDREF #PWR028
U 1 1 5F20816F
P 7085 2270
F 0 "#PWR028" H 7085 2020 50  0001 C CNN
F 1 "GNDREF" H 7090 2097 50  0000 C CNN
F 2 "" H 7085 2270 50  0001 C CNN
F 3 "" H 7085 2270 50  0001 C CNN
	1    7085 2270
	1    0    0    -1  
$EndComp
Wire Wire Line
	7085 2145 7085 2270
Connection ~ 7085 2270
NoConn ~ 7760 2495
NoConn ~ 7760 2595
Wire Wire Line
	8920 4910 8920 5375
NoConn ~ 6810 4000
NoConn ~ 8010 4100
Wire Wire Line
	6810 4100 6355 4100
NoConn ~ 6810 4200
$Comp
L power:GNDREF #PWR0104
U 1 1 5F063991
P 8920 5375
F 0 "#PWR0104" H 8920 5125 50  0001 C CNN
F 1 "GNDREF" H 8925 5202 50  0000 C CNN
F 2 "" H 8920 5375 50  0001 C CNN
F 3 "" H 8920 5375 50  0001 C CNN
	1    8920 5375
	1    0    0    -1  
$EndComp
Text Notes 7080 7260 0    197  ~ 39
Flake Technologies\n\n
$Comp
L Main-Board-rescue:LOGO #G1
U 1 1 5F13D2FC
P 6160 7300
F 0 "#G1" H 6160 6833 60  0001 C CNN
F 1 "LOGO" H 6160 7767 60  0001 C CNN
F 2 "" H 6160 7300 50  0001 C CNN
F 3 "" H 6160 7300 50  0001 C CNN
	1    6160 7300
	1    0    0    -1  
$EndComp
Text Label 8475 4500 2    50   ~ 0
MODE
NoConn ~ 8010 4200
NoConn ~ 8010 4400
$Comp
L Device:R_Small R9
U 1 1 5F24F16D
P 1320 6365
F 0 "R9" V 1250 6275 50  0000 L CNN
F 1 "1k" V 1410 6260 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1320 6365 50  0001 C CNN
F 3 "~" H 1320 6365 50  0001 C CNN
	1    1320 6365
	0    1    1    0   
$EndComp
$Comp
L power:GNDA #PWR04
U 1 1 5F234ADB
P 570 6575
F 0 "#PWR04" H 570 6325 50  0001 C CNN
F 1 "GNDA" H 575 6402 50  0000 C CNN
F 2 "" H 570 6575 50  0001 C CNN
F 3 "" H 570 6575 50  0001 C CNN
	1    570  6575
	1    0    0    -1  
$EndComp
Wire Wire Line
	570  6365 570  6575
Wire Wire Line
	570  6365 720  6365
Wire Wire Line
	1415 6365 1420 6365
Wire Wire Line
	1420 6275 1420 6365
$Comp
L power:+5V #PWR019
U 1 1 5ECB83BC
P 1420 6075
F 0 "#PWR019" H 1420 5925 50  0001 C CNN
F 1 "+5V" H 1435 6248 50  0000 C CNN
F 2 "" H 1420 6075 50  0001 C CNN
F 3 "" H 1420 6075 50  0001 C CNN
	1    1420 6075
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R14
U 1 1 5ECB70F4
P 1420 6175
F 0 "R14" H 1480 6205 50  0000 L CNN
F 1 "10k" H 1470 6135 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 1420 6175 50  0001 C CNN
F 3 "~" H 1420 6175 50  0001 C CNN
	1    1420 6175
	1    0    0    -1  
$EndComp
Connection ~ 1420 6365
Wire Wire Line
	1420 6365 1765 6365
$Comp
L Device:CP1_Small C6
U 1 1 5EE78E32
P 770 4295
F 0 "C6" H 890 4350 50  0000 C CNN
F 1 "100uf" H 945 4275 50  0000 C CNN
F 2 "Capacitor_SMD:CP_Elec_6.3x7.7" H 770 4295 50  0001 C CNN
F 3 "~" H 770 4295 50  0001 C CNN
	1    770  4295
	1    0    0    -1  
$EndComp
Connection ~ 1390 4860
Wire Wire Line
	1390 4860 1392 4860
Wire Wire Line
	1060 4860 1390 4860
$Comp
L Device:CP1_Small C1
U 1 1 5EB25AD7
P 1490 4860
F 0 "C1" V 1718 4860 50  0000 C CNN
F 1 "10uf" V 1627 4860 50  0000 C CNN
F 2 "Capacitor_SMD:CP_Elec_4x5.3" H 1490 4860 50  0001 C CNN
F 3 "~" H 1490 4860 50  0001 C CNN
	1    1490 4860
	0    -1   -1   0   
$EndComp
$EndSCHEMATC
