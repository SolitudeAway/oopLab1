#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <ctime>
using namespace std;
string fileInput();		//введення вхідних даних у файл
string wordInput();		//введення слова, необхідного для виконання задачі
bool fileGen(string, string, string);	//створення файлу відповідно поставленої задачі
void fileRead(string);	//виведення даних із файлу
bool strSplit(string, string);	//перевірка рядка на наявність слова
bool fileAdd(string);	//запит користувача щодо додавання даних до файлу
void fileEdit(string);	//додавання даних до кінця файлу
void fileStat(string);	//визначення розміру, дати і часу створення файлу
