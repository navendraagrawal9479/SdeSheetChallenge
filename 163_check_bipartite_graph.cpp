#include <bits/stdc++.h>
using namespace std;

bool bipartite(int node, vector<vector<int>> &graph, vector<int> &color)
{
    for (auto it : graph[node])
    {
        if (color[it] == -1)
        {
            color[it] = !color[node];
            if (!bipartite(it, graph, color))
                return false;
        }
        else if (color[it] == color[node])
            return false;
    }
    return true;
}
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == 1)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 1;
            if (!bipartite(i, graph, color))
                return false;
        }
    }
    return true;
}