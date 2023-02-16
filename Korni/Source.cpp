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
        a = b - (b - a) * f(b) / (f(b) - f(a));                     //������� ����� ������� 
        b = a - (a - b) * f(a) / (f(a) - f(b));
        inter += 1;
        if (min > P(b))                                             //������� �������� � ��������� ��� ���������� ���������� ����������
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
    cout << "\n�������� ���������� = " << 1 - min / max;
    cout << "\n�������� ������� = " << eps;
    cout << "\n���������� �������� = " << inter << "\n";
    cout << "������ = " << b << "\n";
    long t2 = clock();
    cout << "����� �������� " << t2 - t1 << "��" << endl;
    return 0;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double a, b, exp;
    cout << "������� ������ ���������\n";
    cin >> a;
    cout << "\n������� ����� ���������\n";
    cin >> b;
    cout << "\n������� ��������\n";
    cin >> exp;
    findRoot(a, b, exp);
      
}