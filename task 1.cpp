#include <iostream>
using namespace std;

double calculate(double a, double b, double c)
{
    if ((a - b) == 0)
    {
        throw "Error: Division by zero is not allowed.";
    }
    return (a + b + c) / (a - b);
}

int main()
{
    double a, b, c;

    cout << "Enter value for a: ";
    cin >> a;
    cout << "Enter value for b: ";
    cin >> b;
    cout << "Enter value for c: ";
    cin >> c;

    try
    {
        double d = calculate(a, b, c);
        cout << "The result is: " << d << endl;
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    return 0;
}
