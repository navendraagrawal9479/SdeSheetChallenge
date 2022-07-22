#include <bits/stdc++.h>
using namespace std;

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

bool isBalanced(BinaryTreeNode<int> *root, int Lbound, int Ubound)
{
    if (root == NULL)
        return true;
    if (root->data < Lbound or root->data > Ubound)
        return false;
    return isBalanced(root->left, Lbound, root->data) and isBalanced(root->right, root->data, Ubound);
}
bool validateBST(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (!root)
        return true;
    if (!root->left and !root->right)
        return true;
    return isBalanced(root, INT_MIN, INT_MAX);
}