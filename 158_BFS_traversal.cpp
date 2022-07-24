#include <bits/stdc++.h>
using namespace std;

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> bfs, vis(vertex + 1, 0);
    vector<vector<int>> graph(vertex);
    for (auto it : edges)
    {
        graph[it.first].push_back(it.second);
        graph[it.second].push_back(it.first);
    }
    for (int i = 0; i < vertex; i++)
    {
        if (!vis[i])
        {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while (!q.empty())
            {
                int node = q.front();
                q.pop();
                bfs.push_back(node);
                for (auto it : graph[i])
                {
                    if (!vis[it])
                    {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }
    return bfs;
}