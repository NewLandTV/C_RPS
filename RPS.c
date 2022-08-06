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
	printf("****[ 가위바위보 게임 ]****\n");
	printf("*        S : 가위         *\n");
	printf("*        R : 바위         *\n");
	printf("*        P : 보           *\n");
	printf("***************************\n\n");
	printf(">> ");
	
	while (1)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			// 가위 
			case 'S':
			case 's':
				userRPS = 0;
				
				break;
				
			// 바위 
			case 'R':
			case 'r':
				userRPS = 1;
				
				break;
				
			// 보 
			case 'P':
			case 'p':
				userRPS = 2;
				
				break;
			}
			
			break;
		}
	}
	
	computerRPS = rand() % 3;
	
	printf("[유저] : %s\n", userRPS == 0 ? "가위" : userRPS == 1 ? "바위" : "보");
	printf("[컴퓨터] : %s\n\n", computerRPS == 0 ? "가위" : computerRPS == 1 ? "바위" : "보");
	
	Sleep(500);
	
	// 비김 
	if (userRPS == computerRPS)
	{
		printf("비김");
	}
	// 컴퓨터 승 
	else if ((userRPS == 0 && computerRPS == 1) || (userRPS == 1 && computerRPS == 2) || (userRPS == 2 && computerRPS == 0))
	{
		printf("컴퓨터 승");
	}
	// 유저 승 
	else if ((computerRPS == 0 && userRPS == 1) || (computerRPS == 1 && userRPS == 2) || (computerRPS == 2 && userRPS == 0))
	{
		printf("유저 승");
	}
	
	puts("");
	
	Sleep(1500);
	
	system("cls");
}
