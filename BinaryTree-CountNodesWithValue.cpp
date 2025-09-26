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

int CountNodesWithValue(TreeNode* temp, int v)
{
    if(temp == nullptr)
    {
        return 0;
    }
    else if(temp->data == v)
    {
        return 1 + CountNodesWithValue(temp->left, v) + CountNodesWithValue(temp->right, v);
    }
    else
    {
        return 0 + CountNodesWithValue(temp->left, v) + CountNodesWithValue(temp->right, v);
    }
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int n = CountNodesWithValue(root, 5);
    cout << "the number of value = 5 is : " << n << endl;
    return 0;
}