#include <bits/stdc++.h>
using namespace std;

template <typename T = int>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->data = val;
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

vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    queue<pair<TreeNode<int> *, int>> q;
    map<int, vector<int>> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        root = it.first;
        m[line].push_back(root->data);
        if (root->left)
            q.push({root->left, line - 1});
        if (root->right)
            q.push({root->right, line + 1});
    }
    vector<int> ans;
    for (auto it : m)
    {
        for (auto i : it.second)
        {
            ans.push_back(i);
        }
    }
    return ans;
}