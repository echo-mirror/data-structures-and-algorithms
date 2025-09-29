#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode* parent;
    BSTNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

BSTNode* Insert(BSTNode* temp, int v) //return the head of the new tree
{
    if(temp == nullptr)     //base case
    {
        return new BSTNode(v);
    }
    if(v > temp->data)
    {
        BSTNode* child = Insert(temp->right, v); 
        temp->right = child;
        child->parent = temp;   //need to link the nodes
    }
    if(v < temp->data)
    {
        BSTNode* child = Insert(temp->left, v);
        temp->left = child;
        child->parent = temp;
    }
    return temp;    //after insertion, retrun to the root
}

BSTNode* Findmin(BSTNode* temp)
{
    if(temp == nullptr)
    {
        return nullptr;
    }
    if(temp->left == nullptr)
    {
        return temp;
    }
    return Findmin(temp->left);
}

BSTNode* Findmax(BSTNode* temp)
{
    if(temp == nullptr)
    {
        return nullptr;
    }
    if(temp->right == nullptr)
    {
        return temp;
    }
    return Findmax(temp->right);
}

BSTNode* DeletePre(BSTNode* temp, int v) //Replace target with the value of its predecessor
{
    if(temp == nullptr)
    {
        return nullptr;
    }
    else if(v > temp->data)
    {
        temp->right = DeletePre(temp->right, v);
    }
    else if(v < temp->data)
    {
        temp->left = DeletePre(temp->left, v);
    }
    else    //found target
    {
        if(temp->left == nullptr && temp->right == nullptr) //if target has no child
        {
            delete temp;
            return nullptr;
        }
        else if(temp->left == nullptr) //if target only has right child
        {
            BSTNode* tmp = temp->right;
            delete temp;
            return tmp;
        }
        else if(temp->right == nullptr) //if target only has left child
        {
            BSTNode* tmp = temp->left;
            delete temp;
            return tmp;
        }
        else //if target has both left and right child
        {
            BSTNode* pred = Findmax(temp->left);
            temp->data = pred->data;
            temp->left = DeletePre(temp->left, pred->data);
        }
    }
    return temp;
}

void InOrderT(BSTNode* temp)
{
    if(temp == nullptr)
    {
        return;
    }
    InOrderT(temp->left);
    cout << temp->data << " " ;
    InOrderT(temp->right);
}

int main()
{
    BSTNode* root = nullptr;
    root = Insert(root, 40);
    root = Insert(root, 60);
    root = Insert(root, 20);
    root = Insert(root, 80);
    root = Insert(root, 50);
    root = Insert(root, 10);
    root = Insert(root, 30);
    root = Insert(root, 15);
    root = Insert(root, 5);
    root = Insert(root, 35);
    root = Insert(root, 25);
    root = Insert(root, 45);
    root = Insert(root, 55);
    root = Insert(root, 70);
    root = Insert(root, 90);
    root = Insert(root, 32);
    root = Insert(root, 33);
    root = Insert(root, 48);
    root = Insert(root, 46);
    cout << "after insertion:" << endl;
    InOrderT(root);
    cout << endl;
    cout << "Delete 40 :" << endl;
    root = DeletePre(root, 40);
    InOrderT(root);
    cout << endl;
    cout << "Then delete 20:" << endl;
    root = DeletePre(root, 20);
    InOrderT(root);
    return 0;
}