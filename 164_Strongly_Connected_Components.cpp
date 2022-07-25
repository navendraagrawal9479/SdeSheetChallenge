#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &edges, vector<int> &vis, stack<int> &topo)
{
    vis[node] = 1;
    for (auto it : edges[node])
    {
        if (!vis[it])
            dfs(it, edges, vis, topo);
    }
    topo.push(node);
}

void revdfs(int node, vector<vector<int>> &transpose, vector<int> &vis, vector<int> &ds)
{
    vis[node] = 1;
    ds.push_back(node);
    for (auto it : transpose[node])
    {
        if (!vis[it])
        {
            revdfs(it, transpose, vis, ds);
        }
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    stack<int> topo;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, topo);
        }
    }
    vector<vector<int>> transpose(adj.size());
    for (int i = 0; i < n; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            transpose[it].push_back(i);
        }
    }
    vector<vector<int>> ans;
    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();
        if (!vis[top])
        {
            vector<int> ds;
            revdfs(top, transpose, vis, ds);
            ans.push_back(ds);
        }
    }
    return ans;
}