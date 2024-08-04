/*
This question uses Tree ReRooting concept
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs0(ll node, ll par, vector<vector<ll>> &graph, vector<ll> &dp, vector<ll> &sz)
{
    dp[node] = 0;
    sz[node] = 1;
    for (auto child : graph[node])
    {
        if (child == par)
            continue;
        dfs0(child, node, graph, dp, sz);
        sz[node] += sz[child];
        dp[node] += dp[child] + sz[child];
    }
}

void reroot(ll from, ll to, vector<ll> &dp, vector<ll> &sz)
{
    // To is now not the child of from
    dp[from] -= (dp[to] + sz[to]);
    sz[from] -= sz[to];

    // from is now the child of to
    dp[to] += (dp[from] + sz[from]);
    sz[to] += sz[from];
}

void dfs1(ll node, ll par, vector<vector<ll>> &graph, vector<ll> &dp, vector<ll> &sz, vector<ll> &ans)
{
    ans[node] = dp[node];
    for (auto child : graph[node])
    {
        if (child == par)
            continue;
        reroot(node, child, dp, sz);
        dfs1(child, node, graph, dp, sz, ans);
        reroot(child, node, dp, sz);
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
        graph[b].push_back(a);
    }
    vector<ll> dp(n + 1, 0), sz(n + 1, 0), ans(n + 1, 0);
    dfs0(1, 0, graph, dp, sz);
    dfs1(1, 0, graph, dp, sz, ans);
    for (ll i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}