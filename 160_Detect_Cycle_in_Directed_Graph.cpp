#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, vector<int> &vis, vector<int> &dfsVis, vector<vector<int>> &graph)
{
    vis[i] = 1;
    dfsVis[i] = 1;
    for (auto it : graph[i])
    {
        if (!vis[it])
        {
            if (dfs(it, vis, dfsVis, graph))
                return true;
        }
        else if (dfsVis[it] == 1)
            return true;
    }
    dfsVis[i] = 0;
    return false;
}
int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // Write your code here.
    vector<vector<int>> graph(n + 1);
    vector<int> vis(n + 1, 0), dfsVis(n + 1, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i].first].push_back(edges[i].second);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, dfsVis, graph))
                return 1;
        }
    }
    return 0;
}