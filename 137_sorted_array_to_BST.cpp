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

TreeNode<int> *construct(vector<int> &arr, int l, int h)
{
    if (l > h)
        return NULL;
    int mid = (l + h) / 2;
    TreeNode<int> *root = new TreeNode<int>(arr[mid]);
    root->left = construct(arr, l, mid - 1);
    root->right = construct(arr, mid + 1, h);
    return root;
}
TreeNode<int> *sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    return construct(arr, 0, arr.size() - 1);
}