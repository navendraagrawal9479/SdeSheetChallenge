#include <bits/stdc++.h>
using namespace std;

int findPar(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findPar(parent[node], parent);
}
void unionGraph(int u, int v, vector<int> &rank, vector<int> &parent)
{
    u = findPar(u, parent);
    v = findPar(v, parent);
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}
static bool comp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph)
{
    // Write your code here.
    sort(graph.begin(), graph.end(), comp);
    int cost = 0;
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    vector<int> rank(n + 1, 0);
    for (int i = 0; i < graph.size(); i++)
    {
        int u = graph[i][0];
        int v = graph[i][1];
        int wt = graph[i][2];
        if (findPar(u, parent) != findPar(v, parent))
        {
            cost += wt;
            unionGraph(u, v, rank, parent);
        }
    }
    return cost;
}