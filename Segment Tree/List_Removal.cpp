// https://cses.fi/problemset/task/1749

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

vector<ll> seg(4 * N + 1, 0ll);
vector<ll> val(4 * N + 1, 0ll);

void build(ll idx, ll l, ll h, vector<ll> &arr)
{
    if (l == h)
    {
        val[idx] = arr[l];
        seg[idx] = 1;
        return;
    }
    ll mid = (l + h) / 2;
    build(2 * idx + 1, l, mid, arr);
    build(2 * idx + 2, mid + 1, h, arr);
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
}

ll query(ll idx, ll l, ll h, ll idx_val)
{
    // cout << "f(" << idx << " " << l << " " << h << " " << " " << idx_val << ")" << endl;
    if (l == h)
    {
        seg[idx] = 0;
        return val[idx];
    }
    ll mid = (l + h) / 2;
    ll temp;
    if (idx_val <= seg[2 * idx + 1])
    {
        temp = query(2 * idx + 1, l, mid, idx_val);
    }
    else
    {
        temp = query(2 * idx + 2, mid + 1, h, idx_val - seg[2 * idx + 1]);
    }
    seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    return temp;
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    build(0, 0, n - 1, arr);
    for (ll i = 0; i < n; i++)
    {
        ll temp;
        cin >> temp;
        // cout << "search : " << temp << endl;
        cout << query(0, 0, n - 1, temp) << endl;
    }
}
