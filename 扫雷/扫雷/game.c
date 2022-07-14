#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu(void)
{
	printf("*********************\n");
	printf("*****1.��ʼ��Ϸ******\n");
	printf("*****0.������Ϸ******\n");
	printf("*********************\n");
	return;
}

void initboard(char board[ROWS][COLS], int rows, int cols, char set)//�����ʼ��
{
	int i = 0;
	int j = 0;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
	return;
}

void displayboard(char board[ROWS][COLS], int row, int col)//��ӡ����
{
	int i = 0;
	int j = 0;
	
	printf("_____________ɨ��____________\n");
	for (i = 0; i <= row;i++)
	{
		printf(" %d ", i);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
	printf("_____________ɨ��____________\n");

	return;
}

void setmine(char board[ROWS][COLS], int row, int col)//�������������'1'Ϊ��
{
	int count = bomb;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	return;
}

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (1)
	{
		printf("�������Ų����꣺");

		scanf("%d %d", &x, &y);

		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))//�ж����������Ƿ����
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը����\n");
				displayboard(mine, ROW, COL);

				break;
			}
			else
			{
				test(mine, show, x, y, row, col);

				displayboard(show, ROW, COL);

				win++;

				if (win == ROW * COL - bomb)
				{
					printf("��ϲ�㣬��ʤ��\n");
					displayboard(mine, ROW, COL);

					break;
				}
			}
		}
		else
			printf("��Ч���꣬����������");
	}

}

int get_mine(char mine[ROWS][COLS], int x, int y)//���������������ΧһȦ�ڵ��׵ĸ���
{
	int i = -1;
	int j = -1;
	int count = 0;
	
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1;j++)
		{
			if (mine[x + i][y + j] == '1')
				count++;
		}
	}
	return count;
}

void test(char mine[ROWS][COLS],char show[ROWS][COLS], int x, int y, int row, int col)
{
	int count = get_mine(mine, x, y);

	if (count == 0)
	{
		show[x][y] = count + '0';
		int i = 0;
		int j = 0;
		for (i = x - 1; i <= x + 1; i++)
		{
			for (j = y - 1; j <= j + 1; j++)
			{			
				if (show[i][j] == '*')
				{
					test(mine, show, i, j, row, col);
				}		
			}
		}
	}
	else
		show[x][y] = count + '0';
}
	