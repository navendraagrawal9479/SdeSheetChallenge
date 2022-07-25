#include <bits/stdc++.h>
using namespace std;

bool hasCycle(int s, int par, vector<vector<int>> &adj, vector<int> &vis)
{
    vis[s] = 1;
    for (auto it : adj[s])
    {
        if (!vis[it])
        {
            if (hasCycle(it, s, adj, vis))
                return true;
        }
        else if (par != it)
            return true;
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    vector<vector<int>> adj(n + 1);
    for (auto it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (hasCycle(i, -1, adj, vis))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
