#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    TreeNode<int> *curr = root, *prev = NULL;
    while (curr)
    {
        if (curr->left)
        {
            prev = curr->left;
            while (prev->right)
            {
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
        }
        curr = curr->right;
    }
    curr = root;
    while (curr)
    {
        curr->left = NULL;
        curr = curr->right;
    }
    return root;
}