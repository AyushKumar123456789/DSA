// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &p1, pair<int, int> &p2)
{
    if (p1.second < p2.second)
    {
        return 1;
    }
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }
    return 0;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first;
        cin >> arr[i].second;
    }
    sort(arr.begin(), arr.end(), comp);
    int ans = 0;
    int end = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first > end)
        {
            end = arr[i].second;
            ans++;
        }
    }
    cout << ans << endl;
}