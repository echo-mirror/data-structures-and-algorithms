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

int Count(Node* temp, int v)
{
    if (temp == nullptr)
    {
        return 0;
    }
    else if (temp->data == v)
    {
        return 1 + Count(temp->next, v);
    }
    else
    {
        return Count(temp->next, v);
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

    int num;
    num = Count(head, 7);
    cout << "the number of 7 in the link list is : " << num << endl;
    return 0;
}