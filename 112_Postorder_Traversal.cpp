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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> post;
    stack<TreeNode *> s;
    while (root or !s.empty())
    {
        if (root)
        {
            s.push(root);
            root = root->left;
        }
        else
        {
            TreeNode *temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                post.push_back(temp->data);
                while (!s.empty() and temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    post.push_back(temp->data);
                }
            }
            else
                root = temp;
        }
    }
    return post;
}