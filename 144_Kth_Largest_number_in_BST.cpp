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

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

int KthLargestNumber(TreeNode<int> *root, int k)
{
    // Write your code here.
    TreeNode<int> *curr = root;
    int cnt = 0, size = 0, ans = -1;
    while (curr)
    {
        if (curr->left == NULL)
        {
            size++;
            curr = curr->right;
        }
        else
        {
            TreeNode<int> *prev = curr->left;
            while (prev->right and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == curr)
            {
                prev->right = NULL;
                size++;
                curr = curr->right;
            }
            else if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    curr = root;
    k = size - k + 1;
    while (curr)
    {
        if (curr->left == NULL)
        {
            cnt++;
            if (cnt == k)
                ans = curr->data;
            curr = curr->right;
        }
        else
        {
            TreeNode<int> *prev = curr->left;
            while (prev->right and prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == curr)
            {
                prev->right = NULL;
                cnt++;
                if (cnt == k)
                    ans = curr->data;
                curr = curr->right;
            }
            else if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
        }
    }
    return ans;
}