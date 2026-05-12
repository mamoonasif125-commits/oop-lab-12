#include <iostream>
#include <exception>
using namespace std;

class OutOfRangeException : public exception
{
private:
    const char* message;

public:
    OutOfRangeException(const char* msg = "Error: Mark is out of valid range (0-100).") : message(msg)
    {
    }
    const char* what() const throw() override
    {
        return message;
    }
};
float calculateAverage(int m1, int m2, int m3, int m4)
{
    int marks[4] = { m1, m2, m3, m4 };

    for (int i = 0; i < 4; i++)
    {
        if (marks[i] < 0 || marks[i] > 100)
        {
            throw OutOfRangeException();
        }
    }

    float sum = static_cast<float>(m1 + m2 + m3 + m4);
    return sum / 4.0f;
}

int main()
{
    int m1, m2, m3, m4;

    cout << "Enter marks for 4 courses: ";
    cin >> m1 >> m2 >> m3 >> m4;

    try
    {
        float avg = calculateAverage(m1, m2, m3, m4);
        cout << "Average = " << avg << endl;
    }
    catch (const OutOfRangeException& e)
    {
        cerr << e.what() << endl;
    }
    catch (const exception& e)
    {
        cerr << "Standard exception: " << e.what() << endl;
    }

    return 0;
}
