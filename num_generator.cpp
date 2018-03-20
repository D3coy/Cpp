#include <iostream>
#include <cstdlib> // для exit()
#include <fstream>
using namespace std;

char text[50];

// Exec a menu to user
int menu()
{
    int variant;
    cout << "\n[  Choose task  ]\n" << endl;
    cout << "1. nums 1..8\n"
         << "2. rand_1..8\n"
         << "3. \n"
         << "4. \n"
         << "5. \n"
         << "6. \n"
         << "7. exit\n" << endl;
    cout << ">>> ";
    cin >> variant;
    return variant;
}

int f_nums()
{
  unsigned int digits;

  ofstream file;                     //object of writing class
  file.open("NUMSto8.txt");

  for(digits = 0; digits < 100000000; digits++)
  {
  	file << digits << endl;  //Write to file
  }
  file.close();
 cout << "done..";
 menu();
}

int main(int argc, char* argv[])
{
    int variant = menu();

    switch (variant) {
        case 1:
            cout << "Generating 8 digit series..." << endl;
            f_nums();
            break;
        case 2:
            cout << "..." << endl;
            break;
        case 3:
            cout << "..." << endl;
            break;
        case 4:
            cout << "..." << endl;
            break;
        case 5:
            cout << "..." << endl;
            break;
        case 6:
            cout << "..." << endl;
            break;
        case 7:
            cout << "Exiting..." << endl;
            exit(EXIT_SUCCESS);
            break;
        default:
            cerr << "Error" << endl;
            exit(EXIT_FAILURE);
    }
    return 0;
}
