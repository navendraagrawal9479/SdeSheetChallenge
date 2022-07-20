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

bool isleaf(TreeNode<int> *root)
{
    return !root->left and !root->right;
}
void leftBoundary(TreeNode<int> *root, vector<int> &ans)
{
    TreeNode<int> *node = root->left;
    while (node)
    {
        if (!isleaf(node))
            ans.push_back(node->data);
        if (node->left)
            node = node->left;
        else
            node = node->right;
    }
}
void rightBoundary(TreeNode<int> *root, vector<int> &ans)
{
    stack<int> s;
    TreeNode<int> *node = root->right;
    while (node)
    {
        if (!isleaf(node))
            s.push(node->data);
        if (node->right)
            node = node->right;
        else
            node = node->left;
    }
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
}
void leafnodes(TreeNode<int> *root, vector<int> &ans)
{
    if (isleaf(root))
        ans.push_back(root->data);
    if (root->left)
        leafnodes(root->left, ans);
    if (root->right)
        leafnodes(root->right, ans);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> ans;
    if (!root)
        return ans;
    ans.push_back(root->data);
    if (isleaf(root))
        return ans;
    leftBoundary(root, ans);
    leafnodes(root, ans);
    rightBoundary(root, ans);
    return ans;
}