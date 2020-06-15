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
	2060 4075 2060 4335
Wire Wire Line
	910  4085 910  4485
Connection ~ 2060 4625
Wire Wire Line
	2060 4625 2260 4625
Wire Wire Line
	2830 4825 2830 5035
Wire Wire Line
	2460 4425 2460 4625
Wire Wire Line
	2550 4425 2460 4425
Connection ~ 2460 4625
Wire Wire Line
	2460 4625 2530 4625
Wire Wire Line
	2830 4085 2830 4135
$Comp
L Device:R_Small R5
U 1 1 5EB3F4B3
P 2650 4425
F 0 "R5" V 2800 4465 50  0000 L CNN
F 1 "100k" V 2730 4375 50  0000 L CNN
F 2 "" H 2650 4425 50  0001 C CNN
F 3 "~" H 2650 4425 50  0001 C CNN
	1    2650 4425
	0    -1   -1   0   
$EndComp
$Comp
L Device:R_Small R7
U 1 1 5EB3F4AC
P 2830 5135
F 0 "R7" H 2889 5181 50  0000 L CNN
F 1 "1k" H 2889 5090 50  0000 L CNN
F 2 "" H 2830 5135 50  0001 C CNN
F 3 "~" H 2830 5135 50  0001 C CNN
	1    2830 5135
	1    0    0    -1  
$EndComp
$Comp
L Device:Q_NPN_BEC Q2
U 1 1 5EB3F4A6
P 2730 4625
F 0 "Q2" H 2921 4671 50  0000 L CNN
F 1 "NPN" H 2921 4580 50  0000 L CNN
F 2 "" H 2930 4725 50  0001 C CNN
F 3 "~" H 2730 4625 50  0001 C CNN
	1    2730 4625
	1    0    0    -1  
$EndComp
Wire Wire Line
	2830 4425 3130 4425
$Comp
L Device:CP1_Small C3
U 1 1 5EB3F49E
P 3230 4425
F 0 "C3" V 3458 4425 50  0000 C CNN
F 1 "10uf" V 3367 4425 50  0000 C CNN
F 2 "" H 3230 4425 50  0001 C CNN
F 3 "~" H 3230 4425 50  0001 C CNN
	1    3230 4425
	0    -1   -1   0   
$EndComp
Connection ~ 2830 4425
Wire Wire Line
	2830 4425 2830 4335
$Comp
L Device:R_Small R6
U 1 1 5EB3F490
P 2830 4235
F 0 "R6" H 2889 4281 50  0000 L CNN
F 1 "10k" H 2889 4190 50  0000 L CNN
F 2 "" H 2830 4235 50  0001 C CNN
F 3 "~" H 2830 4235 50  0001 C CNN
	1    2830 4235
	1    0    0    -1  
$EndComp
Wire Wire Line
	2830 4425 2750 4425
Wire Wire Line
	910  4825 910  4835
Connection ~ 910  4825
Wire Wire Line
	1240 4825 910  4825
$Comp
L Device:Microphone MK1
U 1 1 5EB245CF
P 910 5035
F 0 "MK1" H 1040 5081 50  0000 L CNN
F 1 "MIC" H 1040 4990 50  0000 L CNN
F 2 "" V 910 5135 50  0001 C CNN
F 3 "~" V 910 5135 50  0001 C CNN
	1    910  5035
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R1
U 1 1 5EB3EDFD
P 910 4585
F 0 "R1" H 969 4631 50  0000 L CNN
F 1 "6.8k" H 969 4540 50  0000 L CNN
F 2 "" H 910 4585 50  0001 C CNN
F 3 "~" H 910 4585 50  0001 C CNN
	1    910  4585
	-1   0    0    1   
$EndComp
Wire Wire Line
	910  4685 910  4825
Connection ~ 1560 4825
Wire Wire Line
	1560 4825 1760 4825
Wire Wire Line
	1560 4625 1560 4825
Wire Wire Line
	1780 4625 1560 4625
$Comp
L Device:R_Small R2
U 1 1 5EB41476
P 1880 4625
F 0 "R2" V 2030 4665 50  0000 L CNN
F 1 "100k" V 1960 4575 50  0000 L CNN
F 2 "" H 1880 4625 50  0001 C CNN
F 3 "~" H 1880 4625 50  0001 C CNN
	1    1880 4625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1440 4825 1560 4825
$Comp
L Device:R_Small R4
U 1 1 5EB3FFDB
P 2060 5125
F 0 "R4" H 2119 5171 50  0000 L CNN
F 1 "1k" H 2119 5080 50  0000 L CNN
F 2 "" H 2060 5125 50  0001 C CNN
F 3 "~" H 2060 5125 50  0001 C CNN
	1    2060 5125
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C2
U 1 1 5EB248DC
P 2360 4625
F 0 "C2" V 2588 4625 50  0000 C CNN
F 1 "10uf" V 2497 4625 50  0000 C CNN
F 2 "" H 2360 4625 50  0001 C CNN
F 3 "~" H 2360 4625 50  0001 C CNN
	1    2360 4625
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2060 4625 2060 4535
$Comp
L Device:R_Small R3
U 1 1 5EB2C146
P 2060 4435
F 0 "R3" H 2119 4481 50  0000 L CNN
F 1 "10k" H 2119 4390 50  0000 L CNN
F 2 "" H 2060 4435 50  0001 C CNN
F 3 "~" H 2060 4435 50  0001 C CNN
	1    2060 4435
	1    0    0    -1  
$EndComp
Wire Wire Line
	2060 4625 1980 4625
$Comp
L Device:CP1_Small C1
U 1 1 5EB25AD7
P 1340 4825
F 0 "C1" V 1568 4825 50  0000 C CNN
F 1 "10uf" V 1477 4825 50  0000 C CNN
F 2 "" H 1340 4825 50  0001 C CNN
F 3 "~" H 1340 4825 50  0001 C CNN
	1    1340 4825
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3330 4425 4210 4425
Text Label 4210 4425 2    50   ~ 0
MIC_IN
$Comp
L Regulator_Linear:AP2204K-ADJ U2
U 1 1 5EC19F82
P 4215 2645
F 0 "U2" H 4095 2950 50  0000 C CNN
F 1 "NCP718A" H 4210 2875 50  0000 C CNN
F 2 "Footprints:SON65P200X200X80-7N" H 4215 2970 50  0001 C CNN
F 3 "https://www.onsemi.com/pub/Collateral/NCP718-D.PDF" H 4215 2745 50  0001 C CNN
	1    4215 2645
	1    0    0    -1  
$EndComp
Text Notes 600  1355 0    50   ~ 0
Design Requirements:\n\nR15 & R16 Close to U1. Feedback line short as possible. Short and wide traces\n\nC8 & C9 close to U2\n\nC10 & C11 close to U3\n\n
$Comp
L Device:C_Small C8
U 1 1 5EC610C6
P 3615 2645
F 0 "C8" H 3645 2580 50  0000 L CNN
F 1 "1uf" H 3640 2515 50  0000 L CNN
F 2 "" H 3615 2645 50  0001 C CNN
F 3 "~" H 3615 2645 50  0001 C CNN
	1    3615 2645
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small R13
U 1 1 5EC63F48
P 4655 2845
F 0 "R13" H 4715 2875 50  0000 L CNN
F 1 "68k" H 4705 2805 50  0000 L CNN
F 2 "" H 4655 2845 50  0001 C CNN
F 3 "~" H 4655 2845 50  0001 C CNN
	1    4655 2845
	1    0    0    -1  
$EndComp
Wire Wire Line
	4515 2645 4515 2745
Wire Wire Line
	4515 2745 4655 2745
Connection ~ 4655 2745
$Comp
L power:+5V #PWR016
U 1 1 5EC728F7
P 5525 2330
F 0 "#PWR016" H 5525 2180 50  0001 C CNN
F 1 "+5V" H 5540 2503 50  0000 C CNN
F 2 "" H 5525 2330 50  0001 C CNN
F 3 "" H 5525 2330 50  0001 C CNN
	1    5525 2330
	1    0    0    -1  
$EndComp
Text Notes 1420 3840 0    50   ~ 0
Microphone Pre Amplifier
Text Notes 2005 5785 0    50   ~ 0
Voltage Sensing\n
Text Notes 3245 5805 0    50   ~ 0
Temperature Sensing
Text Notes 1265 5695 0    50   ~ 0
Button\n
$Comp
L Device:R_Small R14
U 1 1 5ECB70F4
P 1385 6165
F 0 "R14" H 1445 6195 50  0000 L CNN
F 1 "10k" H 1435 6125 50  0000 L CNN
F 2 "" H 1385 6165 50  0001 C CNN
F 3 "~" H 1385 6165 50  0001 C CNN
	1    1385 6165
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR019
U 1 1 5ECB83BC
P 1385 6065
F 0 "#PWR019" H 1385 5915 50  0001 C CNN
F 1 "+5V" H 1400 6238 50  0000 C CNN
F 2 "" H 1385 6065 50  0001 C CNN
F 3 "" H 1385 6065 50  0001 C CNN
	1    1385 6065
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push_Open_Dual_x2 SW1
U 1 1 5ECC37E1
P 1085 6355
F 0 "SW1" H 1065 6565 50  0000 C CNN
F 1 "Momentary" H 1065 6495 50  0000 C CNN
F 2 "" H 1085 6555 50  0001 C CNN
F 3 "~" H 1085 6555 50  0001 C CNN
	1    1085 6355
	1    0    0    -1  
$EndComp
Wire Wire Line
	735  6355 885  6355
Text Label 1735 6355 2    50   ~ 0
MODE
$Comp
L Device:C_Small C9
U 1 1 5EC62516
P 4995 2645
F 0 "C9" H 5075 2640 50  0000 L CNN
F 1 "1uf" H 5080 2560 50  0000 L CNN
F 2 "" H 4995 2645 50  0001 C CNN
F 3 "~" H 4995 2645 50  0001 C CNN
	1    4995 2645
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
L Transistor_FET:CSD16342Q5A Q3
U 1 1 5EC1B2F5
P 4745 6425
F 0 "Q3" V 4994 6425 50  0000 C CNN
F 1 "A04484" V 5085 6425 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:TDSON-8-1" H 4945 6350 50  0001 L CIN
F 3 "http://www.ti.com/lit/gpn/csd16342q5a" V 4745 6425 50  0001 L CNN
	1    4745 6425
	0    1    1    0   
$EndComp
$Comp
L Device:R_Small R20
U 1 1 5EC41317
P 4475 6225
F 0 "R20" V 4335 6165 50  0000 L CNN
F 1 "10k" V 4395 6155 50  0000 L CNN
F 2 "" H 4475 6225 50  0001 C CNN
F 3 "~" H 4475 6225 50  0001 C CNN
	1    4475 6225
	0    1    1    0   
$EndComp
Wire Wire Line
	4575 6225 4745 6225
Wire Wire Line
	4375 6225 4295 6225
$Comp
L Device:R_Small R19
U 1 1 5EC4B1C2
P 4295 6375
F 0 "R19" H 4115 6335 50  0000 L CNN
F 1 "10k" H 4115 6405 50  0000 L CNN
F 2 "" H 4295 6375 50  0001 C CNN
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
F 2 "" H 5295 6525 50  0001 C CNN
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
F 2 "" H 5705 6525 50  0001 C CNN
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
Wire Wire Line
	5795 6065 5795 6525
Text Label 4955 6035 2    50   ~ 0
LED
$Comp
L Device:Q_NPN_BEC Q1
U 1 1 5EB26D32
P 1960 4825
F 0 "Q1" H 2151 4871 50  0000 L CNN
F 1 "NPN" H 2151 4780 50  0000 L CNN
F 2 "" H 2160 4925 50  0001 C CNN
F 3 "~" H 1960 4825 50  0001 C CNN
	1    1960 4825
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
Temp_Sense
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
F 2 "" H 3615 6365 50  0001 C CNN
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
F 2 "" H 3315 6365 50  0001 C CNN
F 3 "~" H 3315 6365 50  0001 C CNN
	1    3315 6365
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2025 6065 2025 6355
Wire Wire Line
	2455 6355 2935 6355
Text Label 2935 6355 2    50   ~ 0
Pack_Sense
Wire Wire Line
	2255 6355 2025 6355
$Comp
L Device:R_Small R17
U 1 1 5EBF9002
P 2355 6355
F 0 "R17" V 2215 6275 50  0000 L CNN
F 1 "1M" V 2275 6285 50  0000 L CNN
F 2 "" H 2355 6355 50  0001 C CNN
F 3 "~" H 2355 6355 50  0001 C CNN
	1    2355 6355
	0    1    1    0   
$EndComp
Wire Wire Line
	735  6355 735  6565
Wire Wire Line
	1385 6265 1385 6355
Wire Wire Line
	1285 6355 1385 6355
Wire Wire Line
	1385 6355 1735 6355
Connection ~ 1385 6355
$Comp
L Device:D_Zener D3
U 1 1 5EDD461B
P 5280 2545
F 0 "D3" H 5320 2350 50  0000 R CNN
F 1 "1N5819" H 5405 2450 50  0000 R CNN
F 2 "" H 5280 2545 50  0001 C CNN
F 3 "~" H 5280 2545 50  0001 C CNN
	1    5280 2545
	-1   0    0    1   
$EndComp
Wire Wire Line
	4995 2545 5130 2545
$Comp
L Device:R_Small R12
U 1 1 5EC64877
P 4655 2645
F 0 "R12" H 4715 2675 50  0000 L CNN
F 1 "205k" H 4705 2605 50  0000 L CNN
F 2 "" H 4655 2645 50  0001 C CNN
F 3 "~" H 4655 2645 50  0001 C CNN
	1    4655 2645
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR02
U 1 1 5EB3F4D9
P 2830 4085
F 0 "#PWR02" H 2830 3935 50  0001 C CNN
F 1 "+5V" H 2845 4258 50  0000 C CNN
F 2 "" H 2830 4085 50  0001 C CNN
F 3 "" H 2830 4085 50  0001 C CNN
	1    2830 4085
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR01
U 1 1 5EB466B9
P 2060 4075
F 0 "#PWR01" H 2060 3925 50  0001 C CNN
F 1 "+5V" H 2075 4248 50  0000 C CNN
F 2 "" H 2060 4075 50  0001 C CNN
F 3 "" H 2060 4075 50  0001 C CNN
	1    2060 4075
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0103
U 1 1 5EB2E0D5
P 910 4085
F 0 "#PWR0103" H 910 3935 50  0001 C CNN
F 1 "+5V" H 925 4258 50  0000 C CNN
F 2 "" H 910 4085 50  0001 C CNN
F 3 "" H 910 4085 50  0001 C CNN
	1    910  4085
	1    0    0    -1  
$EndComp
Connection ~ 740  2545
Connection ~ 955  2545
Wire Wire Line
	955  2545 740  2545
Wire Wire Line
	1890 2545 1890 2810
Wire Wire Line
	1545 2545 1890 2545
Wire Wire Line
	955  2545 955  2935
Wire Wire Line
	740  2440 740  2545
Wire Wire Line
	1245 2545 955  2545
$Comp
L Device:L_Core_Iron L1
U 1 1 5EDC6B02
P 1395 2545
F 0 "L1" V 1620 2545 50  0000 C CNN
F 1 "10uh" V 1529 2545 50  0000 C CNN
F 2 "" H 1395 2545 50  0001 C CNN
F 3 "~" H 1395 2545 50  0001 C CNN
	1    1395 2545
	0    1    -1   0   
$EndComp
NoConn ~ 1240 2805
Wire Wire Line
	1240 2935 955  2935
$Comp
L power:+BATT #PWR030
U 1 1 5EDC1E29
P 740 2440
F 0 "#PWR030" H 740 2290 50  0001 C CNN
F 1 "+BATT" H 740 2610 50  0000 C CNN
F 2 "" H 740 2440 50  0001 C CNN
F 3 "" H 740 2440 50  0001 C CNN
	1    740  2440
	-1   0    0    -1  
$EndComp
Wire Wire Line
	740  2745 740  3260
$Comp
L power:GNDPWR #PWR03
U 1 1 5EF7E5EB
P 740 3260
F 0 "#PWR03" H 740 3060 50  0001 C CNN
F 1 "GNDPWR" H 744 3106 50  0000 C CNN
F 2 "" H 740 3210 50  0001 C CNN
F 3 "" H 740 3210 50  0001 C CNN
	1    740  3260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR06
U 1 1 5EF83271
P 1975 2935
F 0 "#PWR06" H 1975 2735 50  0001 C CNN
F 1 "GNDPWR" H 1965 2980 50  0000 C CNN
F 2 "" H 1975 2885 50  0001 C CNN
F 3 "" H 1975 2885 50  0001 C CNN
	1    1975 2935
	1    0    0    -1  
$EndComp
$Comp
L New_Library:MT3608 U1
U 1 1 5EDAF2E5
P 2490 1910
F 0 "U1" H 3505 1215 50  0000 C CNN
F 1 "MT3608" H 3405 1145 50  0000 C CNN
F 2 "" H 3790 1060 50  0001 C CNN
F 3 "" H 3790 1060 50  0001 C CNN
	1    2490 1910
	-1   0    0    -1  
$EndComp
Wire Wire Line
	1890 2935 1975 2935
$Comp
L Device:C_Small C12
U 1 1 5EE38BEE
P 740 2645
F 0 "C12" H 870 2705 50  0000 L CNN
F 1 "22uf" H 835 2630 50  0000 L CNN
F 2 "" H 740 2645 50  0001 C CNN
F 3 "~" H 740 2645 50  0001 C CNN
	1    740  2645
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR08
U 1 1 5EF94857
P 2280 3260
F 0 "#PWR08" H 2280 3010 50  0001 C CNN
F 1 "GNDA" H 2285 3087 50  0000 C CNN
F 2 "" H 2280 3260 50  0001 C CNN
F 3 "" H 2280 3260 50  0001 C CNN
	1    2280 3260
	1    0    0    -1  
$EndComp
$Comp
L power:+10V #PWR010
U 1 1 5EF7B517
P 2825 2345
F 0 "#PWR010" H 2825 2195 50  0001 C CNN
F 1 "+10V" H 2840 2518 50  0000 C CNN
F 2 "" H 2825 2345 50  0001 C CNN
F 3 "" H 2825 2345 50  0001 C CNN
	1    2825 2345
	1    0    0    -1  
$EndComp
Wire Wire Line
	2825 2545 2825 2345
$Comp
L Device:R_Small R15
U 1 1 5EE51AD9
P 2280 2960
F 0 "R15" H 2050 3040 50  0000 L CNN
F 1 "43k" H 2060 2950 50  0000 L CNN
F 2 "" H 2280 2960 50  0001 C CNN
F 3 "~" H 2280 2960 50  0001 C CNN
	1    2280 2960
	-1   0    0    -1  
$EndComp
$Comp
L Device:R_Small R16
U 1 1 5EE57D10
P 2280 3160
F 0 "R16" H 2060 3205 50  0000 L CNN
F 1 "2.7k" H 2040 3105 50  0000 L CNN
F 2 "" H 2280 3160 50  0001 C CNN
F 3 "~" H 2280 3160 50  0001 C CNN
	1    2280 3160
	-1   0    0    -1  
$EndComp
$Comp
L Device:C_Small C4
U 1 1 5EE3CF1B
P 2615 2645
F 0 "C4" H 2445 2545 50  0000 L CNN
F 1 "22uf" H 2375 2460 50  0000 L CNN
F 2 "" H 2615 2645 50  0001 C CNN
F 3 "~" H 2615 2645 50  0001 C CNN
	1    2615 2645
	-1   0    0    -1  
$EndComp
$Comp
L power:GNDPWR #PWR09
U 1 1 5F00F1BE
P 2615 3265
F 0 "#PWR09" H 2615 3065 50  0001 C CNN
F 1 "GNDPWR" H 2630 3085 50  0000 C CNN
F 2 "" H 2615 3215 50  0001 C CNN
F 3 "" H 2615 3215 50  0001 C CNN
	1    2615 3265
	1    0    0    -1  
$EndComp
Wire Wire Line
	1890 3060 2280 3060
Wire Wire Line
	2280 2545 2615 2545
Wire Wire Line
	2235 2545 2280 2545
Wire Wire Line
	2280 2545 2280 2550
Connection ~ 2280 2545
Wire Wire Line
	1935 2545 1890 2545
Connection ~ 1890 2545
Connection ~ 2280 3060
Wire Wire Line
	2280 2545 2280 2860
Wire Wire Line
	1240 3060 1110 3060
Wire Wire Line
	1110 3060 1110 3360
Wire Wire Line
	1110 3360 1975 3360
Text Label 1975 3360 2    50   ~ 0
MAIN_POWER
$Comp
L Device:L_Core_Iron L2
U 1 1 5F1204AE
P 3085 2545
F 0 "L2" V 3255 2520 50  0000 C CNN
F 1 "1uh" V 3185 2550 50  0000 C CNN
F 2 "" H 3085 2545 50  0001 C CNN
F 3 "~" H 3085 2545 50  0001 C CNN
	1    3085 2545
	0    1    -1   0   
$EndComp
$Comp
L power:GNDA #PWR012
U 1 1 5F1609AA
P 3365 3255
F 0 "#PWR012" H 3365 3005 50  0001 C CNN
F 1 "GNDA" H 3370 3082 50  0000 C CNN
F 2 "" H 3365 3255 50  0001 C CNN
F 3 "" H 3365 3255 50  0001 C CNN
	1    3365 3255
	1    0    0    -1  
$EndComp
Connection ~ 2615 2545
Wire Wire Line
	2615 2545 2825 2545
Connection ~ 2825 2545
Wire Wire Line
	2825 2545 2935 2545
$Comp
L Device:CP1_Small C5
U 1 1 5F13F3D9
P 3365 2645
F 0 "C5" H 3145 2635 50  0000 L CNN
F 1 "100uf" H 3115 2555 50  0000 L CNN
F 2 "" H 3365 2645 50  0001 C CNN
F 3 "~" H 3365 2645 50  0001 C CNN
	1    3365 2645
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Zener D2
U 1 1 5EDCB754
P 2085 2545
F 0 "D2" H 2230 2720 50  0000 R CNN
F 1 "1N5819" H 2235 2650 50  0000 R CNN
F 2 "" H 2085 2545 50  0001 C CNN
F 3 "~" H 2085 2545 50  0001 C CNN
	1    2085 2545
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3235 2545 3365 2545
Connection ~ 3615 2545
Connection ~ 3365 2545
Wire Wire Line
	3365 2545 3615 2545
$Comp
L power:GNDA #PWR013
U 1 1 5F1FD2F8
P 3615 3255
F 0 "#PWR013" H 3615 3005 50  0001 C CNN
F 1 "GNDA" H 3620 3082 50  0000 C CNN
F 2 "" H 3615 3255 50  0001 C CNN
F 3 "" H 3615 3255 50  0001 C CNN
	1    3615 3255
	1    0    0    -1  
$EndComp
Wire Wire Line
	3615 2745 3615 3255
$Comp
L power:GNDA #PWR015
U 1 1 5F201A91
P 4215 3260
F 0 "#PWR015" H 4215 3010 50  0001 C CNN
F 1 "GNDA" H 4220 3087 50  0000 C CNN
F 2 "" H 4215 3260 50  0001 C CNN
F 3 "" H 4215 3260 50  0001 C CNN
	1    4215 3260
	1    0    0    -1  
$EndComp
Wire Wire Line
	4215 2945 4215 3260
$Comp
L power:GNDA #PWR018
U 1 1 5F2069CD
P 4655 3265
F 0 "#PWR018" H 4655 3015 50  0001 C CNN
F 1 "GNDA" H 4660 3092 50  0000 C CNN
F 2 "" H 4655 3265 50  0001 C CNN
F 3 "" H 4655 3265 50  0001 C CNN
	1    4655 3265
	1    0    0    -1  
$EndComp
Wire Wire Line
	4655 2945 4655 3265
$Comp
L power:GNDA #PWR022
U 1 1 5F20C7C4
P 4995 3265
F 0 "#PWR022" H 4995 3015 50  0001 C CNN
F 1 "GNDA" H 5000 3092 50  0000 C CNN
F 2 "" H 4995 3265 50  0001 C CNN
F 3 "" H 4995 3265 50  0001 C CNN
	1    4995 3265
	1    0    0    -1  
$EndComp
Wire Wire Line
	4995 2740 4995 2745
Connection ~ 4995 2745
Wire Wire Line
	4995 2745 4995 3265
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
L power:GNDA #PWR04
U 1 1 5F234ADB
P 735 6565
F 0 "#PWR04" H 735 6315 50  0001 C CNN
F 1 "GNDA" H 740 6392 50  0000 C CNN
F 2 "" H 735 6565 50  0001 C CNN
F 3 "" H 735 6565 50  0001 C CNN
	1    735  6565
	1    0    0    -1  
$EndComp
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
Text Notes 7070 6880 0    197  ~ 39
Flake Technologies (?)\n
Text Notes 7105 7105 0    79   ~ 16
Michael Madi\n
Text Notes 7350 7510 0    79   ~ 16
Rave Lights Main Board\n
Wire Wire Line
	5525 2325 5525 2330
Wire Wire Line
	5430 2545 5525 2545
Connection ~ 5525 2330
Wire Wire Line
	5525 2330 5525 2545
Wire Wire Line
	2615 2745 2615 3170
$Comp
L Device:Ferrite_Bead_Small FB1
U 1 1 5F30A8DC
P 2985 3170
F 0 "FB1" V 2748 3170 50  0000 C CNN
F 1 "?" V 2839 3170 50  0000 C CNN
F 2 "" V 2915 3170 50  0001 C CNN
F 3 "~" H 2985 3170 50  0001 C CNN
	1    2985 3170
	0    1    1    0   
$EndComp
Connection ~ 2615 3170
Wire Wire Line
	2615 3170 2615 3265
Wire Wire Line
	3365 2745 3365 3170
Wire Wire Line
	2615 3170 2885 3170
Wire Wire Line
	3085 3170 3365 3170
Connection ~ 3365 3170
Wire Wire Line
	3365 3170 3365 3255
Wire Wire Line
	4515 2545 4655 2545
Wire Wire Line
	4655 2545 4995 2545
Connection ~ 4655 2545
Connection ~ 4995 2545
Wire Wire Line
	4655 2540 4655 2060
$Comp
L Device:D_Zener D1
U 1 1 5F336FEA
P 3720 2060
F 0 "D1" H 3760 1865 50  0000 R CNN
F 1 "1N5819" H 3845 1965 50  0000 R CNN
F 2 "" H 3720 2060 50  0001 C CNN
F 3 "~" H 3720 2060 50  0001 C CNN
	1    3720 2060
	-1   0    0    1   
$EndComp
Wire Wire Line
	3870 2060 4655 2060
Wire Wire Line
	3570 2060 955  2060
Wire Wire Line
	955  2060 955  2545
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
$Comp
L power:GNDA #PWR05
U 1 1 5F38954F
P 910 5235
F 0 "#PWR05" H 910 4985 50  0001 C CNN
F 1 "GNDA" H 915 5062 50  0000 C CNN
F 2 "" H 910 5235 50  0001 C CNN
F 3 "" H 910 5235 50  0001 C CNN
	1    910  5235
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR011
U 1 1 5F38C701
P 2830 5235
F 0 "#PWR011" H 2830 4985 50  0001 C CNN
F 1 "GNDA" H 2835 5062 50  0000 C CNN
F 2 "" H 2830 5235 50  0001 C CNN
F 3 "" H 2830 5235 50  0001 C CNN
	1    2830 5235
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR07
U 1 1 5F38CB69
P 2060 5225
F 0 "#PWR07" H 2060 4975 50  0001 C CNN
F 1 "GNDA" H 2065 5052 50  0000 C CNN
F 2 "" H 2060 5225 50  0001 C CNN
F 3 "" H 2060 5225 50  0001 C CNN
	1    2060 5225
	1    0    0    -1  
$EndComp
Wire Wire Line
	3615 2545 3915 2545
Wire Wire Line
	3915 2645 3915 3110
Text Label 3915 3110 1    50   ~ 0
MAIN_POWER
Connection ~ 5985 3650
Wire Wire Line
	5985 3645 5985 3650
Wire Wire Line
	5835 3645 5985 3645
Wire Wire Line
	5985 3650 6295 3650
Wire Wire Line
	6295 3650 7515 3650
Connection ~ 6295 3650
$Comp
L Device:C_Small C10
U 1 1 5EC62A87
P 5985 3750
F 0 "C10" H 5915 3970 50  0000 L CNN
F 1 "10uf" H 5905 3900 50  0000 L CNN
F 2 "" H 5985 3750 50  0001 C CNN
F 3 "~" H 5985 3750 50  0001 C CNN
	1    5985 3750
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C11
U 1 1 5EC989DA
P 6295 3750
F 0 "C11" H 6235 3970 50  0000 L CNN
F 1 ".1uf" H 6235 3900 50  0000 L CNN
F 2 "" H 6295 3750 50  0001 C CNN
F 3 "~" H 6295 3750 50  0001 C CNN
	1    6295 3750
	1    0    0    -1  
$EndComp
Text Label 6450 4365 0    50   ~ 0
LED
Text Label 6450 4065 0    50   ~ 0
MIC_IN
Text Label 6450 4165 0    50   ~ 0
TEMP_SENSE
Wire Wire Line
	6450 4165 6915 4165
Wire Wire Line
	6450 4365 6915 4365
Wire Wire Line
	6450 4065 6915 4065
Wire Wire Line
	6915 4265 6450 4265
Text Label 6450 4265 0    50   ~ 0
MODE
Wire Wire Line
	8115 4165 8580 4165
Text Label 8580 4165 2    50   ~ 0
PACK_SENSE
Text Label 8585 4265 2    50   ~ 0
MAIN_POWER
Wire Wire Line
	7515 5165 7515 5245
Wire Wire Line
	5985 3850 5985 3960
Wire Wire Line
	6295 3850 6295 3960
Wire Wire Line
	5835 3645 5835 3375
$Comp
L power:+5V #PWR024
U 1 1 5EF1FE62
P 5835 3375
F 0 "#PWR024" H 5835 3225 50  0001 C CNN
F 1 "+5V" H 5850 3548 50  0000 C CNN
F 2 "" H 5835 3375 50  0001 C CNN
F 3 "" H 5835 3375 50  0001 C CNN
	1    5835 3375
	1    0    0    -1  
$EndComp
Wire Wire Line
	8115 4065 8580 4065
Text Label 8580 4065 2    50   ~ 0
PRMG
$Comp
L Device:R_Small R8
U 1 1 5F2B9B1E
P 9025 4375
F 0 "R8" H 9090 4345 50  0000 L CNN
F 1 "1M" H 9095 4410 50  0000 L CNN
F 2 "" H 9025 4375 50  0001 C CNN
F 3 "~" H 9025 4375 50  0001 C CNN
	1    9025 4375
	-1   0    0    1   
$EndComp
Wire Wire Line
	9025 4265 9025 4275
Wire Wire Line
	8115 4265 9025 4265
$Comp
L power:GNDA #PWR028
U 1 1 5F2D1230
P 9025 5260
F 0 "#PWR028" H 9025 5010 50  0001 C CNN
F 1 "GNDA" H 9030 5087 50  0000 C CNN
F 2 "" H 9025 5260 50  0001 C CNN
F 3 "" H 9025 5260 50  0001 C CNN
	1    9025 5260
	1    0    0    -1  
$EndComp
Wire Wire Line
	9025 4475 9025 5260
$Comp
L power:GNDA #PWR025
U 1 1 5F2DDF4B
P 5985 3960
F 0 "#PWR025" H 5985 3710 50  0001 C CNN
F 1 "GNDA" H 5990 3787 50  0000 C CNN
F 2 "" H 5985 3960 50  0001 C CNN
F 3 "" H 5985 3960 50  0001 C CNN
	1    5985 3960
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR026
U 1 1 5F2E1016
P 6295 3960
F 0 "#PWR026" H 6295 3710 50  0001 C CNN
F 1 "GNDA" H 6300 3787 50  0000 C CNN
F 2 "" H 6295 3960 50  0001 C CNN
F 3 "" H 6295 3960 50  0001 C CNN
	1    6295 3960
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR027
U 1 1 5F2E1CBF
P 7515 5245
F 0 "#PWR027" H 7515 4995 50  0001 C CNN
F 1 "GNDA" H 7520 5072 50  0000 C CNN
F 2 "" H 7515 5245 50  0001 C CNN
F 3 "" H 7515 5245 50  0001 C CNN
	1    7515 5245
	1    0    0    -1  
$EndComp
Wire Wire Line
	8680 4365 8680 3760
Wire Wire Line
	8115 4365 8680 4365
Text Label 8115 4365 0    50   ~ 0
Supply_Detect
$Comp
L MCU_Microchip_ATtiny:ATtiny814-SS U3
U 1 1 5EE6BDE9
P 7515 4465
F 0 "U3" H 6950 5180 50  0000 C CNN
F 1 "ATtiny814-SS" H 7165 5110 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 7515 4465 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/40001912A.pdf" H 7515 4465 50  0001 C CNN
	1    7515 4465
	1    0    0    -1  
$EndComp
Wire Wire Line
	7515 3760 7515 3765
Wire Wire Line
	7515 3650 7515 3760
Connection ~ 7515 3760
Wire Wire Line
	8680 3760 7515 3760
$EndSCHEMATC
