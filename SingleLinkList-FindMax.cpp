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

int FindMax(Node* temp) //先比较最后一个节点和它前面的节点，然后再比较再前面的节点…… 
                        //最终回到最顶层，得到整个链表最大值
{
    if (temp == nullptr) //如果链表为空
    {
        return INT_MIN;
    }
    if (temp->next == nullptr)
    {
        return temp->data;
    }
    else
    {
        int maxRest = FindMax(temp->next);
        if (temp->data > maxRest)
        {
            return temp->data;
        }
        else
        {
            return maxRest;
        }
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

    int max = FindMax(head);
    cout << "the biggest value in the link list is : " << max << endl;
    return 0;
}