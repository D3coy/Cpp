#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
  int array1[10];
  int sum = 0;
  int i;

  cout << "Введите элементы массива: \n";
  for (i = 0; i < 10; i++){                     // цикл для считывания чисел
    cin >> array1[i];
  }
  cout << "array1 = { ";
  for (i = 0; i < 10; i++){                    // цикл для вывода элементов массива
    cout << array1[i] << " ";
  }
  for (i = 0; i < 10; i++){                    // суммируем элементы массива
    sum += array1[i];
  }
  cout << "}\nsum = " << sum << "\n";

return 0;
}
