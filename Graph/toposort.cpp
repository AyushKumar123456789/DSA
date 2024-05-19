
#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto ch : adj[i])
        {
            indegree[ch]++;
        }
    }
    queue<int> Q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    vector<int> topo;
    while (!Q.empty())
    {
        int node = Q.front();
        topo.push_back(node);
        Q.pop();
        for (auto ch : adj[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
            {
                Q.push(ch);
            }
        }
    }
    return topo;
}