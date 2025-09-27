#include <iostream>
using namespace std;

// Exercise 4
void fun1(int *a, int b)
{
    b = b - 1;
    *a = *a + b;
    cout << *a << "  " << b << endl;
}

void fun2(int &a, int b)
{
    a = a * 2;
    b = a + b;
    cout << a << "  " << b << endl;
}

int main()
{
    /* Exercise 4
    int a = 3, b = 3;
    fun1(&a, b);
    cout << a << "  " << b << endl;
    */

    int x = 3, y = 5;
    fun2(x, y);
    cout << x << "  " << y << endl;
}