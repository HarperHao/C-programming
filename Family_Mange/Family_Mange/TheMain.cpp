#include"Family.h"
#include"global.h"
person T = NULL;
int main()
{
	GamePhase = 0;
	initgraph(952, 536);
	loadimage(NULL, _T("1.jpg"));
	SetWindowText(GetHWnd(), _T("����ϵͳBy:���� ��־�� ���� ���"));
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
	//����
	loadimage(NULL, _T("1.jpg"));
	switch (GamePhase)
	{
	case 0://���˵�����
		First_Window();
		break;
	case 1:	//��������ͼ����
		creat(p);
		break;
	case 2:	//����³�Ա����
		AddNewNode();
		break;
	case 3://���浽�ļ��Ľ���
		save(T);
		break;
	case 4://���Ŀ��ӻ�����
		view(T);
		break;
	case 5://������������
		if (stop2 == 0)
		{
			InputBox(search_name, 20, "������Ҫ���ҵ�������");
		}
		Find_name(search_name);
		break;
	case 6://�����Ա����
		if (stop3 == 0)
		{
			InputBox(search_sex, 20, "������Ҫ���ҵ��Ա�");
		}
		Find_sex(search_sex);
		break;
	case 7://����ְҵ����
		if (stop4 == 0)
		{
			InputBox(search_occupation, 20, "������Ҫ���ҵ�ְҵ��");
		}
		Find_occupation(search_occupation);
		break;
	case 8://����ѧ������
		if (stop5 == 0)
		{
			InputBox(search_education, 20, "������Ҫ���ҵ�ѧ����");
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
		//���÷������˵���Ŧ
		setfillcolor(RGB(240, 248, 255));
		setlinecolor(RGB(119, 136, 153));
		fillrectangle(0, 0, 80, 30);
		settextstyle(15, 0, _T("����"));
		TCHAR s0[] = _T("���ز˵�");
		outtextxy(10, 10, s0);
	}
}
