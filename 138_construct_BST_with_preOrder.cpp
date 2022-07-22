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
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

TreeNode<int> *construct(vector<int> &preOrder, int &i, int bound)
{
    if (i == preOrder.size() or preOrder[i] > bound)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preOrder[i]);
    i++;
    root->left = construct(preOrder, i, root->data);
    root->right = construct(preOrder, i, bound);
    return root;
}
TreeNode<int> *preOrderTree(vector<int> &preOrder)
{
    // Write your code here.
    int i = 0;
    return construct(preOrder, i, INT_MAX);
}