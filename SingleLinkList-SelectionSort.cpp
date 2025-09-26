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

void PrintList(Node* temp)
{
    if(temp->next != nullptr)
    {
        cout << temp->data << "->";
        PrintList(temp->next);
    }
    else
    {
        cout << temp->data << endl;
        return;
    }
}

Node* CreateLinkList(int n) //Create an unsorted list, input with consle
{
    Node* head = nullptr;
    Node* tail = nullptr; //Create 2 pointer, pointing to the fisrt and last node
    cout << "Please enter 15 integers, separated by spaces:" << endl;
    for(int i = 1; i <= n; i++)
    {
        int data;
        cin >> data;
        Node* newNode = new Node(data); //Get the value of nodes from input

        if(head == nullptr) //Create the fist node
        {
            head = newNode;
            tail = newNode;
        }
        else //Create the following nodes
        {
            tail->next = newNode; //Insert the new node
            tail = newNode; //Let the pointer point to the last node in the list
        }
    }
    return head;
}

void SelectionSort(Node*& temp)
{
    if(temp == nullptr || temp->next == nullptr) //base case
    {
        return;
    }

    Node* MinNode = temp;
    Node* PrevMin = nullptr;
    Node* current = temp->next;
    Node* Prevcur = temp;

    while(current != nullptr) //find the node with smallest value
    {
        if(current->data < MinNode->data)
        {
            MinNode = current;
            PrevMin = Prevcur;
        }
        Prevcur = current;
        current = current->next;
    }

    if(PrevMin != nullptr) //If the smallest node is not the first node, swap the nodes
    {
        if(PrevMin == temp) //If the smallest node is directly after head
        {
            temp->next = MinNode->next;
            MinNode->next = temp;
        }
        else
        {
            Node* tmp;
            PrevMin->next = temp;
            tmp = MinNode->next;
            MinNode->next = temp->next;
            temp->next = tmp;
        }
        temp = MinNode;
    }
    SelectionSort(temp->next);
}

int main()
{
    Node* list = CreateLinkList(15);
    cout << "The original list:" << endl;
    PrintList(list);
    cout << "After sorted: " << endl;
    SelectionSort(list);
    PrintList(list);
    return 0;
}