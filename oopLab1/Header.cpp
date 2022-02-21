#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

//введення вхідних даних у файл
string fileInput()
{
	string fileName;
	cout << "Enter preferred name of file: ";
	cin >> fileName;
	ofstream outFile(fileName);
	string str = "";
	cout << "Enter text. If you finished, press Ctrl+S: \n";
	char ends = 19;
	bool flag = true;
	while (flag)
	{
		getline(cin, str);
		if (str.find(ends) != string::npos)
		{
			flag = false;
			str.erase(str.find(ends));
		}
		if (!str.empty())
			outFile << str << '\n';
	}
	outFile.close();
	return fileName;
}

//введення слова, необхідного для виконання задачі
string wordInput()
{
	string word;
	cout << "\nEnter the word: ";
	getline(cin, word);
	return word;
}

//створення файлу відповідно поставленої задачі
bool fileGen(string inFileName, string outFileName, string word)
{
	ifstream inFile;
	inFile.open(inFileName);
	if (!inFile)
	{
		cout << "\nFile cannot be opened!\n";
		inFile.close();
		return false;
	}
	ofstream outFile(outFileName);
	string str;
	while (!inFile.eof())
	{
		getline(inFile, str, '\n');
		if (strSplit(str, word))
		{
			outFile << str << '\n';
		}
	}
	inFile.close();
	outFile.close();
	return true;
}

//виведення даних із файлу
void fileRead(string fileName)
{
	ifstream inFile;
	inFile.open(fileName);

	string str;
	cout << "\nFile " << fileName << ":\n";
	while (!inFile.eof())
	{
		getline(inFile, str, '\n');
		if (!str.empty())
			cout << str << '\n';
	}
	inFile.close();
}

//перевірка рядка на наявність слова
bool strSplit(string str2, string word)
{
	string str = str2;
	char sep = ' ';				//символ, що розділяє слова
	int pos = str.find(sep);	//визначення позиції розділення слів
	string w;					//рядок окремого слова
	while (pos != string::npos) //поки можна знайти пробіл в рядку
	{
		w = str.substr(0, pos); //виділення слова в окремий рядок
		if (w == word || (w.find(word) != string::npos && (w[w.length() - 1] < 65 || w[w.length() - 1] > 122)))
			return true;		//якщо слово знайдене, то повернути істину
		str.erase(0, pos + 1);	//видалення з даного рядка слова та пробілу
		pos = str.find(sep);	//визначення позиції розділення слів
	}
	if (str == word || (str.find(word) != string::npos && (str[str.length() - 1] < 65 || str[str.length() - 1] > 122)))
		return true;		//врахування останнього слова, яке не обмежене пробілом
	return false;
}

//запит користувача щодо додавання даних до файлу
bool fileAdd(string inFileName)
{
	while (true)
	{
		cout << "\nEnter + if you want to add text to existing file or - if you don't want: ";
		string str;
		getline(cin, str);
		if (str == "-")
			return false;
		else if (str == "+")
		{
			fileEdit(inFileName);
			return true;
		}
		else
			cout << "Wrong. Try typing again. \n";
	}
}

//додавання даних до кінця файлу
void fileEdit(string inFileName)
{
	string str;
	fstream ioFile;
	char ends = 19;
	ioFile.open(inFileName, ios::app);
	cout << "Enter text. If you finished, press Ctrl+S: \n";
	bool flag = true;
	while (flag)
	{
		getline(cin, str);
		if (str.find(ends) != string::npos)
		{
			flag = false;
			str.erase(str.find(ends));
		}
		if (!str.empty())
			ioFile << str << '\n';
	}
	ioFile.close();
}

//Визначити розмір, дату і час створення нового файлу. 
void fileStat(string fileName)
{
	struct stat result;
	stat(fileName.c_str(), &result);
	cout << "\nFile " << fileName << " stats:"
		<< "\nTime created: " << ctime(&result.st_mtime)
		<< "Size: " << result.st_size << " bytes\n";
}