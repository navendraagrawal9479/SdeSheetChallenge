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

int height(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;

    int lh = height(root->left);
    int rh = height(root->right);
    if (lh == -1 or rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}
bool isBalancedBT(BinaryTreeNode<int> *root)
{
    // Write your code here.
    if (height(root) != -1)
        return true;
    return false;
}