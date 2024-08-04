// https://cses.fi/problemset/result/10044441/

/*
Getting TLE dont know why
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

vector<ll> depth(N, 0);
vector<vector<ll>> parent(N, vector<ll>(21, -1));

void dfs(vector<vector<ll>> &graph, ll node, ll par)
{
    for (auto ch : graph[node])
    {
        if (ch != par)
        {
            depth[ch] = depth[node] + 1;
            parent[ch][0] = node;
            dfs(graph, ch, node);
        }
    }
}

void preprocess(ll n)
{
    for (int j = 1; j < 21; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

ll query(ll a, ll b)
{
    ll x = a;
    ll y = b;
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

    // ll ans = depth[x] + depth[y];
    ll val = depth[a] - depth[b];
    for (int j = 20; j >= 0; j--)
    {
        if (val >= (1ll << j))
        {
            a = parent[a][j];
            val -= (1ll << j);
        }
    }

    if (a == b)
    {

        return a;
    }

    for (int j = 20; j >= 0; j--)
    {
        if (parent[a][j] != parent[b][j])
        {
            a = parent[a][j];
            b = parent[b][j];
        }
    }
    // ans -= 2 * depth[parent[a][0]];
    return parent[a][0];
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph, 1, 0);
    preprocess(n);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << depth[a] + depth[b] - 2 * depth[query(a, b)] << " ";
    }
    return 0;
}
