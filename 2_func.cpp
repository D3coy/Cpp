/* Эта программа содержит две функции: main() 
и myfunc()
*/

#include <iostream>
using namespace std;

void myfunc();                           //прототип функции

int main()
{
	cout << "В функции main().";         //маркер местонахождения
	myfunc(); //вызов функции myfunc()
	cout << "Мы снова в функции main()\n";
	
	return 0;
}

void myfunc()
{
	cout << "Находимся в функции myfunc()";
}