#include"connection.h"

void menu(void)
{
	printf("********************\n");
	printf("****1.add  2.del****\n");
	printf("****3.rev  4.fin****\n");
	printf("****5.pri  0.exit***\n");
	printf("********************\n");
}

void initialize_contact(contact* con)//��ʼ��ͨѶ¼Ϊ0
{
	con->data = (connect*) calloc(MAX_SPACE, sizeof(connect));
	if (con->data == NULL)
	{
		perror("initialize_contact");
		printf("����ʧ��\n");
		return;
	}
	con->sz = 0;
	con->capacity = MAX_SPACE;
	return;
}

void load(contact* con)//¼���ļ��е�����
{
	FILE* fp = fopen("contact_information.dat", "r");
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	connect ect = { 0 };
	while (fread(&ect, sizeof(connect), 1, fp))//¼���ļ��е����ݣ�fread���������᷵������¼������ݵĸ�����¼��Ϊ0ʱ����0
	{
		if (con->sz == con->capacity)
		{
			place_add(con);
		}
		con->data[con->sz] = ect;
		con->sz++;
	}

	fclose(fp);
	fp = NULL;
	return;
}

void place_add(contact* con)//����ͨѶ¼�еĴ洢�ռ�
{

		connect* ptr = (connect*)realloc(con->data, (con->capacity + INT_ADD) * sizeof(connect));
		if (ptr != NULL)
		{
			con->data = ptr;
			con->capacity += INT_ADD;
			printf("���ӿռ�ɹ�\n");
		}
		else
		{
			perror("increase");
			printf("���ӿռ�ʧ��\n");
			return;
		}
}

void increase(contact* con)//����ͨѶ¼���˵���Ϣ
{
	if (con->sz == MAX_DATA)
	{
		printf("�����Ѵ����ޣ�����ʧ��\n");
		return;
	}

	if (con->sz == con->capacity)
	{
		place_add(con);
	}
	
	printf("���������֣�");
	scanf("%s", con->data[con->sz].name);
	printf("���������䣺");
	scanf("%d", &(con->data[con->sz].age));
	printf("�������Ա�");
	scanf("%s", con->data[con->sz].gender);
	printf("������绰��");
	scanf("%s", con->data[con->sz].tel);
	printf("�������ַ��");
	scanf("%s", con->data[con->sz].address);
	con->sz++;
	printf("���ӳɹ�\n");
	return;
}

void delete(contact* con)//ɾ���˵���Ϣ
{
	if (con->sz == 0)
	{
		printf("ͨѶ¼������Ϣ��ɾ��");
		return;
	}
	char name[MAX_NAME];
	printf("��������Ҫɾ�����˵����֣�");
	scanf("%s", name);

	int i = 0;
	int j = 0;
	int subscript[MAX_SUB] = { 0 };

	j = Find(con, name, subscript);

	if (j != 0)
	{
		int input = 0;
		printf("������һ������ѡ����Ҫɾ������ϵ�ˣ�");
		scanf("%d", &input);

		int ch = subscript[input - 1];
		for (ch; ch < con->sz; ch++)
		{
			con->data[ch] = con->data[ch + 1];
		}
		con->sz--;

		connect* ptr = (connect*)realloc(con->data, (con->capacity - 1) * sizeof(connect));//ÿɾ��һ����ϵ����Ϣ���ͻ���һ���ռ�
		con->data = ptr;
		con->capacity -= 1;

		printf("ɾ���ɹ�\n"); 
		return;
	}

	printf("ͨѶ¼���޸���\n");
	return;
}

void revise(contact* con)//�޸��˵���Ϣ
{
	if (con->sz == 0)
	{
		printf("ͨѶ¼���޿��޸���Ϣ\n");
		return;
	}
	char name[MAX_NAME];
	printf("��������Ҫ�޸ĵ��˵����֣�");
	scanf("%s", name);

	int i = 0;
	int j = 0;
	int subscript[MAX_SUB] = { 0 };

	j = Find(con, name, subscript);

	if (j > 0)
	{
		int input = 0;
		printf("������һ������ѡ����Ҫ�޸ĵ���ϵ�ˣ�");
		scanf("%d", &input);

		int ch = subscript[input - 1];
		printf("�������޸ĺ�����֣�");
		scanf("%s", con->data[ch].name);
		printf("�������޸ĺ�����䣺");
		scanf("%d", &(con->data[ch].age));
		printf("�������޸ĺ���Ա�");
		scanf("%s", con->data[ch].gender);
		printf("�������޸ĺ�ĵ绰��");
		scanf("%s", con->data[ch].tel);
		printf("�������޸ĺ�ĵ�ַ��");
		scanf("%s", con->data[ch].address);

		printf("�޸ĳɹ�\n");
		return;
	}
	printf("ͨѶ¼���޸�����Ϣ\n");
	return;
}

int find(const contact* con, char* name)//Ѱ���˵���Ϣ
{
	int i = 0;
	int t = 0;
	int j = 0;
	for (i = 0; i < con->sz; i++)
	{;
		if (strcmp(name, con->data[i].name) == 0)
		{
			j = i;

			if (t == 0)
			{
				printf("���ҵ�\n");
				t++;
			}

			printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
				                                        con->data[i].gender, con->data[i].tel,
				                                        con->data[i].address);
		}
	}
	if (t == 0)
	{
		printf("δ�ҵ�\n");
		return -1;
	}

	if (i + 1 >= con->sz)
	{
		return j;
	}
}

void print(const contact* con)//��ӡ�˵���Ϣ
{
	int i = 0;

	printf("%-20s\t%-5s\t%-5s\t%-15s\t%-20s\n","����", "����", "�Ա�", "�绰", "��ַ");

	for (i = 0; i < (con->sz); i++)
	{
		printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
			                                        con->data[i].gender, con->data[i].tel,
			                                        con->data[i].address);
	}
	return;
}

void write(const contact* con)////�Ѽ�¼��ͨѶ¼��Ϣ¼�뵽�ļ���
{
	FILE* fp = fopen("contact_information.dat", "w");//�ԡ�ֻ��������ʽ���ļ�
	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	int i = 0;
	for (i = 0; i < con->sz; i++)//��con->dataָ�������¼�뵽�򿪵��ļ���
	{
		fwrite(con->data + i, sizeof(connect), 1, fp);
	}
	
	fclose(fp);//�ر��ļ�
	fp = NULL;
	return;
}

void purge(contact* con)//��������Ķ�̬�ռ�
{
	free(con->data);
	con->data = NULL;
	con->sz = 0;
	con->capacity = 0;
	return;
}

int Find(const contact* con, char* name, int* subscript)//��delete()��revise��������ʹ�õĲ��Һ���
{
	int i = 0;
	int j = 0;

	for (i = 0; i < con->sz; i++)
	{
		if (strcmp(name, con->data[i].name) == 0)
		{
			printf("%-20s\t%-5d\t%-5s\t%-15s\t%-20s\n", con->data[i].name, con->data[i].age,
				con->data[i].gender, con->data[i].tel,
				con->data[i].address);

			subscript[j] = i;
			j++;
		}
	}
	return j;
}