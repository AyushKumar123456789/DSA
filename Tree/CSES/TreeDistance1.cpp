/*
Logic :
Find the max distance node from the stastring node dist1 and then find the max distance node from dist1
which is dist2 node, then this two nodes are the end of diameter .

Now, find the max distance of every nodes from dist1 and dist2 node , one of them give the max answer
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(ll node, ll parent, vector<ll> &dist, vector<vector<ll>> &graph)
{
    for (auto ch : graph[node])
    {
        if (ch != parent)
        {
            dist[ch] = dist[node] + 1;
            dfs(ch, node, dist, graph);
        }
    }
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<ll>> graph(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Since it's an undirected tree
    }
    // find the max distance node from 1
    vector<ll> dist(n + 1, 0);
    dfs(1, 0, dist, graph);

    ll dist1 = 0;
    ll maxi = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (maxi < dist[i])
        {
            maxi = dist[i];
            dist1 = i;
        }
    }
    dist.clear();
    dist.resize(n + 1, 0);
    dfs(dist1, 0, dist, graph); // dist store the max distance from dist1 to all node
    ll dist2 = 0;
    maxi = 0;
    for (ll i = 1; i <= n; i++)
    {
        if (maxi < dist[i])
        {
            maxi = dist[i];
            dist2 = i;
        }
    }

    vector<ll> dist2_dist(n + 1, 0);
    dfs(dist2, 0, dist2_dist, graph); // dist2_dist stores the max distance of all node from dist2
    // now find the max distance from dist1 and dist2 of all node
    for (ll i = 1; i <= n; i++)
    {
        cout << max(dist[i], dist2_dist[i]) << " ";
    }
    cout << endl;
}
