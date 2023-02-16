#include <windows.h>
#include <iostream>
#include <cmath>
#include <time.h> 

using namespace std;

double f(double x)
{
    return sqrt(4 * x + 7) - 3 * cos(x);
}

double P(double x)
{
    return 3 * sin(x) + ( 2 / sqrt(4 * x + 7));
}

double findRoot(double a, double b, double eps)
{
    double min = P(b), max= P(b);
    long t1 = clock();
    int inter = 0;
    cout << "F(x) = sqrt(4 * x + 7) - 3 * cos(x)";
    while (fabs(b - a) > eps)
    {
        a = b - (b - a) * f(b) / (f(b) - f(a));                     //Рассчет корня функции 
        b = a - (a - b) * f(a) / (f(a) - f(b));
        inter += 1;
        if (min > P(b))                                             //Рассчет минимума и максимума для нахождения параматера сходимости
        {
            min = P(b);
        }
        if (max < P(b))
        {
            max = P(b);
        }
    }
    cout << "\nmin = " << min;
    cout << "\nmax = " << max;
    cout << "\nПараметр сходимости = " << 1 - min / max;
    cout << "\nЗаданная точнсть = " << eps;
    cout << "\nКоличество итераций = " << inter << "\n";
    cout << "Корень = " << b << "\n";
    long t2 = clock();
    cout << "Время подсчета " << t2 - t1 << "мс" << endl;
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, exp;
    cout << "Введите начало интервала\n";
    cin >> a;
    cout << "\nВведите конец интервала\n";
    cin >> b;
    cout << "\nВведите точность\n";
    cin >> exp;
    findRoot(a, b, exp);
      
}