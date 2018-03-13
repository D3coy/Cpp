#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])   //argc = arg.count(кол-во аргументов) ; argv = arg.vector(указатель на массив строковых параметров) >=1
{
	char text[50];                     //переменная хранящая считанные символы из файла text.txt, буфер ->50
	/*
	ofstream file;                     //объект класса записи в файл
	file.open("text.txt");             //открыть -> создать файл
	file << "work with files in c++";  //запись в файл
	file.close();                      //закрытие файла
	*/
	
	ifstream file("text.txt");       //создали объект класса чтения из файла и открыли на чтение
	if (!file.is_open())               //проверка не открыт(например не существует больше)
	{
		cout << "Error, no file here.." << "\n";
	}
	else
	{
		file.getline(text, 50);
		cout << text << "\n";
		file.close();
	}
	
	cin.get();
	return 0;
}
