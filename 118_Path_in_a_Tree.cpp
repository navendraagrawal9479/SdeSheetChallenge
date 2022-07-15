#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
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
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

bool isPresent(TreeNode<int> *root, vector<int> &ans, int x)
{
    if (!root)
        return false;
    ans.push_back(root->data);
    if (root->data == x)
        return true;
    if (isPresent(root->left, ans, x) or isPresent(root->right, ans, x))
        return true;
    ans.pop_back();
    return false;
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    isPresent(root, ans, x);
    return ans;
}
