#pragma once
#include <stdio.h>
#include <stdlib.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define bomb 4

void menu(void);//��ӡ�˵�

void initboard(char board[ROWS][COLS], int rows, int cols, char set);//�����ʼ��

void displayboard(char board[ROWS][COLS], int row, int col);//��ӡ����

void setmine(char board[ROWS][COLS], int row, int col);//�����������������

void findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//��mine���Ų���

int get_mine(char mine[ROWS][COLS], int row, int col);//��ȡ�����������Χ�м�����

void test(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int row, int col);//�ṩһ������ѭ����ʾΪ0������ĳ���