#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* prev;
    Node* next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

void PrintList(Node* temp)
{
    if (temp == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }
    else
    {
        cout << temp->data << "->";
        PrintList(temp->next);
    }
}

void InsertAfter(Node*& temp, int val, int v) //Insert B after v
{
    if (temp == nullptr)
    {
        cout << "can't find value v" << endl;
        return;
    }
    else if (temp->data == val)
    {
        Node* B = new Node(v);
        if (temp->next == nullptr) //special case: when inserting on the tail
        {
            B->next = nullptr;
            B->prev = temp;
            temp->next = B;
        }
        else //normal case
        {
            B->next = temp->next;
            B->prev = temp;
            temp->next->prev = B;
            temp->next = B;
        }
        return;
        
    }
    else
    {
        InsertAfter(temp->next, val, v);
    }
}

void InsertBefore(Node*& temp, int val, int v)
{
    if (temp == nullptr)
    {
        cout << "Can't find value " << val << endl;
        return;
    }
    else if (temp->data == val)
    {
        Node* B = new Node(v);
        if (temp->prev == nullptr) //Special case: inserting before the head
        {
            B->next = temp;
            temp->prev = B;
            temp = B; //Update the head
        }
        else //Normal case:
        {
            B->next = temp;
            B->prev = temp->prev;
            temp->prev->next = B;
            temp->prev = B;
        }
        return;
    }
    else
    {
        InsertBefore(temp->next, val, v);
    }
}

void DeleteNode(Node*& temp, int v)
{
    if (temp == nullptr)
    {
        cout << "Can't find value" << v << endl;
        return;
    }
    else if (temp->data == v)
    {
        Node* toDelet = temp;
        if (temp->prev == nullptr && temp->next == nullptr) //Only have one node
        {
            temp = nullptr;
        }
        else if (temp->prev == nullptr) //Delete head
        {
            temp->next->prev = nullptr;
            temp = temp->next;
        }
        else if (temp->next == nullptr) //Delete tail
        {
            temp->prev->next = nullptr;
            //temp = temp->prev; Edit temp only when you need to change the head
        }
        else // Normal case
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }
        delete toDelet;
        return;
    }
    DeleteNode(temp->next, v);
}

int main()
{
    Node* head = nullptr;
    head = new Node(1);
    cout << "The original list : " << endl;
    PrintList(head);

    cout << "Insert 2 after 1: " << endl;
    InsertAfter(head, 1, 2);
    PrintList(head);

    cout << "Insert 0 before 1: " << endl;
    InsertBefore(head, 1, 0);
    PrintList(head);

    cout << "Delete 0: " << endl;
    DeleteNode(head, 0);
    PrintList(head);

    return 0;
}