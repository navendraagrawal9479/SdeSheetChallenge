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

vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>s;
    vector<int>preorder;
    while(true){
        if(root){
            s.push(root);
            preorder.push_back(root->data);
            root=root->left;
        }
        else{
            if(s.empty())break;
            root = s.top();
            s.pop();
            root = root->right;
        }
    }
    return preorder;
}