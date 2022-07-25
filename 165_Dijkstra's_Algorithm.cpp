#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Write your code here.
    vector<vector<pair<int, int>>> graph(vertices);
    for (int i = 0; i < vec.size(); i++)
    {
        graph[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        graph[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    q.push({0, source});
    while (!q.empty())
    {
        auto i = q.top();
        q.pop();
        int prevdist = i.first;
        int node = i.second;
        for (auto it : graph[node])
        {
            if (prevdist + it.second < dist[it.first])
            {
                dist[it.first] = prevdist + it.second;
                q.push({dist[it.first], it.first});
            }
        }
    }
    return dist;
}
