#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* FindParent(TreeNode* temp, int v)
{
    if(temp == nullptr)
    {
        return nullptr;
    }
    if(temp->data == v)
    {
        return nullptr; // root has no parent
    }
    if(temp->left != nullptr && temp->left->data == v)
    {
        return temp;
    }
    if(temp->right != nullptr && temp->right->data == v)
    {
        return temp;
    }
    TreeNode* LeftRes = FindParent(temp->left, v);
    if(LeftRes != nullptr)
    {
        return LeftRes;
    }
    return FindParent(temp->right, v);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    TreeNode* parent = FindParent(root, 4);
    cout << "The parent of node 4 is: " << parent->data <<endl;
    return 0;
}