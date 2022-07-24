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

void solve(BinaryTreeNode<int> *root, BinaryTreeNode<int> *&head, BinaryTreeNode<int> *&prev, int &f)
{
    if (!root)
        return;
    solve(root->left, head, prev, f);
    if (f == 0)
    {
        f = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        root->left = prev;
        prev = prev->right;
    }
    solve(root->right, head, prev, f);
}
BinaryTreeNode<int> *BTtoDLL(BinaryTreeNode<int> *root)
{
    BinaryTreeNode<int> *head = NULL, *prev = NULL;
    int f = 0;
    solve(root, head, prev, f);
    return head;
}