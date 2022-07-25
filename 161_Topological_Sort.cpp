#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> &vis, stack<int> &s, vector<vector<int>> &graph)
{
    vis[i] = 1;
    for (auto it : graph[i])
    {
        if (!vis[it])
        {
            dfs(it, vis, s, graph);
        }
    }
    s.push(i);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    vector<vector<int>> graph(v);
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int> vis(v, 0);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, s, graph);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}