#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<graphics.h>
const int BRIGHT=0;
const double PI = 3.1415926;
typedef double datatype;
//雨滴模型
typedef struct RainDrop {
	//雨滴颜色
	char color;
	//雨滴清晰程度
	datatype visibility;
	//雨滴的宽和高
	datatype width;
	datatype height;
	//雨滴x,y方向的速度
	datatype v_y;
	datatype v_x;
}RainDrop;
//得到一个非零的随机数，index1，index2表示出现随机数的范围,不包括这两个范围
int CirJudgeZero(int index1, int index2)
{
	int rec = 0;
	while (rec == 0)
	{
		rec = rand() % index1 + index2;//产生index1--index2范围内的数
	}
	return rec;
}
//初始化雨滴
void init_RainDrop()
{

}
//初始化闪电
void init_Lighting(int x)
{
	int LightingTimes = CirJudgeZero(3, 0);//随机出现双重闪电
	int end_Pos;//用于记录闪电的终点
	for (int i = 0; i < LightingTimes; i++)
	{
		int Xpoint = x;
		int Ypoint = 480;
		end_Pos = Ypoint - rand() % 120 - 120;//随机闪电的终点(闪电最长的y坐标)
		//绘制一条闪电
		while (Ypoint >= end_Pos)//判断是否到达了闪电的终点并且不断绘制每一段闪电
		{
			int Dis = rand() % 30;//每段闪电的长度
			int Ang1 = rand() % 120 - 60;//每段闪电偏移的角度（x轴）
			int Ang2 = rand() % 120 - 60;//每段闪电偏移的角度（y轴）
			int NextX = Xpoint + (int)(Dis * sin(Ang1 * PI / 180));					// 计算闪电端点的下一点(x轴)
			int NextY = Ypoint - (int)(Dis * cos(Ang2 * PI / 180));					// 计算闪电端点的下一点(y轴)


		
			setlinecolor(RGB(191,239,255));	//闪电的颜色
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);//闪电的样式
			line(Xpoint, Ypoint, NextX, NextY);


			Xpoint = NextX;
			Ypoint = NextY;
			double sleep_time = rand() % 100 > 60 ? 20 : 10;
			Sleep(sleep_time);
		}
		Sleep(40);//在绘制第二条闪电前暂停20ms
	}
}
int main()
{

	srand((unsigned)time(NULL));//设置随机种子
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	//实现逻辑坐标轴的反转
	setorigin(0, 480);
	setaspectratio(1, -1);
	setbkcolor(RGB(20, 20, 20));//设置背景色
	cleardevice();//清屏


	int Xpoint;
	while (TRUE)
	{
		cleardevice();
		Xpoint = rand() % 590 + 50;//闪电x坐标
		init_Lighting(Xpoint);
		Sleep(50);
	}
	system("pause");
	closegraph();
	return 0;
}