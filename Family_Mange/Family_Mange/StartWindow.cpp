#include"Family.h"
#include"global.h"
extern int GamePhase;
extern int mouseX;
extern int mouseY;
extern bool isMouseDown;
extern person T;
extern int stop1 ;
extern int stop2 ;
extern int stop3 ;
void biaoti()//����
{
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(100, 0, _T("����"));
	TCHAR s1[] = _T("��");
	outtextxy(230, 70, s1);
	TCHAR s2[] = _T("��");
	outtextxy(180, 150, s2);
	settextstyle(40, 0, _T("����"));
	TCHAR s3[] = _T("��");
	outtextxy(260, 260, s3);
	TCHAR s4[] = _T("��");
	outtextxy(260, 300, s4);
	TCHAR s5[] = _T("ϵ");
	outtextxy(260, 340, s5);
	TCHAR s6[] = _T("ͳ");
	outtextxy(260, 380, s6);
	settextstyle(30, 0, _T("����"));
	TCHAR s7[] = _T("1.�´�����������");
	outtextxy(400, 150, s7);
	TCHAR s8[] = _T("2.��Ӽ�������Ա");
	outtextxy(400, 180, s8);
	TCHAR s9[] = _T("3.���������Ϣ���ļ�");
	outtextxy(400, 210, s9);
	TCHAR s10[] = _T("4.������Ϣ���ӻ�");
	outtextxy(400, 240, s10);
	TCHAR s11[] = _T("5.���������ҳ�Ա");
	outtextxy(400, 270, s11);
	TCHAR s12[] = _T("6.���Ա���ҳ�Ա");
	outtextxy(400, 300, s12);
	TCHAR s13[] = _T("7.��ְҵ���ҳ�Ա");
	outtextxy(400, 330, s13);
	TCHAR s14[] = _T("8.��ѧ�����ҳ�Ա");
	outtextxy(400, 360, s14);

}
void First_Window()//��һ������
{
	biaoti();
	if (isMouseDown&&mouseX >= 400 && mouseX <= 1000)
	{
		//���봴��һ���������Ĺ���
		if ( mouseY > 150 && mouseY < 180)
		{
			GamePhase = 1;
	
		}
		//���뽫���������浽�ļ��Ĺ�����
		if (mouseY > 210 && mouseY < 240)
		{
			GamePhase = 3;
	
		}
		//�������һ���³�Ա�Ĺ���
		if (mouseY > 180 && mouseY < 210)
		{
			GamePhase = 2;
	
			stop1 = 0;
		}
		//������������ӻ�����
		if (mouseY > 240 && mouseY < 270)
		{
			GamePhase = 4;

		}
		//���������������
		if (mouseY > 270 && mouseY < 300)
		{
			GamePhase = 5;
			stop2 = 0;
	
		}
		//��������Ա���
		if (mouseY > 300 && mouseY < 330)
		{
			GamePhase = 6;
			stop3 = 0;
	
		}
		//�������ְҵ����
		if (mouseY > 330 && mouseY < 360)
		{
			GamePhase = 7;
			stop4 = 0;
		}
		//�������ѧ������
		if (mouseY > 360 && mouseY < 390)
		{
			GamePhase = 8;
			stop5 = 0;
		}
	}
}
