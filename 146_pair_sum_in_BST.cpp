#include <bits/stdc++.h>
using namespace std;

template <typename T>
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

    ~BinaryTreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

class BSTiterator
{
private:
    stack<BinaryTreeNode<int> *> s;
    bool reverse;

public:
    BSTiterator(BinaryTreeNode<int> *root, bool isreverse)
    {
        reverse = isreverse;
        pushall(root);
    }
    int next()
    {
        BinaryTreeNode<int> *next = s.top();
        s.pop();
        if (reverse)
            pushall(next->left);
        else
            pushall(next->right);
        return next->data;
    }
    void pushall(BinaryTreeNode<int> *root)
    {
        while (root)
        {
            s.push(root);
            root = !reverse ? root->left : root->right;
        }
    }
};
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    BSTiterator l(root, false), r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j)
    {
        if (i + j == k)
            return true;
        else if (i + j < k)
        {
            i = l.next();
        }
        else
            j = r.next();
    }
    return false;
}