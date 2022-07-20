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

long long int maxPathSum(TreeNode<int> *root, long long int &height)
{
    if (!root)
        return 0;
    long long int lh = maxPathSum(root->left, height);
    long long int rh = maxPathSum(root->right, height);
    height = max(height, root->val + lh + rh);
    return root->val + max(lh, rh);
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    if (!root)
        return -1;
    if (!root->left)
        return -1;
    if (!root->right)
        return -1;
    long long int height = 0;
    maxPathSum(root, height);
    return height;
    // Write your code here.
}