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

TreeNode<int> *construct(int instart, int inend, vector<int> &inorder, int prestart, int preend, vector<int> &preorder, unordered_map<int, int> &m)
{
    if (prestart > preend or instart > inend)
        return NULL;
    TreeNode<int> *root = new TreeNode<int>(preorder[prestart]);
    int inroot = m[preorder[prestart]];
    int countleft = inroot - instart;
    TreeNode<int> *left = construct(instart, inroot - 1, inorder, prestart + 1, prestart + countleft, preorder, m);
    TreeNode<int> *right = construct(inroot + 1, inend, inorder, prestart + 1 + countleft, preend, preorder, m);
    root->left = left;
    root->right = right;
    return root;
}
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
    //    Write your code here
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    return construct(0, inorder.size() - 1, inorder, 0, preorder.size() - 1, preorder, m);
}