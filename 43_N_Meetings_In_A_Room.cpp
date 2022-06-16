#include <bits/stdc++.h>
using namespace std;

struct meeting
{
    int start, end, number;
};
static bool comp(meeting a, meeting b)
{
    if (a.end < b.end)
        return true;
    else if (a.end > b.end)
        return false;
    else if (a.number < b.number)
        return true;
    return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<meeting> meetings;
    int n = start.size();
    for (int i = 0; i < n; i++)
    {
        meeting m;
        m.start = start[i];
        m.end = end[i];
        m.number = i + 1;
        meetings.push_back(m);
    }
    sort(meetings.begin(), meetings.end(), comp);
    vector<int> ans;
    int endtime = -1;
    for (auto it : meetings)
    {
        if (it.start > endtime)
        {
            endtime = it.end;
            ans.push_back(it.number);
        }
    }
    return ans;
}