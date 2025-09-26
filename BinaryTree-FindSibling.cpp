#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int val)
    {
        data = val;
        right = nullptr;
        left = nullptr;
    }
};

TreeNode* FindSilb(TreeNode* temp, int v)
{
    if(temp->right != nullptr && temp->left->data == v)
    {
        return temp->right; //base case 1
    }
    else if(temp->left != nullptr && temp->right->data == v)
    {
        return temp->left; //base case 2
    }
    TreeNode* LeftRes = FindSilb(temp->left, v);
    if(LeftRes != nullptr)
    {
        return LeftRes; //find target in the left subtree
    }
    return FindSilb(temp->right, v); //find target in the right subtree
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    TreeNode* sib = FindSilb(root, 4);
    cout << "The sibling of node 4 is: " << sib->data <<endl;
    return 0;
}