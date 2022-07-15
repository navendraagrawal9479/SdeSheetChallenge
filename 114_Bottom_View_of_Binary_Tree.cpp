#include <bits/stdc++.h>
using namespace std;

template<class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

vector<int> bottomView(BinaryTreeNode<int> *root)
{

    // Write your code here.
    map<int, int> m;
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int line = it.second;
        root = it.first;
        m[line] = root->data;
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
