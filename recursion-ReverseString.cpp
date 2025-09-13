#include <iostream>
#include <string>
using namespace std;

//注意这次的函数返回类型是void
void ReverseString(string &s, int left, int right)
{
    if (left >= right)
    {
        //因为是void，无法返回什么值，所以只写一个return来中断递归
        return;
    }
    //交换的元素的类型是char，因此tmp的类型也必须保持一致
    char tmp;
    tmp = s[right];
    s[right] = s[left];
    s[left] = tmp;
    //函数是void，因此递归的情况不能用retrun，直接调用自身
    ReverseString(s, left + 1, right - 1);
}

int main()
{
    string str;
    cout << "Please enter a string :";
    cin >> str;
    ReverseString(str, 0, str.size() - 1);
    cout << str << endl;
    return 0;
}