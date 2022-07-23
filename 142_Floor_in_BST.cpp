#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

int floorInBST(TreeNode<int> *root, int X)
{
    int pre = -1;
    while (root != NULL)
    {
        if (root->val > X)
        {
            root = root->left;
        }
        else
        {
            pre = root->val;
            root = root->right;
        }
    }
    return pre;
}