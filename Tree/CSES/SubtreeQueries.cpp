#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

vector<ll> eulerTour;
vector<pair<ll, ll>> entry_exit(N, {0ll, 0ll});
vector<ll> seg(4 * N, 0ll);
ll timer = 0ll;

void dfs(vector<vector<ll>> &graph, ll node, ll pr)
{
    entry_exit[node].first = timer++;
    eulerTour.push_back(node);
    for (auto ch : graph[node])
    {
        if (ch != pr)
        {
            dfs(graph, ch, node);
        }
    }
    eulerTour.push_back(node);
    entry_exit[node].second = timer++;
}

void segment(ll low, ll high, ll pos, map<ll, ll> &val)
{
    if (high == low)
    {
        seg[pos] = val[eulerTour[low]];
    }
    else
    {
        ll mid = (low + high) / 2;
        segment(low, mid, 2 * pos, val);
        segment(mid + 1, high, 2 * pos + 1, val);
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}

ll query(ll node, ll start, ll end, ll l, ll r)
{
    if (r < start || end < l)
    {
        return 0;
    }
    if (l <= start && end <= r)
    {
        return seg[node];
    }
    ll mid = (start + end) / 2;
    ll p1 = query(2 * node, start, mid, l, r);
    ll p2 = query(2 * node + 1, mid + 1, end, l, r);
    return (p1 + p2);
}

void update(ll pos, ll low, ll high, ll idx, ll val)
{
    if (low == high)
    {
        seg[pos] = val;
    }
    else
    {
        ll mid = (low + high) / 2;
        if (low <= idx && idx <= mid)
        {
            update(2 * pos, low, mid, idx, val);
        }
        else
        {
            update(2 * pos + 1, mid + 1, high, idx, val);
        }
        seg[pos] = seg[2 * pos] + seg[2 * pos + 1];
    }
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> graph(n + 1);
    map<ll, ll> val;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        val[i] = x;
    }
    for (int i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(graph, 1, 0);
    segment(0, eulerTour.size() - 1, 1, val);

    while (q--)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll s, x;
            cin >> s >> x;
            ll e = entry_exit[s].first;
            ll f = entry_exit[s].second;
            update(1, 0, eulerTour.size() - 1, e, x);
            update(1, 0, eulerTour.size() - 1, f, x);
        }
        else
        {
            ll s;
            cin >> s;
            ll e = entry_exit[s].first;
            ll f = entry_exit[s].second;
            ll ans = query(1, 0, eulerTour.size() - 1, e, f);
            cout << (ans / 2ll) << endl;
        }
    }
    return 0;
}
