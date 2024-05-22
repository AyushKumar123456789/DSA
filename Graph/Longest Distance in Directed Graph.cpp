// https://www.naukri.com/code360/problems/longest-path-in-directed-graph_1172157?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

/*
First Go with Bellman Ford Algorithm with , if(dist[u]!=-1 && dist[v]<dist[u] +w) { dist[v] = dist[u] + w; }
And Relx every Edges N-1 times, because at most N-1 edges are there in the longest path.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n, -1);
    dist[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];

            if (dist[u] != -1 && dist[v] < dist[u] + w)
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    return dist;
}

// Time Complexity : O(N*E)
// Space Complexity : O(N+E)

/*

2nd Approach :

Use Dijkstra and convert the graph into a graph with negative weights.

1. Create a new graph with negative weights.
2. Run Dijkstra on the new graph.
*/

vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges)
{
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        graph[u].push_back({v, -wt});
    }
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto p = pq.top();
        pq.pop();
        int node = p.second;
        int wt = p.first;
        for (auto ch : graph[node])
        {
            if (dist[ch.first] > dist[node] + ch.second)
            {
                dist[ch.first] = dist[node] + ch.second;
                pq.push({dist[ch.first], ch.first});
            }
        }
    }
    return dist;
}

// Time Complexity : O((N+E)logN)
// Space Complexity : O(N+E)

// Optimized Approach : Topological Sort + Relaxation

/*
Steps :

1. Create a Toposort of the graph and stores it in an Vector.
2. Initialize the distance of source node to 0 and all other nodes to INT_MAX.
3. Run a loop of toposort and relax all the edges of the node , if dist[u] + wt < dist[v] then dist[v] = dist[u] + wt.
*/

void dfs(vector<pair<int, int>> graph[], int node, vector<int> &vis, vector<int> &topo)
{
    vis[node] = 1;
    for (auto ch : graph[node])
    {
        if (vis[ch.first] == 0)
        {
            dfs(graph, ch.first, vis, topo);
        }
    }
    topo.push_back(node);
}

vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges)
{
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        graph[u].push_back({v, wt});
    }
    vector<int> topo;
    vector<int> vis(n, 0);
    dfs(graph, src, vis, topo);
    reverse(topo.begin(), topo.end());
    vector<int> dist(n, -1);
    dist[src] = 0;

    for (int i = 0; i < topo.size(); i++)
    {
        int node = topo[i];
        for (auto ch : graph[node])
        {
            if (dist[ch.first] < dist[node] + ch.second)
            {
                dist[ch.first] = dist[node] + ch.second;
            }
        }
    }
    return dist;
}

// Time Complexity : O(N+E)
// Space Complexity : O(N)
