#include <iostream>
#include <locale.h> 
#include <conio.h> 
using namespace std;

int c_nod (int, int);

int main()
{
	setlocale(LC_ALL,"RUS");

	int x, y;
	x = y = 0;

	cout << "Введите первое число: " << endl;
	cin >> x;
	cout << "Введите второе число: " << endl;
	cin >> y;

	cout << "Нод чисел равен: " << c_nod (x, y) << endl;


system("pause");
return 0;
}  

int c_nod (int k, int q)
{
	int min;

	if (k == q){                                    //если числа равны, то НОД = одному из них
		return k;
	}
	else
		if (k > q)                                  //нахождение наименьшего числа
			min = q;
		else
			min = k;

	while (k % min || q % min)                      //блок [min--] будет выполняться пока [k] или [q] будут
		min--;                                      //делиться на [min] с остатком -> [true]

	return min;
}
