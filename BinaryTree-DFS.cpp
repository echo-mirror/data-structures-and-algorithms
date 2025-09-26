#include <iostream>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

void DFSPreOrder(TreeNode* temp) // P->L->R
{
    if (temp == nullptr)
    {
        return;
    }
    cout << temp->data << " ";
    DFSPreOrder(temp->left);
    DFSPreOrder(temp->right);
}

void DFSPostOrder(TreeNode* temp) // L->R->P
{
    if (temp == nullptr)
    {
        return;
    }
    DFSPostOrder(temp->left);
    DFSPostOrder(temp->right);
    cout << temp->data << " ";
}

void DFSInOrder(TreeNode* temp) // L->P->R
{
    if(temp == nullptr)
    {
        return;
    }
    DFSInOrder(temp->left);
    cout << temp->data << " ";
    DFSInOrder(temp->right);
}

int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Pre-order DFS Traversal:" << endl;
    DFSPreOrder(root);
    cout << endl;

    cout << "Post-order DFS Traversal:" << endl;
    DFSPostOrder(root);
    cout << endl;

    cout << "In-order DFS Traversal:" << endl;
    DFSInOrder(root);
    cout << endl;
    return 0;
}