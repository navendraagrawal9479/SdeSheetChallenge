#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>> &graph, vector<int> &vis, vector<int> &temp)
{
    temp.push_back(i);
    vis[i] = 1;
    for (auto it : graph[i])
    {
        if (!vis[it])
        {
            dfs(it, graph, vis, temp);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    vector<vector<int>> graph(V);
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<int> vis(V, 0);
    vector<vector<int>> ans;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            vector<int> temp;
            dfs(i, graph, vis, temp);
            ans.push_back(temp);
        }
    }
    return ans;
}