#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int val)
    {
        data = val;
        next = nullptr;
    }
};

void insertAfter(Node*& temp, Node* B, int v)
{
    if (temp == nullptr)
    {
        cout << "Unable to find value " << v << endl;
        return;
    }
    if (temp->data == v)
    {
        B->next = temp->next;
        temp->next = B;
        return;
    }
    else 
    {
        insertAfter(temp->next, B, v);
    }
}

void insertBefore(Node*& temp, Node* B, int v)
{
    if (temp == nullptr)
    {
        cout << "Unable to find the value " << v << endl;
        return;
    }
    if (temp->data == v)
    {
        B->next = temp;
        temp = B; //把指针 temp 本身指向新节点,
                  //因为 temp 是引用，所以这一行会修改链表中原来指向 temp 的指针，
                  //让它指向新节点B，完成真正的插入。
    }
    else
    {
        return insertBefore( temp->next, B, v);
    }
}

void printList(Node* temp)
{
    if (temp == nullptr) //如果写成temp->next，会遗漏最后一个节点
    {
        cout << "NULL" << endl;
        return;
    }
    else
    {
        cout << temp->data << "->";
        return printList(temp->next);
    }
}

void deleteNode(Node*& temp, int v)
{
    if (temp == nullptr)
    {
        cout << "can't find value " << v << endl;
        return;
    }
    if (temp->data == v)
    {
        Node* toDelet = temp; //注意这里要先保存当前要删除的节点，而不是直接删除temp
        temp = temp->next;
        delete toDelet;
        return;
    }
    else
    {
        return deleteNode(temp->next, v);
    }
}

int main()
{
    Node* head = nullptr;

    head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "initial link list: " << endl;
    printList(head);

    Node* B1 = new Node(25);
    cout << "insert 25 after 20: " << endl;
    insertAfter(head, B1, 20);
    printList(head);

    Node* B2 = new Node(5);
    cout << "insert 5 before 10: " << endl;
    insertBefore(head, B2, 10);
    printList(head);

    cout << "delete 5: " << endl;
    deleteNode(head, 5);
    printList(head);
    return 0;
}