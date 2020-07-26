#include "main.h"
#include "GPS.h"
#include <reg52.h>
#define uchar unsigned char  
#define uchar unsigned char
	
typedef unsigned int u16;
typedef unsigned char u8;

unsigned char i,j,k,l;

sbit P0_0 = P0^0;
sbit P0_1 = P0^1;
sbit P0_2 = P0^2;
sbit P0_3 = P0^3;
sbit P0_4 = P0^4;
sbit P0_5 = P0^5;
sbit P0_6 = P0^6;
sbit P0_7 = P0^7;
sbit P1_0 = P1^0;
sbit P1_1 = P1^1;
sbit P1_2 = P1^2;
sbit P1_3 = P1^3;
sbit P1_4 = P1^4;
sbit P1_5 = P1^5;
sbit P1_6 = P1^6;
sbit P1_7 = P1^7;
sbit P2_0 = P2^0;
sbit P2_1 = P2^1;
sbit P2_2 = P2^2;
sbit P2_3 = P2^3;
sbit P2_4 = P2^4;
sbit P2_5 = P2^5;
sbit P2_6 = P2^6;
sbit P2_7 = P2^7;
sbit P3_0 = P3^0;
sbit P3_1 = P3^1;
sbit P3_2 = P3^2;
sbit P3_3 = P3^3;
sbit P3_4 = P3^4;
sbit P3_5 = P3^5;
sbit P3_6 = P3^6;
sbit P3_7 = P3^7;

unsigned char m;

unsigned char xdata Display_GPGGA_Buffer[68];
bit Flag_Calc_GPGGA_OK = 0;

void display0()
{
	u8 j;
	j = Hour%10;
	switch(j)
	{
		case(0):
			P0_0 = 0; P0_1 = 0; P0_2 = 0; P0_3 = 0; P0_4 = 0; P0_5 = 0; P0_6 = 1; P0_7 = 1; break;
		case(1):
			P0_0 = 1; P0_1 = 0; P0_2 = 0; P0_3 = 1; P0_4 = 1; P0_5 = 1; P0_6 = 1; P0_7 = 1; break;
		case(2):
			P0_0 = 0; P0_1 = 0; P0_2 = 1; P0_3 = 0; P0_4 = 0; P0_5 = 1; P0_6 = 0; P0_7 = 1; break;
		case(3):
			P0_0 = 0; P0_1 = 0; P0_2 = 0; P0_3 = 0; P0_4 = 1; P0_5 = 1; P0_6 = 0; P0_7 = 1; break;
		case(4):
			P0_0 = 1; P0_1 = 0; P0_2 = 0; P0_3 = 1; P0_4 = 1; P0_5 = 0; P0_6 = 0; P0_7 = 1; break;
			break;
	}
}

void display1()
{
	u8 l;
	l = Min_Low;
	switch(l)
	{
		case(0):
			P1_0 = 0; P1_1 = 0; P1_2 = 0; P1_3 = 0; P1_4 = 0; P1_5 = 0; P1_6 = 1; P1_7 = 0; break;
		case(1):
			P1_0 = 1; P1_1 = 0; P1_2 = 0; P1_3 = 1; P1_4 = 1; P1_5 = 1; P1_6 = 1; P1_7 = 0; break;
		case(2):
			P1_0 = 0; P1_1 = 0; P1_2 = 1; P1_3 = 0; P1_4 = 0; P1_5 = 1; P1_6 = 0; P1_7 = 0; break;
		case(3):
			P1_0 = 0; P1_1 = 0; P1_2 = 0; P1_3 = 0; P1_4 = 1; P1_5 = 1; P1_6 = 0; P1_7 = 0; break;
		case(4):
			P1_0 = 1; P1_1 = 0; P1_2 = 0; P1_3 = 1; P1_4 = 1; P1_5 = 0; P1_6 = 0; P1_7 = 0; break;
		case(5):
			P1_0 = 0; P1_1 = 1; P1_2 = 0; P1_3 = 0; P1_4 = 1; P1_5 = 0; P1_6 = 0; P1_7 = 0; break;
		case(6):
			P1_0 = 0; P1_1 = 1; P1_2 = 0; P1_3 = 0; P1_4 = 0; P1_5 = 0; P1_6 = 0; P1_7 = 0; break;
		case(7):
			P1_0 = 0; P1_1 = 0; P1_2 = 0; P1_3 = 1; P1_4 = 1; P1_5 = 1; P1_6 = 1; P1_7 = 0; break;
		case(8):
			P1_0 = 0; P1_1 = 0; P1_2 = 0; P1_3 = 0; P1_4 = 0; P1_5 = 0; P1_6 = 0; P1_7 = 0; break;
		case(9):
			P1_0 = 0; P1_1 = 0; P1_2 = 0; P1_3 = 0; P1_4 = 1; P1_5 = 0; P1_6 = 0; P1_7 = 0; break;
		default:
			break;
	}
}

void display2()
{
	u8 k;
	k = Min_High;
	switch(k)
	{
		case(0):
			P2_0 = 0; P2_1 = 0; P2_2 = 0; P2_3 = 0; P2_4 = 0; P2_5 = 0; P2_6 = 1; P2_7 = 1; break;
		case(1):
			P2_0 = 1; P2_1 = 0; P2_2 = 0; P2_3 = 1; P2_4 = 1; P2_5 = 1; P2_6 = 1; P2_7 = 1; break;
		case(2):
			P2_0 = 0; P2_1 = 0; P2_2 = 1; P2_3 = 0; P2_4 = 0; P2_5 = 1; P2_6 = 0; P2_7 = 1; break;
		case(3):
			P2_0 = 0; P2_1 = 0; P2_2 = 0; P2_3 = 0; P2_4 = 1; P2_5 = 1; P2_6 = 0; P2_7 = 1; break;
		case(4):
			P2_0 = 1; P2_1 = 0; P2_2 = 0; P2_3 = 1; P2_4 = 1; P2_5 = 0; P2_6 = 0; P2_7 = 1; break;
		case(5):
			P2_0 = 0; P2_1 = 1; P2_2 = 0; P2_3 = 0; P2_4 = 1; P2_5 = 0; P2_6 = 0; P2_7 = 1; break;
		case(6):
			P2_0 = 0; P2_1 = 1; P2_2 = 0; P2_3 = 0; P2_4 = 0; P2_5 = 0; P2_6 = 0; P2_7 = 1; break;
		default:
			break;
	}
}

void display3()//P3.0<->P3.7    P3.1<->P1.7
{
	u8 i;
	i = Hour/10;
	switch(i)
	{
		case(0):
			P3_0 = 1; P3_1 = 0; P3_2 = 0; P3_3 = 0; P3_4 = 0; P3_5 = 0; P3_6 = 1; P3_7 = 0; break;
		case(1):
			P3_0 = 1; P3_1 = 0; P3_2 = 0; P3_3 = 1; P3_4 = 1; P3_5 = 1; P3_6 = 1; P3_7 = 1; break;
		case(2):
			P3_0 = 1; P3_1 = 0; P3_2 = 1; P3_3 = 0; P3_4 = 0; P3_5 = 1; P3_6 = 0; P3_7 = 0; break;
		default:
			break;
	}
}

void main()
{
	unsigned char i = 0;

	Uart_Init();

	while(1)
	{
		if(Flag_GPS_OK == 1 && RX_Buffer[4] == 'G' && RX_Buffer[6] == ',' && RX_Buffer[13] == '.')
		{
			for( i = 0; i < 68 ; i++)
			{
				Display_GPGGA_Buffer[i] = RX_Buffer[i];	
			}
			Hour = (Display_GPGGA_Buffer[7]-0x30)*10+(Display_GPGGA_Buffer[8]-0x30)+8;   //China Standard Time    UTC + 08:00

			if( Hour >= 24)
			{
				Hour %= 24;
			}

			Min_High = Display_GPGGA_Buffer[9]-0x30;
			Min_Low = Display_GPGGA_Buffer[10]-0x30;
	
			Sec_High = Display_GPGGA_Buffer[11];
			Sec_Low = Display_GPGGA_Buffer[12];

			Flag_Calc_GPGGA_OK = 1;
		}
		
			Flag_Calc_GPGGA_OK = 0;
			display0();
			display1();
			display2();
			display3();
	}
}