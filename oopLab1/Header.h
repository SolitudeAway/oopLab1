#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
string fileInput();		//�������� ������� ����� � ����
string wordInput();		//�������� �����, ����������� ��� ��������� ������
bool fileGen(string, string, string);	//��������� ����� �������� ���������� ������
void fileRead(string);	//��������� ����� �� �����
bool strSplit(string, string);	//�������� ����� �� �������� �����
bool fileAdd(string);	//����� ����������� ���� ��������� ����� �� �����
void fileEdit(string);	//��������� ����� �� ���� �����
void fileStat(string);	//���������� ������, ���� � ���� ��������� �����
