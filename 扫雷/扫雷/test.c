#define  _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

//дһ��9*9��ɨ����Ϸ
//���裺д�����Գ���д�����������򣬶�����������飬��ʼ���������ݣ���ӡ�������ݣ��������е����������
//�����Ż���ʹ��ɨ����Ϸ���������귵��ֵΪ0ʱ�����μ����ܱ������ֵ����Ϊ0���ٴμ��飬����Ϊ0���ò�Ϊ0������ֹͣ����
void game(void)
{
	char mine[ROWS][COLS] = {0};//������������
	char show[ROWS][COLS] = {0};

	initboard(mine, ROWS, COLS, '0');//��ʼ����������Ϊ�ַ�0
	initboard(show, ROWS, COLS, '*');//��ʼ����������Ϊ�ַ�*

	//displayboard(mine, ROW, COL);
	displayboard(show, ROW, COL);//��ӡ���������

	setmine(mine, ROW, COL);//��mine�����з�����
	//displayboard(mine, ROW, COL);����Ÿ���ӡ������Ϊ�˿����׵�λ���Է������

	findmine(mine, show, ROW, COL);//��mine�������Ų��ף�����������뵽show�����С�
	                               //����û�вȵ���ʱ��ӡshow���飬�ȵ���ʱ��ӡmine����

}


int main(void)
{
	int input = 0;

	srand((unsigned int)time(NULL));

	do
	{
		menu();

		printf("��ѡ�� >");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("����\n");
			break;
		default:
			printf("����������������룺\n");
			break;
		}
	} while (input);
	
	return 0;
}