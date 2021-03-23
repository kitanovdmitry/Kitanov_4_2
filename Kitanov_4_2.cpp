/*
Автор: Китанов Дмитрий
Группа: СБС-001, 2 подгруппа
Задача №4, вариант 2
Цель: вычислить синус угла х, используя формулу(с заданной границей ряда)
*/

#include <iostream>
#include <cmath>
#include <climits>
#define _USE_MATH_DEFINES // the program works without it, but on some platforms it is necessary //

using namespace std;
long double factorial(int number)
{
    if (number == 0)
    {
        return 1;
    }
    else
        {
            return number * factorial(number - 1);
        }
}

int main()
{
    long double x = 0.0;
    bool typeFail;

    do
    {
        cout << "Enter argument(type double, x in degrees) x  for sin(x)\n";
        cin >> x;

        typeFail = cin.fail();
        cin.clear();
        cin.ignore(INT_MAX,'\n');
    }
    while (typeFail);

    cout << "x = " << x << " degrees\n";
    x = x * M_PI / 180.0;
    cout << "x = " << x << " radians\n";

    int k = x / (2*M_PI);
    x = x - 2*M_PI * k; // sin(x + 2*pi*k) = sin(x) //

    const int row_border = 200;
    long double sin_x = 0.0;
    bool angle_180_degrees = (x == M_PI);

    for (int n = 0; n < row_border; n++)
    {
        if (angle_180_degrees) // because when calculated by the formula, the result will be very close to zero: sin(x) = 1.227e-16 //
        {
            sin_x = 0.0;
            break;
        }
        
        sin_x = sin_x + (pow(-1, n) * pow(x, 2*n+1)) / factorial(2*n+1);
        cout << sin_x << "\n";
    }

    cout.precision(15);
    cout << "sin(x) = " << sin_x;
    return 0;
}
