#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a;
    int b;
    cout << "Please enter two number :" << endl;
    cin >> a;
    cin >> b;
    cout << "The Greatest Common Divisor between " << a << " and " << b << " is " << gcd(a, b);
    return 0;
}