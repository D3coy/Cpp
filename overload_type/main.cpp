#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inches;
};

void engldisp (Distance);        //прототипы
void engldisp (float);

int main()
{
    Distance d1;                //длина типа Distance
    float d2;                   //длина типа float

    cout << "\nВведите число футов: "; cin >> d1.feet;
    cout << "\nВведите число дюймов: "; cin >> d1.inches;

    //инициализзща

    return 0;
}
