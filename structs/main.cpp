#include <iostream>
using namespace std;

struct Book
{
    int id;                     //poles of structure
    int pages;
    float cost;
};

struct Library
{
    Book classic[3];                //поля структуры Library наследующие поля Book
    Book horror[3];
};

int main(int argc, char* argv[])
{
    Book c1 = {1, 100, 50};         //переменная с типом Book может иметь только 3 параметра
    Book c2 = {2, 100, 50};
    Book c3 = {3, 100, 50};

    Book h1 = {4, 100, 70};
    Book h2 = {4, 100, 70};
    Book h3 = {4, 100, 70};

    Library l1 = {{c1, c2, c3}, {h1, h2, h3}};  //Впихнули в два поля общего хранилища Library три поля Book. При этом поля Library имеют связь с переменными полей Book

    for (int i = 0; i < 3; i++) {
        cout << "Classic literature: " << endl;
        cout << "Book number " << i+1 << endl;                // counter_i = 0, 1, 2; numBook_i = 0+1, 1+1, 2+1;
        cout << "Book id -> " << l1.classic[i].id << endl;
        cout << "Freq of pages -> " << l1.classic[i].pages << endl;
        cout << "How much? -> " << l1.classic[i].cost << endl;
        cout << "\n";
    }

    cout << "_______________________________________\n";
    cout << "\n";

    for (int i = 0; i < 3; i++) {
        cout << "Horror literature: " << endl;
        cout << "Book number " << i+1 << endl;                // counter_i = 0, 1, 2; numBook_i = 0+1, 1+1, 2+1;
        cout << "Book id -> " << l1.horror[i].id << endl;
        cout << "Freq of pages -> " << l1.horror[i].pages << endl;
        cout << "How much? -> " << l1.horror[i].cost << endl;
        cout << "\n";

    }

    cout << "---------------------------------------\n";
    cout << "\n";

    return 0;
}
