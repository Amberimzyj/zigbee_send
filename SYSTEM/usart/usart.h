#ifndef __USART_H
#define __USART_H
#include "stdio.h"
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEK STM32������
//����1��ʼ��
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/8/18
//�汾��V1.5
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved
//********************************************************************************
//V1.3�޸�˵��
//֧����Ӧ��ͬƵ���µĴ��ڲ���������.
//�����˶�printf��֧��
//�����˴��ڽ��������.
//������printf��һ���ַ���ʧ��bug
//V1.4�޸�˵��
//1,�޸Ĵ��ڳ�ʼ��IO��bug
//2,�޸���USART_RX_STA,ʹ�ô����������ֽ���Ϊ2��14�η�
//3,������USART_REC_LEN,���ڶ��崮�����������յ��ֽ���(������2��14�η�)
//4,�޸���EN_USART1_RX��ʹ�ܷ�ʽ
//V1.5�޸�˵��
//1,�����˶�UCOSII��֧��
#define USART_REC_LEN           200     //�����������ֽ��� 200
#define EN_USART3_RX            1       //ʹ�ܣ�1��/��ֹ��0������1����

extern u16 USART3_RX_BUF[200]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з�
extern u16 USART3_RX_STA;               //����״̬���
//����봮���жϽ��գ��벻Ҫע�����º궨��
void usart3_init(u32 bound);

//#define USART_REC_LEN           200     //�����������ֽ��� 200
#define EN_USART2_RX            1       //ʹ�ܣ�1��/��ֹ��0������1����

extern u16  USART2_RX_BUF[200]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з�
extern u16 USART2_RX_STA;               //����״̬���
//����봮���жϽ��գ��벻Ҫע�����º궨��
void usart2_init(u32 bound);

#define EN_USART1_RX            1       //ʹ�ܣ�1��/��ֹ��0������1����

extern u16  USART1_RX_BUF[200]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з�
extern u16 USART1_RX_STA;               //����״̬���

// extern u8 usartrece[13];
//����봮���жϽ��գ��벻Ҫע�����º궨��
void usart1_init(u32 bound);

u8 USART_GetChar(USART_TypeDef* USARTx);
extern u8 flag;
extern u8 data[13];
void USART_PutChar(USART_TypeDef* USARTx, uint8_t Data);
void USART_PutStr(USART_TypeDef* USARTx, uint8_t *str);   //�򴮿ڷ�������
void PutCharTemp(float data);
void PutCharHumid(float data);
void PutCharLight(float data);
#endif


