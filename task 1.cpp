#include <iostream>
using namespace std;
class divisionWithZeroException
{
private:
    const char* message;

public:
    divisionWithZeroException(const char* msg = "Error: Division by zero is not allowed.") : message(msg)
    {
    }
    const char* what() const
    {
        return message;
    }
};
double calculate(double a, double b, double c)
{
    if ((a - b) == 0)
    {
        throw divisionWithZeroException();
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
    catch (const divisionWithZeroException& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
