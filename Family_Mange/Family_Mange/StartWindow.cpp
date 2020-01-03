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
void biaoti()//标题
{
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(100, 0, _T("楷体"));
	TCHAR s1[] = _T("家");
	outtextxy(230, 70, s1);
	TCHAR s2[] = _T("谱");
	outtextxy(180, 150, s2);
	settextstyle(40, 0, _T("楷体"));
	TCHAR s3[] = _T("管");
	outtextxy(260, 260, s3);
	TCHAR s4[] = _T("理");
	outtextxy(260, 300, s4);
	TCHAR s5[] = _T("系");
	outtextxy(260, 340, s5);
	TCHAR s6[] = _T("统");
	outtextxy(260, 380, s6);
	settextstyle(30, 0, _T("楷体"));
	TCHAR s7[] = _T("1.新创建家族谱树");
	outtextxy(400, 150, s7);
	TCHAR s8[] = _T("2.添加家谱树成员");
	outtextxy(400, 180, s8);
	TCHAR s9[] = _T("3.保存家谱信息到文件");
	outtextxy(400, 210, s9);
	TCHAR s10[] = _T("4.家谱信息可视化");
	outtextxy(400, 240, s10);
	TCHAR s11[] = _T("5.按姓名查找成员");
	outtextxy(400, 270, s11);
	TCHAR s12[] = _T("6.按性别查找成员");
	outtextxy(400, 300, s12);
	TCHAR s13[] = _T("7.按职业查找成员");
	outtextxy(400, 330, s13);
	TCHAR s14[] = _T("8.按学历查找成员");
	outtextxy(400, 360, s14);

}
void First_Window()//第一个界面
{
	biaoti();
	if (isMouseDown&&mouseX >= 400 && mouseX <= 1000)
	{
		//进入创建一个家谱树的功能
		if ( mouseY > 150 && mouseY < 180)
		{
			GamePhase = 1;
	
		}
		//进入将家谱树保存到文件的功能中
		if (mouseY > 210 && mouseY < 240)
		{
			GamePhase = 3;
	
		}
		//进入添加一个新成员的功能
		if (mouseY > 180 && mouseY < 210)
		{
			GamePhase = 2;
	
			stop1 = 0;
		}
		//进入家谱树可视化功能
		if (mouseY > 240 && mouseY < 270)
		{
			GamePhase = 4;

		}
		//进入查找姓名功能
		if (mouseY > 270 && mouseY < 300)
		{
			GamePhase = 5;
			stop2 = 0;
	
		}
		//进入查找性别功能
		if (mouseY > 300 && mouseY < 330)
		{
			GamePhase = 6;
			stop3 = 0;
	
		}
		//进入查找职业功能
		if (mouseY > 330 && mouseY < 360)
		{
			GamePhase = 7;
			stop4 = 0;
		}
		//进入查找学历功能
		if (mouseY > 360 && mouseY < 390)
		{
			GamePhase = 8;
			stop5 = 0;
		}
	}
}
