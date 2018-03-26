#include <iostream>
using namespace std;

class Car {
protected:
    int height;
    float speed;
public:
    Car() {}                                                        //конструктор по-умолчанию
    
    Car(int height, float speed){                                   //конструктор при передаче параметров
        this->height = height;
        this->speed = speed;
        
        print();
    }
    
    void setValues(int height, float speed)                        //установка значений
    {
        this->height = height;
        this->speed = speed;
    }
    
    void print()                                                   //функция для вывода значений на экран
    {
        cout << this->height << " - " << this->speed << endl;
    }
    
    ~Car() {                                                       //деструктор
        cout << "All is OK." << endl;
    }
};

class Motorcycle : public Car{};                                   //наследование

int main(int argc, char *argv[])
{
    Motorcycle Honda;
    Honda.setValues(500, 300);
    Honda.print();
    
    Car Audi(1200, 230);
    //Audi.setValues(1200, 230);
    //Audi.print();
    
    Car BMW;
    BMW.setValues(2000, 250);
    BMW.print();
}
