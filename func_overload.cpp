#include <iostream>
#include <string>

using namespace std;

void print(string word);            //prototype
void print(float word);
float del(float a, float b);

int main()
{
  string text = "hello";
  print(text);                      //string print()

  float res = del(22, 10);
  print(res);                       //float print()
}

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
  try {                              //checking :0
    if(b == 0){
     throw(b);
   }
    else{
      return a / b;
    }
  }
  catch(float err_b){
    cout << "Division by zero is forbidden" << endl;
    return 0;
  }
}
