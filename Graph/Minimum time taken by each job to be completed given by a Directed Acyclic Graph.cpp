// https://www.geeksforgeeks.org/problems/minimum-time-taken-by-each-job-to-be-completed-given-by-a-directed-acyclic-graph/1

#include <bits/stdc++.h>
using namespace std;

// Similar to Topological Sort and previous prerequisites problem

vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
{
    vector<int> ans(n);
    vector<int> graph[n + 1];
    vector<int> indegree(n + 1, 0);
    queue<int> Q;
    for (int i = 0; i < m; i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    int cnt = 0;
    int time = 0;
    int nodes = 0;
    while (!Q.empty())
    {
        int node = Q.front();
        if (cnt == 0)
        {
            time++;
            cnt = Q.size();
        }
        Q.pop();
        cnt--;
        ans[node - 1] = time;
        nodes++;
        for (auto ch : graph[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
            {
                Q.push(ch);
            }
        }
    }

    return ans;
}