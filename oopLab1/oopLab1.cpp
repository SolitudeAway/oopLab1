#include "Header.h"	//включення користувацької бібліотеки

int main() {
	string inFileName = fileInput();	//введення назви файлу ввідних даних, створення файлу
	string outFileName = "output.txt";	//назва файлу вихідних даних
	string word = wordInput();			//слово для виконання поставленої задачі
	if (fileGen(inFileName, outFileName, word))		//якщо створення файлу вихідних даних відбулось успішно
	{
		fileRead(inFileName);		//виведення файлу ввідних даних
		fileRead(outFileName);		//виведення файлу вихідних даних
		fileStat(outFileName);		//виведення статистики файлу вихідних даних
		while (fileAdd(inFileName))		//поки користувач бажає додати дані до файлу ввідних даних
		{
			fileGen(inFileName, outFileName, word); //створення файлу вихідних даних
			fileRead(inFileName);					//виведення файлу ввідних даних
			fileRead(outFileName);					//виведення файлу вихідних даних
			fileStat(outFileName);					//виведення статистики файлу вихідних даних
		}
	}
	system("pause");
}
