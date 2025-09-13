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

int SumList(Node* temp)
{
    if (temp->next == nullptr)
    {
        return temp->data;
    }
    else
    {
        return temp->data + SumList(temp->next);
    }
}

int main()
{
    Node* head = nullptr;
    head = new Node(2);
    head->next = new Node(8);
    head->next->next = new Node(10);

    int sum = SumList(head);
    cout << "the sum of the link list is : " << sum << endl;
    return 0;
}