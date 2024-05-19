// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

/*
Basic Concept to make a connected Graph of n vertices use n-1 edges
*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> graph[], vector<int> &vis)
{
    vis[i] = 1;
    for (auto ch : graph[i])
    {
        if (!vis[ch])
        {
            dfs(ch, graph, vis);
        }
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> vis(n, 0);
    int cnt = 0;

    vector<int> graph[n];
    for (int i = 0; i < connections.size(); i++)
    {
        graph[connections[i][0]].push_back(connections[i][1]);
        graph[connections[i][1]].push_back(connections[i][0]);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(i, graph, vis);
        }
    }
    int e = connections.size();

    if (e >= n - 1)
    {
        return cnt - 1;
    }
    return -1;
}