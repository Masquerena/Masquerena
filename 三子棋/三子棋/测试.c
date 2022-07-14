#define  _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game(void)
{
	char board[ROW][COL];
	char ret = 0;

	InitBoard(board, ROW, COL);//��ʼ������Ϊ�ո�

	Displayboard(board, ROW, COL);//��ӡ����

	while (1)
	{
		playermove(board, ROW, COL);//����ж�
		Displayboard(board, ROW, COL);//��ӡ����
		ret = iswin(board, ROW, COL);
		if (ret != 'c')
			break;

		computermove(board, ROW, COL);//�����ж�
		Displayboard(board, ROW, COL);//��ӡ����
		ret = iswin(board, ROW, COL);//�ж�ʤ����������Ӯ������'*'���������Ӯ������'#'
		                             //���ƽ�֣�����'q'�������δ����ʤ��������'c'
		if (ret != 'c')
			break;
	}

	switch (ret)
	{
	case '*':
		printf("��һ�ʤ\n");
		break;
	case '#':
		printf("���Ի�ʤ\n");
		break;
	case 'q':
		printf("ƽ��\n");
		break;
	}
	Displayboard(board, ROW, COL);
	return;
}

int main(void)//�����������ڲ����������Ƿ����
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();

		printf("��ѡ��");
		scanf("%d", &input);

		switch (input)
		{
		case 1 :
			game();
			break;
		case 0:
			printf("�˳�\n");
			break;
		default :
			printf("����������������룺\n");
		}

	} while (input);
	return 0;
}