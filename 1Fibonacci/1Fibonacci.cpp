#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n, choice;
    int a, b, c;

    cout << "1. Non-Recursive Fibonacci" << endl;
    cout << "2. Recursive Fibonacci" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter number of terms: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Enter a positive number of terms.";
        return 0;
    }

    switch (choice)
    {
    case 1:
        a = 0;
        b = 1;

        cout << "Fibonacci Series: ";

        for (int i = 0; i < n; i++)
        {
            cout << a << " ";
            c = a + b;
            a = b;
            b = c;
        }
        break;

    case 2:
        cout << "Fibonacci Series: ";

        for (int i = 0; i < n; i++)
        {
            cout << fibonacci(i) << " ";
        }
        break;

    default:
        cout << "Invalid choice!";
    }

    return 0;
}
