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

void leftview(int level, TreeNode<int> *root, vector<int> &leftView)
{
    if (root == NULL)
        return;
    if (level == leftView.size())
        leftView.push_back(root->data);
    leftview(level + 1, root->left, leftView);
    leftview(level + 1, root->right, leftView);
}

vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> leftView;
    leftview(0, root, leftView);
    return leftView;
}