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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

TreeNode<int> *LCAinaBST(TreeNode<int> *root, TreeNode<int> *P, TreeNode<int> *Q)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    int curr = root->data;
    if (curr > P->data and curr > Q->data)
    {
        return LCAinaBST(root->left, P, Q);
    }
    else if (curr < P->data and curr < Q->data)
    {
        return LCAinaBST(root->right, P, Q);
    }
    return root;
}
