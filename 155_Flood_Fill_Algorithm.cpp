#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    // Write your code here.
    int oldColor = image[x][y];
    if (oldColor == newColor)
        return image;
    int n = image.size(), m = image[0].size();
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {-1, 1, 0, 0};
    queue<pair<int, int>> q;
    q.push({x, y});
    image[x][y] = newColor;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int _x = it.first + dx[i];
            int _y = it.second + dy[i];
            if (_x < 0 or _x >= n or _y < 0 or _y >= m or image[_x][_y] != oldColor)
                continue;
            image[_x][_y] = newColor;
            q.push({_x, _y});
        }
    }
    return image;
}