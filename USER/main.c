#include "stm32f10x.h"
#include "sys.h"
#include "usart.h"
#include "led.h"
#include "delay.h"
#include "myiic.h"
#include "myiic1.h"
#include "AM2320.h"
#include "GY-30.h"
#include "ESP8266.h"
//#include "DL_LN3X.h"
#include "DL_LN33_Send.h"
#include "DL_LN33_Rece.h"





int main(void)
{

    u16 times = 0;
    u16 temp;
    float temp1;
    u16 humid;
    float humid1;
    u32 data;
    u16 light;
    float light1;
    char a[] = "temp";
    char b[] = "humid";
    char c[] = "light";

    delay_init();
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);  //����NVIC�жϷ���2
    usart3_init(115200);    //���ڳ�ʼ��������
    usart2_init(115200);    //���ڳ�ʼ��������
    usart1_init(115200);    //���ڳ�ʼ��������
    LED_Init();       //LED�˿ڳ�ʼ��
    AM2320_Init();    //��ʼ����ʪ��IIC
    IIC_Init1();    //��ʼ������IIC
    GY_30_Init();  //��ʼ��GY-30
    delay_ms(30);
    TCP_Con();
    USART_PutStr(USART2, "\r\n");


    while (1)
    {

        GY_30_SendMode(0x01);  //�ϵ�
        GY_30_SendMode(0x10);  //����Ϊ�����߷ֱ���ģʽ
        delay_ms(180);  //�����ʱ180ms

        //���Ѵ����������Ͷ�ָ��
        AM2320_Wakeup();
        AM2320_Send_Read();
        delay_ms(3);

        //����ȡ������ת��Ϊ��ǿ
        light = GY_30_Read();
        light1 = light / 1.2;

        //����ȡ������ת��Ϊ�ٽ�����ʪ��
        data = AM2320_Read() ;
        humid = data >> 16;
        humid1 = humid / 10.0; //((humid / 256) * 256 + ((humid % 256) / 16) * 16 + ((humid % 256) % 16)) * 1.0 / 10;
        temp = data;
        temp1 = temp / 10.0; //(temp / 256) * 256 + ((temp % 256) / 16) * 16 + ((temp % 256) % 16)) * 1.0 / 10;

        times++;
        if (times % 1 == 0)
        {
            LED0 = !LED0;
            times = 0;
        }


        // delay_ms(1000);
        // delay_ms(1000);

        // PutCharTemp(temp1);
        // delay_ms(1000);
        // PutCharHumid(humid1);
        // delay_ms(1000);
        // PutCharLight(light1);
        // delay_ms(1000);
        // USART_PutStr(USART2, "\r\n");
        // USART_PutStr(USART2, "This is a test!\r\n");

//��������Ϣͨ��zigbee����
        SendInfo(temp, humid, light);

        // DealData();
        delay_ms(1000);
        delay_ms(1000);


    }

}

