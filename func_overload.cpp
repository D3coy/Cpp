#include <iostream>
#include <string>

using namespace std;

void print(string word)            //string only
{
  cout << word << endl;
}

void print(float word)              //float only
{
  cout << word << endl;
}

float del(float a, float b)
{
  if(b == 0)
    return -1;
  else
      return a / b;
}

int main()
{
  string text = "hello";            //string print()
  print(text);

  float res = del(22, 10);
  print(res);                       //float print()
}
