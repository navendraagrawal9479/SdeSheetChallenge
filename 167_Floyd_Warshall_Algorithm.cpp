#include <bits/stdc++.h>
using namespace std;

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        graph[edges[i][0]][edges[i][1]] = edges[i][2];
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] == 1e9 or graph[k][j] == 1e9)
                    continue;
                else
                {
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (graph[i][i] < 0)
            return -1;
    return graph[src][dest];
}