#include <iostream>
using namespace std;

void test(int value)
{
    try
    {
        if (value > 0)
        {
            throw value;
        }
        else
        {
            throw 'x';
        }
    }
    catch (int i)
    {
        cout << "Integer Exception Caught: " << i << endl;
    }
    catch (char c)
    {
        cout << "Character Exception Caught: " << c << endl;
    }
}

int main()
{
    int num;

    cout << "Testing Multiple Catches" << endl;
    cout << "Enter an integer value: ";
    cin >> num;

    test(num);

    return 0;
}
