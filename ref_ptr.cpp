#include <iostream>
#include <string>

using namespace std;

void ukazateli(int var)                        //a -> var
{
  int *ptr_var = &var;                         // &var - возвращает адрес переменной, *ptr_var - указатель
  int **ptr_ptr_var = &ptr_var;                //указатель на указатель

//выведет 8 и адрес переменной содержащей значение 8
  cout << "\n1)переменная _a_ = " << var << ", " << "Указатель _ptr_var_ на переменную _a_ =" << ptr_var << endl;
//выведет значение переменной, адрес переменной/значение указателя, значение переменной через обращение к указателю
  cout << "значение переменной _a_ через указатель _ptr_var_ = " << *ptr_var << ",\n" << "адрес указателя на указатель переменной _a_ = "
   << ptr_ptr_var << ", " << endl;
//указатель ссылается на ту-же ячейку
  cout << "3)Адрес ячейки переменной _a_: " << &var <<" = " << ptr_var << " Значению указателя _ptr_var_.\n";
}

void ssylka(int &ref)
{
  cout << "Ссылка на переменную _c_ : " << ref;          //ссылка позволяет работать с переменной напрямую
}

void ukazateli_arifm(float *b, int c_par)
{
  (*b)++;                                                //изменяем переменную на которую ссылаемся
  cout << "-теперь переменная b =" << *b << endl;

  int *ptr_c = &c_par;                                  //указатель на принятую переменную c
  cout << "2)Значение переменной _c_ на которое указывает *ptr_c ->" << *ptr_c << endl;
  cout << "-Адрес переменной _c_ ->" << ptr_c << endl;
  ptr_c++;
  cout << "-Адрес переменной _c_ после сложения(ptr_c++) ->" << ptr_c << endl;
}

int main()
{
  int a = 8;
  float b = 10.5;
  int c = 3;
  cout << "\n1)переменная b =" << b << endl;

  ukazateli_arifm(&b, c);
  ukazateli(a);
  ssylka(c);

  return 0;
}
