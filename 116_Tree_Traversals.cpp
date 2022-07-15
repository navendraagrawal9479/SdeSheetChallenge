#include <bits/stdc++.h>
using namespace std;

template <class T>
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

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here.
    vector<int> pre, in, post;
    stack<pair<BinaryTreeNode<int> *, int>> s;
    s.push({root, 1});
    if (!root)
        return {};
    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->left)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right)
            {
                s.push({it.first->right, 1});
            }
        }
        else
            post.push_back(it.first->data);
    }
    return {in, pre, post};
}
