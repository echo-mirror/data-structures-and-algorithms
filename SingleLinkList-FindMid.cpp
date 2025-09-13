#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

int FindMid(Node* temp1, Node* temp2) //前提：链表有奇数个节点
{
    if (temp2->next == nullptr) //到达终点
    {
        return temp1->data;
    }
    else
    {
        return FindMid(temp1->next, temp2->next->next);
    }
}

int main()
{
    Node* head = nullptr;
    head = new Node(5);
    head->next = new Node(8);
    head->next->next = new Node(7);
    head->next->next->next = new Node(17);
    head->next->next->next->next = new Node(7);
    head->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next = new Node(14);
    int mid = FindMid(head, head); //一个容易犯错的点：快指针也应该从头开始
    cout << "The value in the middle of the list is : " << mid << endl;
    return 0;
}