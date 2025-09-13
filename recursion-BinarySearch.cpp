#include <iostream>
using namespace std;

int BinarySearch(int arr[], int left, int right, int target)
{
    int mid = (left + right)/ 2;
    if (left > right)
    {
        //函数返回值是int，为了表示找不到，返回一个不可能是index的值的数
        return -1;
    }
    if (arr[mid] == target)
    {
        return mid + 1;
    }
    if (arr[mid] < target)
    {
        return BinarySearch(arr, mid + 1, right, target);
    }
    else
    {
        return BinarySearch(arr, left, mid - 1, target);
    }

}

int main()
{
    int n;
    cout << "Please enter the size of an array :";
    cin >> n;
    int arr[n];
    cout << "Please enter the array :";
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }
    int t;
    cout << "Please enter the target: ";
    cin >> t;
    cout << "The target element is in the " << BinarySearch(arr, 0, n-1, t) << "th of your array.";
    return 0;
}