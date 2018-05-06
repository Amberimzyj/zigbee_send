/*
* @Author: Amberimzyj
* @Date:   2018-04-18 12:13:51
* @Last Modified by:   Amberimzyj
* @Last Modified time: 2018-04-19 14:16:44
*/
#include "DL_LN33_Rece.h"
#include "sys.h"
#include "delay.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "usart.h"



char str_2[] = "f1";
char str_3[] = "f2";
char str_4[] = "f3";
char str_5[] = "f4";

// u8 data[6] = {0};

//void ReadData(void)
//{

////    u8 data[6] = {0};
//    if (USART_GetChar(USART1) == 0xFF)
//    {

//        if (USART_GetChar(USART1) == 0xFE)
//        {
//            for (u8 i = 0; i < 5; i++)
//            {
//                USART_GetChar(USART1);
//            }
//            for (u8 t = 0; t < 6; t++)
//            {
//                data[t] = USART_GetChar(USART1);
//            }
//        }
//    }
//}
float f1data[3] = {0};
float f2data[3] = {0};
float f3data[3] = {0};
float f4data[3] = {0};

void DealData(void)
{
    // u8 data[6]={0};
    // ReadData();
    u16 data1 = 0;
    float data2 = 0;
    if (data[4] == 0x1F)
    {

        data1 = data[6];
        data1 <<= 8;
        data1 |= data[7];
        data2 = data1 / 10.0;
        f1data[0] = data2;

        data1 = data[8];
        data1 <<= 8;
        data1 |= data[9];
        data2 = data1 / 10.0;
        f1data[1] = data2;

        data1 = data[10];
        data1 <<= 8;
        data1 |= data[11];
        data2 = data1 / 1.2;
        f1data[2] = data2;

        printf("\r\n当前数据来自F1节点\r\n");
        printf("\r\n当前温度为：%g ℃\r\n", f1data[0] );
        printf("\r\n当前湿度为：%g %%RH\r\n", f1data[1]);
        printf("\r\n当前光强为：%g lx\r\n\r\n", f1data[2]);
    }
    else if (data[4] == 0x2F)
    {

        data1 = data[6];
        data1 <<= 8;
        data1 |= data[7];
        data2 = data1 / 10.0;
        f2data[0] = data2;

        data1 = data[8];
        data1 <<= 8;
        data1 |= data[9];
        data2 = data1 / 10.0;
        f2data[1] = data2;

        data1 = data[10];
        data1 <<= 8;
        data1 |= data[11];
        data2 = data1 / 1.2;
        f2data[2] = data2;

        printf("\r\n当前数据来自F2节点r\n");
        printf("\r\n当前温度为：%g ℃\r\n", f2data[0] );
        printf("\r\n当前湿度为：%g %%RH\r\n", f2data[1]);
        printf("\r\n当前光强为：%g lx\r\n\r\n", f2data[2]);
    }
    else if (data[4] == 0x3F)
    {

        data1 = data[6];
        data1 <<= 8;
        data1 |= data[7];
        data2 = data1 / 10.0;
        f3data[0] = data2;

        data1 = data[8];
        data1 <<= 8;
        data1 |= data[9];
        data2 = data1 / 10.0;
        f3data[1] = data2;

        data1 = data[10];
        data1 <<= 8;
        data1 |= data[11];
        data2 = data1 / 1.2;
        f3data[2] = data2;

        printf("\r\n当前数据来自F3节点r\n");
        printf("\r\n当前温度为：%g ℃\r\n", f3data[0] );
        printf("\r\n当前湿度为：%g %%RH\r\n", f3data[1]);
        printf("\r\n当前光强为：%g lx\r\n\r\n", f3data[2]);
    }
    else if (data[4] == 0x4F)
    {

        data1 = data[6];
        data1 <<= 8;
        data1 |= data[7];
        data2 = data1 / 10.0;
        f4data[0] = data2;

        data1 = data[8];
        data1 <<= 8;
        data1 |= data[9];
        data2 = data1 / 10.0;
        f4data[1] = data2;

        data1 = data[10];
        data1 <<= 8;
        data1 |= data[11];
        data2 = data1 / 1.2;
        f4data[2] = data2;

        printf("\r\n当前数据来自F4节点r\n");
        printf("\r\n当前温度为：%g ℃\r\n", f4data[0] );
        printf("\r\n当前湿度为：%g %%RH\r\n", f4data[1]);
        printf("\r\n当前光强为：%g lx\r\n\r\n", f4data[2]);
    }
}

