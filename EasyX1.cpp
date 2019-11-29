#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<graphics.h>
const int BRIGHT=0;
const double PI = 3.1415926;
typedef double datatype;
//���ģ��
typedef struct RainDrop {
	//�����ɫ
	char color;
	//��������̶�
	datatype visibility;
	//��εĿ�͸�
	datatype width;
	datatype height;
	//���x,y������ٶ�
	datatype v_y;
	datatype v_x;
}RainDrop;
//�õ�һ��������������index1��index2��ʾ����������ķ�Χ,��������������Χ
int CirJudgeZero(int index1, int index2)
{
	int rec = 0;
	while (rec == 0)
	{
		rec = rand() % index1 + index2;//����index1--index2��Χ�ڵ���
	}
	return rec;
}
//��ʼ�����
void init_RainDrop()
{

}
//��ʼ������
void init_Lighting(int x)
{
	int LightingTimes = CirJudgeZero(3, 0);//�������˫������
	int end_Pos;//���ڼ�¼������յ�
	for (int i = 0; i < LightingTimes; i++)
	{
		int Xpoint = x;
		int Ypoint = 480;
		end_Pos = Ypoint - rand() % 120 - 120;//���������յ�(�������y����)
		//����һ������
		while (Ypoint >= end_Pos)//�ж��Ƿ񵽴���������յ㲢�Ҳ��ϻ���ÿһ������
		{
			int Dis = rand() % 30;//ÿ������ĳ���
			int Ang1 = rand() % 120 - 60;//ÿ������ƫ�ƵĽǶȣ�x�ᣩ
			int Ang2 = rand() % 120 - 60;//ÿ������ƫ�ƵĽǶȣ�y�ᣩ
			int NextX = Xpoint + (int)(Dis * sin(Ang1 * PI / 180));					// ��������˵����һ��(x��)
			int NextY = Ypoint - (int)(Dis * cos(Ang2 * PI / 180));					// ��������˵����һ��(y��)


		
			setlinecolor(RGB(191,239,255));	//�������ɫ
			setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);//�������ʽ
			line(Xpoint, Ypoint, NextX, NextY);


			Xpoint = NextX;
			Ypoint = NextY;
			double sleep_time = rand() % 100 > 60 ? 20 : 10;
			Sleep(sleep_time);
		}
		Sleep(40);//�ڻ��Ƶڶ�������ǰ��ͣ20ms
	}
}
int main()
{

	srand((unsigned)time(NULL));//�����������
	initgraph(640, 480);	// ������ͼ���ڣ���СΪ 640x480 ����
	//ʵ���߼�������ķ�ת
	setorigin(0, 480);
	setaspectratio(1, -1);
	setbkcolor(RGB(20, 20, 20));//���ñ���ɫ
	cleardevice();//����


	int Xpoint;
	while (TRUE)
	{
		cleardevice();
		Xpoint = rand() % 590 + 50;//����x����
		init_Lighting(Xpoint);
		Sleep(50);
	}
	system("pause");
	closegraph();
	return 0;
}