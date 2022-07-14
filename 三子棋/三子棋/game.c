#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu(void)
{
	printf("******************\n");
	printf("**** 1.play ******\n");
	printf("**** 0.quit ******\n");
	printf("******************\n");

	return;
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
	return;
}

void Displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}

		printf("\n");

		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("___");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
	return;
}

void playermove(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("����� >\n");
	printf("���������꣺");

	while (1)
	{
		scanf("%d %d", &i, &j);
		if ((i >= 1 && i <= row) && (j >= 1 && j <= col))
		{
			if (board[i - 1][j - 1] == ' ')
			{
				board[i - 1][j - 1] = '*';
				break;
			}
			else
				printf("�ѱ�ռ�ã����������룺");
		}
		else
			printf("��Ч���꣬���������룺");
	}
	return;
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("������ >\n");
	
	while (1)
	{
		int i = rand() % row;
		int j = rand() % col;

		if (board[i][j] == ' ')
		{
			board[i][j] = '#';
			break;
		}
	}
	return;
}

int isfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	//дһ�����򣬵�board()��������������������һ���ߵ��������ʱ�����ظ������ϵĺ���ֵ
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == board[i][i + 1] && board[i][i + 1] == board[i][i + 2] && board[i][i] != ' ')
			return board[i][i];
		if (board[i][i] == board[i + 1][i] && board[i + 1][i] == board[i + 2][i] && board[i][i] != ' ')
			return board[i][i];
		if (board[i][i] == board[i + 1][i + 1] && board[i + 1][i + 1] == board[i + 2][i + 2] && board[i][i] != ' ')
			return board[i][i];
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == board[i + 1][i - 1] && board[i + 2][i - 2] == board[i + 2][i - 2] && board[i][j] != ' ')
				return board[i][i];
		}
	}
		//for (i = 0; i < row; i++)//�ж���������ʱ�ĳ��򣬵����Ӳ�Ϊ����ʱ�����ʧЧ
		//{
		//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		//	{
		//		return board[i][1];
		//	}
		//}
		//for (i = 0; i < row; i++)
		//{
		//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		//	{
		//		return board[1][i];
		//	}
		//}
		//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		//{
		//	return board[1][1];
		//}
		//if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		//{
		//	return board[1][1];
		//}

	int ret = isfull(board, row, col);//�ж��Ƿ�ƽ�ֺͼ�����ƽ�ַ���1����������0�����������Ƿ��пո�Ϊ�ж�����
	{
		if (ret == 1)
			return 'q';
		if (ret == 0)
			return 'c';
	}
}

