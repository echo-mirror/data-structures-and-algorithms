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

int FindMax(TreeNode* temp) //assume the tree has at least one node
{
    int MaxLeft;
    int MaxRight; //for each node, there are 4 possibilities:
    if(temp->left == nullptr && temp->right == nullptr)
    {
        return temp->data;
    } 
    else if(temp->left == nullptr )
    {
        MaxLeft = temp->data;
        MaxRight = FindMax(temp->right);
    }
    else if(temp->right == nullptr)
    {
        MaxRight = temp->data;
        MaxLeft = FindMax(temp->left);
    }
    else
    {
        MaxLeft = FindMax(temp->left);
        MaxRight = FindMax(temp->right);
    }
    int Max = max(MaxLeft, MaxRight);
    return max(Max, temp->data);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    int max = FindMax(root);
    cout << "the max value in the tree is : " << max << endl;
    return 0;
}