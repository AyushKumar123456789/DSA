// https://cses.fi/problemset/task/2134

#include <bits/stdc++.h>
using namespace std;

#define ll long long
vector<ll> tree(10000000, 0);
vector<ll> start_time(500001);
vector<ll> end_time(500001);
vector<bool> visited(500001, 0);
vector<ll> path;

void build_tree(ll l, ll r, ll treenode, vector<ll> &values)
{
    if (l > r)
    {
        return;
    }
    if (l == r)
    {
        tree[treenode] = path[l];
        return;
    }
    ll mid = l + (r - l) / 2;
    build_tree(l, mid, 2 * treenode + 1, values);
    build_tree(mid + 1, r, 2 * treenode + 2, values);
    tree[treenode] = tree[2 * treenode + 1] + tree[2 * treenode + 2];
}

void update(ll l, ll r, ll ul, ll ur, ll treenode, ll val)
{
    if (ul > r || ur < l)
    {
        return;
    }
    if (l == r)
    {
        tree[treenode] = val;
        return;
    }
    ll mid = l + (r - l) / 2;
    update(l, mid, ul, ur, 2 * treenode + 1, val);
    update(mid + 1, r, ul, ur, 2 * treenode + 2, val);
    tree[treenode] = tree[2 * treenode + 1] + tree[2 * treenode + 2];
}

ll query(ll l, ll r, ll ql, ll qr, ll treenode)
{
    if (l > r)
    {
        return 0;
    }
    if (l > qr || r < ql)
    {
        return 0;
    }
    if (l >= ql && r <= qr)
    {
        return tree[treenode];
    }
    ll mid = l + (r - l) / 2;
    ll a = query(l, mid, ql, qr, 2 * treenode + 1);
    ll b = query(mid + 1, r, ql, qr, 2 * treenode + 2);
    return a + b;
}

void dfs(ll c, ll &count, vector<vector<ll>> &adj, vector<ll> &values)
{
    if (visited[c])
    {
        return;
    }
    visited[c] = true;
    path.push_back(values[c - 1]);
    start_time[c] = count;
    count++;
    for (int neigh : adj[c])
    {
        if (!visited[neigh])
        {
            dfs(neigh, count, adj, values);
        }
    }
    path.push_back(-values[c - 1]);
    end_time[c] = count;
    count++;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> values(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }
    vector<vector<ll>> adj(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ll count = 0;
    dfs(1, count, adj, values);
    ll m = path.size();
    build_tree(0, m - 1, 0, values);
    while (q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll b, c;
            cin >> b >> c;
            update(0, m - 1, start_time[b], start_time[b], 0, c);
            update(0, m - 1, end_time[b], end_time[b], 0, -c);
        }
        else
        {
            ll b;
            cin >> b;
            cout << query(0, m - 1, 0, start_time[b], 0) << endl;
        }
    }
    return 0;
}
