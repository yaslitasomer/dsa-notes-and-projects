//============================================================================
// Name        : notes_1.cpp
// Author      : Ömer YASLITAŞ
// Version     : 1.0
// Description : Introduction to CPP - NOTES PART 1
//============================================================================
#include <iostream> //input/output
#include <math.h>   //usual C lib header file for math
#include <iomanip>
using namespace std;

void basic_cpp_program()
{
    double a = 15.2;
    double b = 3.3434343;

    cout << fixed << showpoint;
    cout << setprecision(2);      // 2 digits after the dot
    cout << setw(6) << a << endl; // 15.20
    cout << setw(6) << b << endl; // 34.34
}

// Class Syntax
class IntCell{
    public:
        IntCell(int initialValue = 0) : storedValue( initialValue ) {}

        int read() const {return storedValue;}
        void write(int x) {storedValue = x;}

        ~IntCell() { cout << "IntCell object with storedValue of " << storedValue << " destructed" << endl; }

    private:
        int storedValue;

};

void intcell_function(){
    IntCell m1;
    IntCell m2(15);
    IntCell *m3;

    m1.write(55);
    m2.write(m1.read() + 1);
    cout << m1.read() << " " << m2.read() << endl;
    m3 = new IntCell;
    cout << "m3 = " << m3->read() << endl;
    m3->~IntCell();
}

void pointers(){
    int a, b, *p;
    a = b = 7;
    p = &a;

    cout << "*p = " << *p << endl;

    *p = 3;
    cout << "a = " << a << endl;

    p = &b;
    *p = 2 * *p - a;

    cout << "b = " << b << endl;

}

void swap_p (int *p, int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

void swap_p_Call()
{
    int a = 3;
    int b = 5;
    cout << a << b << endl;
    swap_p(&a, &b);
    cout << a << b << endl;
}

void swap_r (int &p, int &q)
{
    int tmp = p;
    p = q;
    q = tmp;
}

void swap_r_Call()
{
    int a = 3;
    int b = 5;
    cout << a << b << endl;
    swap_r(a, b);
    cout << a << b << endl;
}


int main()
{
    //basic_cpp_program();
    //intcell_function();
    //pointers();
    //swap_p_Call();
    swap_r_Call();

    return 0;
}