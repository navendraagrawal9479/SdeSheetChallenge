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

void Leaf(TreeNode<int> *root, TreeNode<int> *leaf, stack<pair<TreeNode<int> *, bool>> &st, bool prev)
{

    if (!st.empty() and st.top().first == leaf)
        return;

    if (root == NULL)
        return;

    st.push({root, prev});

    Leaf(root->left, leaf, st, true);

    Leaf(root->right, leaf, st, false);

    if (!st.empty() and st.top().first->data != leaf->data)
        st.pop();
}

TreeNode<int> *invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)

{

    // Write your code here.

    // L=1,R=0

    stack<pair<TreeNode<int> *, bool>> st;

    Leaf(root, leaf, st, false);

    bool prevDir = st.top().second;

    st.pop();

    TreeNode<int> *t = leaf;

    while (!st.empty())
    {

        if (prevDir == true)
        {

            st.top().first->left = NULL;

            t->left = st.top().first;
        }

        else
        {

            st.top().first->right = st.top().first->left;

            st.top().first->left = NULL;

            t->left = st.top().first;
        }

        t = st.top().first;

        prevDir = st.top().second;

        st.pop();
    }

    if (leaf->right)
    {

        leaf->left = leaf->right;

        leaf->right = NULL;
    }

    return leaf;
}