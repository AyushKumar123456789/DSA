// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
using namespace std;

// l,r->range to increase value with val

#define ll long long
#define N 200001ll

vector<ll> lazy(4 * N, 0);
vector<ll> seg(4 * N, 0);

void rangeUpdate(ll idx, ll l, ll h, ll arr_l, ll arr_h, ll val)
{
    if (lazy[idx] != 0)
    {
        seg[idx] += (h - l + 1) * lazy[idx];

        if (l != h)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    if (arr_l > h || arr_h < l || l > h)
    {
        return;
    }

    if (arr_l <= l && arr_h >= h)
    {
        seg[idx] += (h - l + 1) * val;
        if (l != h)
        {
            lazy[2 * idx + 1] += val;
            lazy[2 * idx + 2] += val;
        }
        return;
    }

    ll mid = (l + h) / 2;
    rangeUpdate(2 * idx + 1, l, mid, arr_l, arr_h, val);
    rangeUpdate(2 * idx + 2, mid + 1, h, arr_l, arr_h, val);
}

void build(ll idx, ll l, ll h, vector<ll> &arr)
{
    if (l == h)
    {
        seg[idx] = arr[l];
        return;
    }
    ll mid = (l + h) / 2;
    build(2 * idx + 1, l, mid, arr);
    build(2 * idx + 2, mid + 1, h, arr);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll rangeSum(ll idx, ll l, ll h, ll arr_l, ll arr_h)
{
    if (lazy[idx] != 0)
    {
        seg[idx] += (h - l + 1) * lazy[idx];
        if (l != h)
        {
            lazy[2 * idx + 1] += lazy[idx];
            lazy[2 * idx + 2] += lazy[idx];
        }
        lazy[idx] = 0;
    }
    if (arr_l > h || arr_h < l || l > h)
    {
        return 0;
    }

    if (arr_l <= l && arr_h >= h)
    {
        return seg[idx];
    }
    ll mid = (l + h) / 2;
    return rangeSum(2 * idx + 1, l, mid, arr_l, arr_h) + rangeSum(2 * idx + 2, mid + 1, h, arr_l, arr_h);
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    build(0, 0, n - 1, arr);

    for (ll i = 0; i < q; i++)
    {
        ll a;
        cin >> a;
        if (a == 1)
        {
            ll x, y, z;
            cin >> x >> y >> z;
            rangeUpdate(0, 0, n - 1, x - 1, y - 1, z);
        }
        else
        {
            ll x;
            cin >> x;
            cout << rangeSum(0, 0, n - 1, x - 1, x - 1) << endl;
        }
    }
}