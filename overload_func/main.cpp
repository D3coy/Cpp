#include <iostream>
using namespace std;

void repchar();                 //starline() analog (45->*)
void repchar(char);             //charline() analog (45->char)
void repchar(char, int);        //repchar() analog (x->char)

int main()
{
    repchar ();                 //перегрузочка функций
    repchar ('=');
    repchar ('+', 30);

    return 0;
}

//функция repchar выводит на экран 45 символов '*' без конфигураций(с пустой сигнатурой)
void repchar(){
    for (int i = 0; i < 45; i++) {
        cout << '*';
    }
    cout << endl;
}

//функция repchar(char) выводит 45 раз переданный в параметр символ (сигнатура -> char sym)
void repchar(char sym){
    for (int i = 0; i < 45; i++) {
        cout << sym;
    }
    cout << endl;
}

//функция repchar(char, int) выводит [x] раз заданный символ
void repchar(char sym, int frq){
    for (int i = 0; i < frq; i++) {
        cout << sym;
    }
    cout << endl;
}
