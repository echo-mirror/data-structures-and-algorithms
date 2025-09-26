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

int CountNodes(TreeNode* temp)
{
    if(temp == nullptr)
    {
        return 0;
    }
    int LeftCount = CountNodes(temp->left);
    int RightCount = CountNodes(temp->right);
    return 1 + LeftCount + RightCount;
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int NodeNum = CountNodes(root);
    cout << "This binary tree has " << NodeNum << " Nodes in total." << endl;
    return 0;
}