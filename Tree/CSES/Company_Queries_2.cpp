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
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }

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
    return parent[a][0];
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 2; i <= n; i++)
    {
        ll a;
        cin >> a;
        graph[a].push_back(i);
        graph[i].push_back(a);
    }
    dfs(graph, 1, -1);
    preprocess(n);
    while (q--)
    {
        ll a, b;
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
    return 0;
}
