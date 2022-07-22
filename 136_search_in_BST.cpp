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

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    // Write your code here.
    while (root)
    {
        if (root->data == x)
            return true;
        else if (root->data > x)
        {
            root = root->left;
        }
        else
            root = root->right;
    }
    return false;
}