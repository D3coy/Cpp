#include <iostream>
#include <conio.h>
#include <cstdio>
using namespace std;

int main()
{
    void intfrac_f (float, float&, float&, string&);                       //proto
    float number, intpart, fracpart;
    string random_string;

    do {                                                                   //this
            cout << "\nEnter float number: ";
            cin >> number;
            cout << "\nEnter some text: ";
            cin >> random_string;

            intfrac_f (number, intpart, fracpart, random_string);

            cout << "Integer part equal: " << intpart
                 << " , Float part equal: " << fracpart << endl;

            cout << "Text entered: " << random_string << endl;

        } while (number !=0.0);                                             //exit condition

   return 0;
}

void intfrac_f (float n, float& intp, float& fracp, string& random_str) {   //refs to arg, refs allow to change value in function and obviesly it changed in main()
    long temp = static_cast<long>(n);                                       //temp equals rounded float value (2.5 -> 2)
    intp = temp;                                                            //intp=2 for minus integer part from <n>
    fracp = (float)n - intp;                                                //2.5 - 2 = 0.5
}
