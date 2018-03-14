#include <iostream>
using namespace std;

int main()
{
	int a, b;
	
	cout << "Введите первое число: ";
	cin >> a;
	
	cout << "Введите второе число: ";
	cin >> b;
	
	if(a < b)
	{
		cout << "Первое число меньше второго.";
	}
	else if (a == b)
	{
		cout << "Первое число равно второму.";
	}
	else if (a > b)
	{
		cout << "Первое число больше второго.";
	}
	else 
		cout << "Значение не распознаны..";
}