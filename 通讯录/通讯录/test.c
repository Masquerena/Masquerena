#define  _CRT_SECURE_NO_WARNINGS 1
#include"connection.h"

//дһ��ͨѶ¼��ͨѶ¼���ܴ��1000������Ϣ
//ÿ���˵���Ϣ��
//����+����+�Ա�+�绰+��ַ
//���ܣ�
//�����˵���Ϣ
//ɾ��ָ���˵���Ϣ
//�޸�ָ���˵���Ϣ
//����ָ���˵���Ϣ
//����ͨѶ¼����Ϣ

int main(void)
{
	contact con;//����ͨѶ¼
	int choose = 0;
	initialize_contact(&con);//��ʼ��ͨѶ¼
	load(&con);//¼���ļ��е�����

	do 
	{
		menu();
		printf("����������ѡ��Ҫ���еĲ�����");
		scanf("%d", &choose);

		switch (choose)
		{
		case ADD://����
			increase(&con);
			break;
		case DEL://ɾ��
			delete(&con);
			break;
		case REV://�޸�
			revise(&con);
			break;
		case FIN://Ѱ��
			printf("��������Ҫ���ҵ��˵����֣�");

			char Name[MAX_NAME] = "0";
			scanf("%s", Name);

			find(&con, Name);
			break;
		case PRI://��ӡ
			print(&con);
			break;
		case EXIT://�˳�
			write(&con);//��ͨѶ¼�е���Ϣ��¼���ļ���
			purge(&con);//��������Ķ�̬�ռ�
			printf("�������");
			break;
		default:
			printf("�������ݴ�������������\n");
		}
	} while (choose);
	
	return 0;
}