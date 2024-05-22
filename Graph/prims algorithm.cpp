// https://www.naukri.com/code360/problems/prim-s-mst_1095633?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker

#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < m; i++)
    {
        graph[g[i].first.first].push_back({g[i].first.second, g[i].second});
        graph[g[i].first.second].push_back({g[i].first.first, g[i].second});
    }
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> Q;
    Q.push({{0, 1}, -1});
    vector<pair<pair<int, int>, int>> ans;
    vector<int> vis(n + 1, 0);
    while (!Q.empty())
    {
        auto it = Q.top();
        Q.pop();
        int node = it.first.second;
        int paren = it.second;
        int wt = it.first.first;
        if (vis[node] == 1)
            continue;
        if (paren != -1)
        {
            ans.push_back({{node, paren}, wt});
        }
        vis[node] = 1;
        //    cout<<"node : "<<node<<" paren : "<<paren<<" wt : "<<wt<<endl;
        for (auto ch : graph[node])
        {
            int adjNode = ch.first;
            //    cout<<"adjNode : "<<adjNode<<endl;
            if (vis[adjNode] == 0)
            {
                Q.push({{ch.second, adjNode}, node});
            }
        }
    }
    return ans;
}