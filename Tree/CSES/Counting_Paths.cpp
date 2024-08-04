// https://cses.fi/problemset/task/1136

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

vector<ll> val(N, 0ll);
vector<vector<ll>> parent(N, vector<ll>(21, -1));
vector<ll> depth(N, 0);

void dfs(ll node, vector<vector<ll>> &graph, ll par)
{
    for (auto ch : graph[node])
    {
        if (par != ch)
        {
            depth[ch] = depth[node] + 1;
            parent[ch][0] = node;
            dfs(ch, graph, node);
        }
    }
}

void preProcess(ll n)
{
    for (int i = 1; i < 21; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (parent[j][i - 1] != -1)
            {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
        }
    }
}

ll LCA(ll a, ll b)
{
    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    ll diff = depth[a] - depth[b];
    for (int i = 20; i >= 0; i--)
    {
        if (diff >= (1ll << i))
        {
            a = parent[a][i];
            diff -= (1ll << i);
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

void dfs_ans(ll node, vector<vector<ll>> &graph, ll par)
{
    ll x = val[node];
    for (auto ch : graph[node])
    {
        if (ch != par)
        {
            dfs_ans(ch, graph, node);
            x += val[ch];
        }
    }
    val[node] = x;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, graph, 0);
    preProcess(n);
    while (m--)
    {
        ll a, b;
        cin >> a >> b;
        val[a]++;
        val[b]++;
        ll temp = LCA(a, b);
        // cout << "LCA of " << a << " " << b << " " << temp << endl;
        val[temp]--;
        if (parent[temp][0] != -1)
        {
            val[parent[temp][0]]--;
        }
    }
    dfs_ans(1, graph, 0);
    for (ll i = 1; i <= n; i++)
    {
        cout << val[i] << " ";
    }
    cout << endl;
}