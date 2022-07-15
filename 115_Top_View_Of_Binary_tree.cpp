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

vector<int> getTopView(TreeNode<int> *root)
{
    // Write your code here.
    if (!root)
        return {};
    queue<pair<TreeNode<int> *, int>> q;
    map<int, int> m;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        root = it.first;
        if (m.find(line) == m.end())
        {
            m[line] = root->val;
        }
        if (root->left)
        {
            q.push({root->left, line - 1});
        }
        if (root->right)
        {
            q.push({root->right, line + 1});
        }
    }
    vector<int> ans;
    for (auto it : m)
    {
        ans.push_back(it.second);
    }
    return ans;
}