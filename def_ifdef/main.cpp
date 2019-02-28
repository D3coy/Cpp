#include <iostream>
using namespace std;

#define DEBUG

int main()
{
   #ifdef DEBUG                                                             // IFDEF проверяет наличие объявленной константы (define DEBUG), если она объявленна то выводит текст
                                                                            // и является по-факту выключателем для ненужной части кода!
        cout << "IFDEF shows that <DEBUG> const is defined!" << endl;

   #else

        cout << "<DEBUG> const isn't defined yet.. << endl;"                  // IFDEF_ELSE соответственно выводит текст в своем теле если <DEBUG> не объявлен

   #endif

   #ifndef LOCAL
        cout << "IFNDEF shows that LOCAL const isn't defined" << endl;      // IFNDEF проверяет наличие константы и работает наоборот[ifdef] в случае отсутствия константы [LOCAL] выводит
                                                                            // текст в своем теле
   #else
        cout << "IFNDEF_else shows that LOCAL const is defined" << endl;    // IFNDEF_ELSE соответственно выводит текст в своем теле при наличии константы [LOCAL]
   #endif

 return 0;
}
