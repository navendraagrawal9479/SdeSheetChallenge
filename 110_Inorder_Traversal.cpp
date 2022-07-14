#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode *> s;
    vector<int> inorder;
    while (true)
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            if (s.empty())
                break;
            root = s.top();
            s.pop();
            inorder.push_back(root->data);
            root = root->right;
        }
    }
    return inorder;
}