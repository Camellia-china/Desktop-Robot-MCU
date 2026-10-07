#include <reg52.h>

// L298N电机引脚定义
sbit IN1 = P1 ^ 0;
sbit IN2 = P1 ^ 1;
sbit IN3 = P1 ^ 2;
sbit IN4 = P1 ^ 3;

// 红外避障传感器
sbit IR_Sensor = P2 ^ 0;

// 前进
void Forward(void)
{
    IN1 = 1; IN2 = 0;
    IN3 = 1; IN4 = 0;
}
//后退
void Back(void)
{
    IN1 = 0; IN2 = 1;
    IN3 = 0; IN4 = 1;
}
//左转
void Left(void)
{
    IN1 = 0; IN2 = 1;
    IN3 = 1; IN4 = 0;
}
//右转
void Right(void)
{
    IN1 = 1; IN2 = 0;
    IN3 = 0; IN4 = 1;
}
//停止
void Stop(void)
{
    IN1 = 0; IN2 = 0;
    IN3 = 0; IN4 = 0;
}

void Delay_ms(unsigned int t)
{
    unsigned int i, j;
    for (i = t; i > 0; i--)
        for (j = 110; j > 0; j--);
}

void main(void)
{
    while (1)
    {
        if (IR_Sensor == 0) //检测到障碍物
        {
            Stop();
            Delay_ms(300);
            Back();
            Delay_ms(500);
            Left();
            Delay_ms(400);
        }
        else
        {
            Forward();
        }
    }
}