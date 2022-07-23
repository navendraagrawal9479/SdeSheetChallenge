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

int kthSmallest(TreeNode<int> *root, int k)
{
    //	Write the code here.
    int cnt = 0, ans = -1;
    while (root)
    {
        if (root->left == NULL)
        {
            cnt++;
            if (cnt == k)
                ans = root->data;
            root = root->right;
        }
        else
        {
            TreeNode<int> *prev = root->left;
            while (prev->right and prev->right != root)
            {
                prev = prev->right;
            }
            if (prev->right == root)
            {
                prev->right = NULL;
                cnt++;
                if (cnt == k)
                    ans = root->data;
                root = root->right;
            }
            else if (prev->right == NULL)
            {
                prev->right = root;
                root = root->left;
            }
        }
    }
    return ans;
}