#pragma once

#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 10

void menu(void);//��ӡ�˵�

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ������Ϊ�ո�

void Displayboard(char board[ROW][COL], int row, int col);//��ӡ����

void playermove(char board[ROW][COL], int row, int col);//�������

void computermove(char board[ROW][COL], int row, int col);//��������

char iswin(char board[ROW][COL], int row, int col);//�ж�ʤ��

int isfull(char board[ROW][COL], int row, int col);//�ж������Ƿ���