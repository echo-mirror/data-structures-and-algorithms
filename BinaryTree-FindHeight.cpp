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

int FindHeight(TreeNode* temp)
{
    if(temp == nullptr)
    {
        return -1; //if the tree is empty
    }
    if(temp->left == nullptr && temp->right == nullptr)
    {
        return 0; //base case
    }
    int LeftHeight = FindHeight(temp->left);
    int RightHeight = FindHeight(temp->right);
    return 1 + max(LeftHeight, RightHeight); //non-base case
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int height = FindHeight(root);
    cout << "the height of the tree is : " << height << endl;
    return 0;
}