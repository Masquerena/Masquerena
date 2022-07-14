#define  _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

enum number
{
	MAX_NAME = 20,
	MAX_GENDER = 5,
	MAX_TEL = 15,
	MAX_ADD = 20,
	MAX_DATA = 1000,
	MAX_SUB = 100
};

enum memory
{
	MAX_SPACE = 3,
	INT_ADD = 2
};

typedef struct connect//����+����+�Ա�+�绰+��ַ
{
	char name[MAX_NAME];
	int age;
	char gender[MAX_GENDER];
	char tel[MAX_TEL];
	char address[MAX_ADD];
}connect;

typedef struct contact
{
	connect* data;//ָ������Ķ�̬�ڴ�ռ�
	int sz;//��¼ͨѶ¼�е���ϵ�˸���
	int capacity;//ͨѶ¼�е�����
}contact;

enum choose
{
	EXIT,
	ADD,
	DEL,
	REV,
	FIN,
	PRI
};

void menu(void);

void initialize_contact(contact* con);//��ͨѶ¼��ʼ��Ϊ0

void load(contact* con);//¼���ļ��е�����

void place_add(contact* con);//���ӿռ�

void increase(contact* con);//�����˵���Ϣ

void delete(contact* con);//ɾ���˵���Ϣ

void revise(contact* con);//�޸��˵���Ϣ

int find(const contact* con, char* name);//�����˵���Ϣ�����ز��ҵ����˵Ĵ���

void print(const contact* con);//��ӡ�˵���Ϣ

void write(const contact* con);//�Ѽ�¼��ͨѶ¼��Ϣ¼�뵽�ļ���

void purge(contact* con);//��������Ķ�̬�ռ�

int Find(const contact* con, char* name, int* subscript);//��delete������revise��������ʹ�õĲ��Һ���