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

string serializeTree(TreeNode<int> *root)
{
    //    Write your code here for serializing the tree
    if (!root)
        return "";
    queue<TreeNode<int> *> q;
    q.push(root);
    string s = "";
    while (!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            s.append("#,");
        }
        else
        {
            s.append(to_string(curr->data) + ',');
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode<int> *deserializeTree(string &s)
{
    //    Write your code here for deserializing the tree
    if (s.size() == 0)
        return NULL;
    stringstream st(s);
    string str;
    getline(st, str, ',');
    TreeNode<int> *curr = new TreeNode<int>(stoi(str));
    queue<TreeNode<int> *> q;
    q.push(curr);
    while (!q.empty())
    {
        TreeNode<int> *root = q.front();
        q.pop();
        getline(st, str, ',');
        if (str == "#")
        {
            root->left = NULL;
        }
        else
        {
            root->left = new TreeNode<int>(stoi(str));
            q.push(root->left);
        }
        getline(st, str, ',');
        if (str == "#")
        {
            root->right = NULL;
        }
        else
        {
            root->right = new TreeNode<int>(stoi(str));
            q.push(root->right);
        }
    }
    return curr;
}