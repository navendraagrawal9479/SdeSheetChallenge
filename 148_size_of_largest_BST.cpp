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

class NodeValue
{
public:
    int maxnode, minnode, maxsize;
    NodeValue(int max, int min, int maxsize)
    {
        maxnode = max;
        minnode = min;
        this->maxsize = maxsize;
    }
};
NodeValue maxSumBSTHelp(TreeNode<int> *root)
{
    if (!root)
    {
        return NodeValue(INT_MIN, INT_MAX, 0);
    }
    auto left = maxSumBSTHelp(root->left);
    auto right = maxSumBSTHelp(root->right);

    if (root->data > left.maxnode and root->data < right.minnode)
    {
        return NodeValue(max(root->data, right.maxnode), min(root->data, left.minnode), left.maxsize + right.maxsize + 1);
    }
    return NodeValue(INT_MAX, INT_MIN, max(left.maxsize, right.maxsize));
}
int largestBST(TreeNode<int> *root)
{
    return maxSumBSTHelp(root).maxsize;
}
