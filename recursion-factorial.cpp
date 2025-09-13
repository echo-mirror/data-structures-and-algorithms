#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else 
    {
        return n * factorial(n-1);
    }
}

int main()
{
    int n;
    cout << "Please enter an integer n : ";
    cin >> n;
    cout << "the result of n! is " << factorial(n) << endl;
    return 0;
}