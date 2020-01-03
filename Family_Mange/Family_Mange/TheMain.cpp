#include"Family.h"
#include"global.h"
person T = NULL;
int main()
{
	GamePhase = 0;
	initgraph(952, 536);
	loadimage(NULL, _T("1.jpg"));
	SetWindowText(GetHWnd(), _T("家谱系统By:曹汶 张志辉 张洋 吕昊"));
	MOUSEMSG msg;
	while (1)
	{
		while (MouseHit())
		{
			msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_MOUSEMOVE:
				mouseX = msg.x;
				mouseY = msg.y;
				break;
			case WM_LBUTTONUP:
				isMouseDown = false;
				break;
			case WM_LBUTTONDOWN:
				isMouseDown = true;
				break;
			}
		}
		windows();
		Sleep(150);
	}
	_getch();
	closegraph();
}
void windows()
{	
	char p[20] = "JiaPu.txt";
	//清屏
	loadimage(NULL, _T("1.jpg"));
	switch (GamePhase)
	{
	case 0://主菜单界面
		First_Window();
		break;
	case 1:	//创建家谱图界面
		creat(p);
		break;
	case 2:	//添加新成员界面
		AddNewNode();
		break;
	case 3://保存到文件的界面
		save(T);
		break;
	case 4://树的可视化界面
		view(T);
		break;
	case 5://查找姓名界面
		if (stop2 == 0)
		{
			InputBox(search_name, 20, "请输入要查找的姓名：");
		}
		Find_name(search_name);
		break;
	case 6://查找性别界面
		if (stop3 == 0)
		{
			InputBox(search_sex, 20, "请输入要查找的性别：");
		}
		Find_sex(search_sex);
		break;
	case 7://查找职业界面
		if (stop4 == 0)
		{
			InputBox(search_occupation, 20, "请输入要查找的职业：");
		}
		Find_occupation(search_occupation);
		break;
	case 8://查找学历界面
		if (stop5 == 0)
		{
			InputBox(search_education, 20, "请输入要查找的学历：");
		}
		Find_education(search_education);
		break;
	}
}
void ExitButton()
{
	if (isMouseDown&&mouseX < 85 && mouseX>0 && mouseY < 35 && mouseY>0)
	{
		GamePhase = 0;
	}
	else
	{
		//设置返回主菜单按纽
		setfillcolor(RGB(240, 248, 255));
		setlinecolor(RGB(119, 136, 153));
		fillrectangle(0, 0, 80, 30);
		settextstyle(15, 0, _T("楷体"));
		TCHAR s0[] = _T("返回菜单");
		outtextxy(10, 10, s0);
	}
}
