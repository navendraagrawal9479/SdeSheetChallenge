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

TreeNode<int> *construct(int inStart, int inEnd, vector<int> &inorder, int postStart, int postEnd, vector<int> &postorder, unordered_map<int, int> &m)
{
    if (inStart > inEnd or postStart > postEnd)
        return NULL;

    TreeNode<int> *root = new TreeNode<int>(postorder[postEnd]);
    int inroot = m[postorder[postEnd]];
    int numsright = inEnd - inroot;
    TreeNode<int> *left = construct(inStart, inroot - 1, inorder, postStart, postEnd - numsright - 1, postorder, m);
    TreeNode<int> *right = construct(inroot + 1, inEnd, inorder, postEnd - numsright, postEnd - 1, postorder, m);
    root->left = left;
    root->right = right;
    return root;
}
TreeNode<int> *getTreeFromPostorderAndInorder(vector<int> &postorder, vector<int> &inorder)
{
    // Write your code here.
    unordered_map<int, int> m;
    for (int i = 0; i < inorder.size(); i++)
    {
        m[inorder[i]] = i;
    }
    return construct(0, inorder.size() - 1, inorder, 0, postorder.size() - 1, postorder, m);
}
