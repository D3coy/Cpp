#include <iostream>
using namespace std;

int main()
{
    void order (int&, int&, int&);        //прототип

    int n1, n2, n3;

    cout << "Enter first number: ";
    cin >> n1;
    cout << "\nEnter second number: ";
    cin >> n2;
    cout << "\nEnter third number: ";
    cin >> n3;

    order(n1, n2, n3);

    cout << "n1= " << n1 << endl;
    cout << "n2= " << n2 << endl;
    cout << "n3= " << n3 << endl;


    return 0;
}

void order (int& numb1, int& numb2, int& numb3) {
    if (numb1 > numb2 && numb2 > numb3) {               // 12 > 11 > 5
        int temp = numb1;                               // t = 12
        numb1 = numb3;                                  // 5 > 11 > 5, t-12
            numb3 = temp;                               //5 < 11 < 12
        }
    else if (numb1 > numb2 && numb2 < numb3) {          // 20 10 30         // 20 10 15
        int temp = numb1;                               // 20 10 30 t-20    // 20 10 15 t-20
        numb1 = numb2;                                  // 10 10 30 t-20    // 10 10 15, t-20
        if (numb3 > temp) {
            numb2 = temp;                               // 10 20 30
        }
        else {                                                              // 10 15 15
            numb2 = numb3;
            numb3 = temp;                                                   // 10 15 20
        }
    }
    else if (numb1 < numb2 && numb2 > numb3) {
        int temp = numb3;                               // temp = numb2, n2 = n3, n3 = temp , 11 < 22 > 5
        numb3 = numb2;                                  // 11 22 22, t-5
        numb2 = temp;                                   // 11 5 22
        if (numb1 > numb2) {
            temp = numb1;                               // 11 5 22 t-11
            numb1 = numb2;                              // 5 5 22
            numb2 = temp;                               // 5 11 22
        }
    }
    else {
        cout << "\nAll numbers sort by grown up.." << endl;
    }
}
