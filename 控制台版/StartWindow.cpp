#include"Family.h"
#include<Windows.h>
//标题
void biaoti(/*int x, int y, int nHeight, int nWidth*/)
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
	TCHAR s12[] = _T("6.按关键字查找成员");
	outtextxy(400, 300, s12);
	TCHAR s13[] = _T("7.统计家谱成员信息");
	outtextxy(400, 330, s13);
	TCHAR s14[] = _T("8.退出系统");
	outtextxy(400, 360, s14);

	printf("12312132");
}

//void First_Window()//第一个界面
//{
//	person T;
//	char s[] = "JiaPu.txt";
//	T = creat(s);
//	initgraph(952, 536);
//	loadimage(NULL, _T("1.jpg"));
//	biaoti(100, 200, 100, 100);
//	MOUSEMSG m;		// 定义鼠标消息
//	while (true)
//	{
//		// 获取一条鼠标消息
//		m = GetMouseMsg();
//		//printf("%d %d", m.x, m.y);
//		//switch (m.uMsg)
//		//{
//		//case WM_LBUTTONDOWN:
//		//	/*if(m.y=150)
//
//		//		return person creat( char *fileName)/;
//		//	  */
//		//	if (m.y > 180 && m.x > 400 && m.y < 209 && m.x < 600)
//		//	{
//		//		//MOUSEMSG GetMouseMsg();
//		//		AddNewNode(T);
//		//	}
//		//	/*if(m.y>210&&m.y<239)
//		//	if(m.y>240&&m.y<269)
//		//	if(m.y>270&&m.y<299)
//		//	if(m.y>300&&m.y<329)
//		//	if(m.y>180&&m.y<209)
//		//	if(m.y>180&&m.y<209)*/
//		//	break;
//		//case WM_RBUTTONUP:
//		//	return;	// 按鼠标右键退出程序
//
//		//}
//		if (m.uMsg == WM_LBUTTONDOWN&&m.y < 500 && m.y>0 && m.x < 800 &&m. x>0)
//		{
//
//			AddNewNode(T);
//			/*int x = m.x;
//			int y = m.y;*/
//			/*if((y<500&&y>0)&&(x<800&&x>0))*/
//			//if (y > 180 && x > 400 && y < 209 &&x < 600)
//			/*{
//				
//			}*/
//		}
//	}
//
//	_getch();
//	closegraph();
//}
//int  main()
//{
//
//	First_Window();
//	return 0;
//}

//int main()
//{
//	initgraph(952, 536,SHOWCONSOLE);
//	setbkmode(TRANSPARENT);
//	settextcolor(WHITE);
//	settextstyle(20, 0, _T("楷体"));
//	menu1();
//	while (1)
//	{
//		Mouse_Pos();
//	}
//	
//	_getch();
//	closegraph();
//	system("pause");
//	return 0;
//}
void Mouse_Pos()
{
	MOUSEMSG m;
	m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE)
		{
			char s[12];
			setfillcolor(BLACK);
			solidrectangle(0, 0, 75, 20);
			sprintf(s, "[%d,%d]", m.x, m.y);
			outtextxy(0, 0, s);
		}
}