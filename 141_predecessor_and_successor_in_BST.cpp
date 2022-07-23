#include <bits/stdc++.h>
using namespace std;

template <typename T>

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

    ~BinaryTreeNode()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

pair<int, int> predecessorSuccessor(BinaryTreeNode<int> *root, int key)
{
    int pre = -1;
    int suc = -1;
    BinaryTreeNode<int> *curr = root;
    while (root != NULL)
    {
        if (root->data <= key)
        {
            root = root->right;
        }
        else
        {
            suc = root->data;
            root = root->left;
        }
    }
    root = curr;
    while (root != NULL)
    {
        if (root->data >= key)
        {
            root = root->left;
        }
        else
        {
            pre = root->data;
            root = root->right;
        }
    }
    pair<int, int> ans = {pre, suc};
    return ans;
}
