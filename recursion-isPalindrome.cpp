#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s, int left, int right)
{
    //添加了一个输出功能，来检测每次比较的对象
    cout << "Comparing " << s[left] << " and " << s[right] << endl;
    if (left >= right)
    {
        return true;
    }
    else if (s[left] != s[right])
    {
        return false;
    }
    else
    {
        return isPalindrome(s, left + 1, right - 1);
    }
}

int main()
{
    string str;
    cout << "Please enter a string :";
    cin >> str;
    //注意访问越界问题，right是size-1而不是size
    if (isPalindrome(str, 0, str.size()-1))
    {
        cout << "This string is a Palindrome" << endl;
    }
    else
    {
        cout << "This string is not a Plaindrome" << endl;
    }
    return 0;
}