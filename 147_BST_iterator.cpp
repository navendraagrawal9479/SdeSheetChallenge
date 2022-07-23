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

class BSTiterator
{
private:
    stack<TreeNode<int> *> s;

public:
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        pushall(root);
    }

    void pushall(TreeNode<int> *root)
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
    }

    int next()
    {
        // write your code here
        if (!hasNext())
            return -1;
        TreeNode<int> *next = s.top();
        s.pop();
        pushall(next->right);
        return next->data;
    }

    bool hasNext()
    {
        return !s.empty();
        // write your code here
    }
};