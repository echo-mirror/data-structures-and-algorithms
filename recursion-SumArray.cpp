#include <iostream>
using namespace std;

int SumArray(int arr[], int n)
{
    if (n == 0)
    {
        return arr[0];
    }
    else
    {
        return arr[n] + SumArray(arr, n-1);
    }
}

int main()
{
    int n;
    cout << "Please enter the size of the array : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n-1; i ++)
    {
        cin >> arr[i];
    }
    cout << "the sum of all its elements is " << SumArray(arr, n) << endl;
    return 0;
}