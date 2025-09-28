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
class IntCell
{
public:
    IntCell(int initialValue = 0) : storedValue(initialValue) {}

    int read() const { return storedValue; }
    void write(int x) { storedValue = x; }

    ~IntCell() { cout << "IntCell object with storedValue of " << storedValue << " destructed" << endl; }

private:
    int storedValue;
};

void intcell_function()
{
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

void pointers()
{
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

void swap_p(int *p, int *q)
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

void swap_r(int &p, int &q)
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

void dynamic_memory_allocation()
{
    // declare a ptr to user-defined data type
    IntCell *ptr1;
    int *ptr2;

    // dynamically allocate space for an IntCell;
    // initialize values; return pointer and assign
    // to ptr1
    ptr1 = new IntCell(5);

    // similar for int:
    ptr2 = new int(2);
    // free up the memory that ptr1 points to
    delete ptr1;
    // dynamically allocate array of 23
    // IntCell slots
    // each will be initialized to 0
    ptr1 = new IntCell[23];

    // similar for int
    ptr2 = new int[12];

    // free up the dynamically allocated array
    delete[] ptr1;
}

void reference_variables()
{
    int n = 5, m = 6;
    int &rn = n; // we should give a value to declare a reference

    n = 6;
    rn = 7;
    cout << n << rn << m << endl;
    rn = m; // makes n equal to m
    cout << n << rn << m << endl;
}

void ref_vs_pointers()
{
    int n = 5;
    int &rn = n;
    int *const p = &n;

    // Same Effect
    *p = 6;
    rn = 6;
}

void pointer_and_consts()
{
    // ----Constant Pointer----
    int i = 0;
    int *const p = &i;

    //p = &j // error
    cout << i << endl;
    *p = 6;
    cout << i << endl;

    // ----Pointer to a Const variable----
    i = 0;
    const int *q = &i;

    //*p = 6 // not possible
    cout << *q << endl;
    i = 6; // but possible independently
    cout << *q << endl;
}



int main()
{
    // basic_cpp_program();
    // intcell_function();
    // pointers();
    // swap_p_Call();
    // swap_r_Call();
    //dynamic_memory_allocation();
    //reference_variables();
    pointer_and_consts();

    return 0;
}