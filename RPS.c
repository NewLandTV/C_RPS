#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void Init();
void Loop();

int computerRPS;
int userRPS;

int main(void)
{
	Init();
	
	while (1)
	{
		Loop();
	}
	
	return 0;
}

void Init()
{
	system("title RPS");
	system("mode con cols=100 lines=40");
	
	srand(time(NULL));
}

void Loop()
{
	printf("****[ ���������� ���� ]****\n");
	printf("*        S : ����         *\n");
	printf("*        R : ����         *\n");
	printf("*        P : ��           *\n");
	printf("***************************\n\n");
	printf(">> ");
	
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			// ���� 
			case 'S':
			case 's':
				userRPS = 0;
				
				break;
				
			// ���� 
			case 'R':
			case 'r':
				userRPS = 1;
				
				break;
				
			// �� 
			case 'P':
			case 'p':
				userRPS = 2;
				
				break;
			}
			
			break;
		}
	}
	
	computerRPS = rand() % 3;
	
	printf("[����] : %s\n", userRPS == 0 ? "����" : userRPS == 1 ? "����" : "��");
	printf("[��ǻ��] : %s\n\n", computerRPS == 0 ? "����" : computerRPS == 1 ? "����" : "��");
	
	Sleep(500);
	
	// ��� 
	if (userRPS == computerRPS)
	{
		printf("���");
	}
	// ��ǻ�� �� 
	else if ((userRPS == 0 && computerRPS == 1) || (userRPS == 1 && computerRPS == 2) || (userRPS == 2 && computerRPS == 0))
	{
		printf("��ǻ�� ��");
	}
	// ���� �� 
	else if ((computerRPS == 0 && userRPS == 1) || (computerRPS == 1 && userRPS == 2) || (computerRPS == 2 && userRPS == 0))
	{
		printf("���� ��");
	}
	
	puts("");
	
	Sleep(1500);
	
	system("cls");
}
