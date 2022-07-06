#include <bits/stdc++.h>
using namespace std;

class Node
{
    Node *links[2];

public:
    bool containsKey(int bit)
    {
        return links[bit] != NULL;
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
    Node *get(int bit)
    {
        return links[bit];
    }
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int Max(int num)
    {
        Node *node = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit))
            {
                maxnum = maxnum | (1 << i);
                node = node->get(1 - bit);
            }
            else
                node = node->get(bit);
        }
        return maxnum;
    }
};

static bool compare(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    int size = queries.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> q;
    for (int i = 0; i < size; i++)
    {
        q.push_back({queries[i][0], queries[i][1], i});
    }
    sort(q.begin(), q.end(), compare);
    vector<int> ans(size, 0);
    Trie t;
    int ind = 0;
    for (int i = 0; i < size; i++)
    {
        int a = q[i][1];
        int x = q[i][0];
        while (ind < arr.size() and arr[ind] <= a)
        {
            t.insert(arr[ind]);
            ind++;
        }
        if (ind == 0)
            ans[q[i][2]] = -1;
        else
            ans[q[i][2]] = t.Max(x);
    }
    return ans;
}