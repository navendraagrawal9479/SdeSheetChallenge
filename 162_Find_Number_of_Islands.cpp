#include <bits/stdc++.h>
using namespace std;

int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};
void numberOfIslands(int **arr, int x, int y, int n, int m)
{
    for (int i = 0; i < 8; i++)
    {
        int _x = dx[i] + x;
        int _y = dy[i] + y;
        if (_x < 0 or _y < 0 or _x >= n or _y >= m or arr[_x][_y] == 0)
            continue;
        arr[_x][_y] = 0;
        numberOfIslands(arr, _x, _y, n, m);
    }
}
int getTotalIslands(int **arr, int n, int m)
{
    // Write your code here.
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {
                num++;
                numberOfIslands(arr, i, j, n, m);
            }
        }
    }
    return num;
}
