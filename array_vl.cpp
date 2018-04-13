#include <iostream>
using namespace std;

int main()
{
  int mass[5][2];
  int sum;
  int i,j;              //переменные отвечающие за массивные значения

  cout << "Введите элементы массива: \n";
  for (i = 0; i < 5; i++){
    for (j = 0; j < 2; j++){
      cin >> mass[i][j];
    }
  }
  cout << "array1 = {";
  for (i = 0; i < 5; i++){
    for (j = 0; j < 2; j++){
      cout << mass[i][j];
    }
  }

  for (i = 0; i < 5; i++){
    for (j = 0; j < 2; j++){
      sum += mass[i][j];
    }
  }
  cout << "}\nsum = " << sum << "\n";

return 0;
}
