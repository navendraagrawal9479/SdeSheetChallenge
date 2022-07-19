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

int height(TreeNode<int> *root, int &maxi)
{
    if (!root)
        return 0;
    int lh = height(root->left, maxi);
    int rh = height(root->right, maxi);

    maxi = max(maxi, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode<int> *root)
{
    // Write Your Code Here.
    int maxi = 0;
    height(root, maxi);
    return maxi;
}
