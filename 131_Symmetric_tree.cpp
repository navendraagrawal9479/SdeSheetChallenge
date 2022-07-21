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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

bool mirror(BinaryTreeNode<int> *root1, BinaryTreeNode<int> *root2)
{
    if (!root1 or !root2)
        return root1 == root2;
    if (root1->data != root2->data)
        return false;
    return mirror(root1->left, root2->right) and mirror(root1->right, root2->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    // Write your code here.
    return mirror(root, root);
}
