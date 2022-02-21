#define _CRT_SECURE_NO_WARNINGS
#include "Header.h"

//�������� ������� ����� � ����
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

//�������� �����, ����������� ��� ��������� ������
string wordInput()
{
	string word;
	cout << "\nEnter the word: ";
	getline(cin, word);
	return word;
}

//��������� ����� �������� ���������� ������
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

//��������� ����� �� �����
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

//�������� ����� �� �������� �����
bool strSplit(string str2, string word)
{
	string str = str2;
	char sep = ' ';				//������, �� ������� �����
	int pos = str.find(sep);	//���������� ������� ��������� ���
	string w;					//����� �������� �����
	while (pos != string::npos) //���� ����� ������ ����� � �����
	{
		w = str.substr(0, pos); //�������� ����� � ������� �����
		if (w == word || (w.find(word) != string::npos && (w[w.length() - 1] < 65 || w[w.length() - 1] > 122)))
			return true;		//���� ����� ��������, �� ��������� ������
		str.erase(0, pos + 1);	//��������� � ������ ����� ����� �� ������
		pos = str.find(sep);	//���������� ������� ��������� ���
	}
	if (str == word || (str.find(word) != string::npos && (str[str.length() - 1] < 65 || str[str.length() - 1] > 122)))
		return true;		//���������� ���������� �����, ��� �� �������� �������
	return false;
}

//����� ����������� ���� ��������� ����� �� �����
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

//��������� ����� �� ���� �����
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

//��������� �����, ���� � ��� ��������� ������ �����. 
void fileStat(string fileName)
{
	struct stat result;
	stat(fileName.c_str(), &result);
	cout << "\nFile " << fileName << " stats:"
		<< "\nTime created: " << ctime(&result.st_mtime)
		<< "Size: " << result.st_size << " bytes\n";
}