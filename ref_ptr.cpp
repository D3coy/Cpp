#include <iostream>
#include <string>

using namespace std;

void ukazateli(int var)                        //a -> var
{
  int *ptr_var = &var;                         // &var - возвращает адрес переменной, *ptr_var - указатель
  int **ptr_ptr_var = &ptr_var;                //указатель на указатель

//выведет 8 и адрес переменной содержащей значение 8
  cout << "\n1)переменная = " << var << ", " << "Указатель на переменную =" << ptr_var << endl;
//выведет значение переменной, адрес переменной/значение указателя, значение переменной через обращение к указателю
  cout << "2)переменная = " << var << ", " << "Указатель = " << ptr_var << ", " << "значение переменной через указатель = " << *ptr_var
  << ",\n" << "адрес указателя на указатель переменной = "<< ptr_ptr_var << ", " << endl;
//указатель ссылается на ту-же ячейку
  cout << "3)Адрес ячейки переменной: " << &var <<" = " << ptr_var << " Значению указателя.\n";
}

void ssylka(float &ref)
{
  cout << "Ссылка на переменную _c_ : " << ref;
}

void ukazateli_plus(float *b)
{
  (*b)++;                                     //изменяем переменную на которую ссылаемся
  cout << "-теперь переменная b =" << *b << endl;
}

int main()
{
  int a = 8;
  float b = 10.5;
  float c = 2.5;
  cout << "\nпеременная b =" << b << endl;

  ukazateli_plus(&b);
  ukazateli(a);
  ssylka(c);

  return 0;
}
