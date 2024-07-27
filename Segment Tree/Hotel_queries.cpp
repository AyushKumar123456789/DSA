// https://cses.fi/problemset/task/1143

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

vector<ll> seg(4 * N, 0);

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
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
}

ll query(ll idx, ll l, ll h, ll val)
{
    if (l == h)
    {
        if (seg[idx] >= val)
        {
            seg[idx] -= val;
            return l + 1;
        }
        return 0;
    }
    ll mid = (l + h) / 2;
    ll temp = 0;
    if (seg[idx] >= val)
    {
        if (seg[2 * idx + 1] >= val && seg[2 * idx + 2] >= val)
        {
            temp = query(2 * idx + 1, l, mid, val);
        }
        else if (seg[2 * idx + 1] >= val)
        {
            temp = query(2 * idx + 1, l, mid, val);
        }
        else if (seg[2 * idx + 2] >= val)
        {
            temp = query(2 * idx + 2, mid + 1, h, val);
        }
        else
        {
            return 0;
        }
    }
    seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    return temp;
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
        ll x;
        cin >> x;
        cout << query(0, 0, n - 1, x) << endl;
    }
}