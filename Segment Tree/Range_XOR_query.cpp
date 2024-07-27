// https://cses.fi/problemset/task/1651

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define N 200001ll

class segmentTree
{
private:
    vector<ll> segment;

public:
    segmentTree()
    {
        segment.resize(4 * N + 1, 0ll);
    }
    void build(vector<ll> &arr, ll l, ll r, ll idx)
    {
        if (l == r)
        {
            segment[idx] = arr[l];
            return;
        }
        ll m = (l + r) / 2;
        build(arr, l, m, 2 * idx + 1);
        build(arr, m + 1, r, 2 * idx + 2);
        segment[idx] = segment[2 * idx + 1] ^ segment[2 * idx + 2];
    }

    ll query(ll idx, ll l, ll r, ll x, ll y)
    {
        if (x > r || y < l)
        {
            return 0;
        }
        if (x <= l && y >= r)
        {
            return segment[idx];
        }
        ll m = (l + r) / 2;
        return (query(2 * idx + 1, l, m, x, y) ^ query(2 * idx + 2, m + 1, r, x, y));
    }

    void update(ll idx, ll l, ll r, ll pos, ll val)
    {
        if (l == r)
        {
            segment[idx] = val;
        }
        ll m = (l + r) / 2;
        if (pos <= m)
        {
            update(2 * idx + 1, l, m, pos, val);
        }
        else
        {
            update(2 * idx + 2, m + 1, r, pos, val);
        }
        segment[idx] = (segment[2 * idx + 1] ^ segment[2 * idx + 2]);
    }
};

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for (auto &x : arr)
        cin >> x;
    segmentTree obj;
    obj.build(arr, 0, n - 1, 0);
    for (ll i = 0; i < q; i++)
    {
        ll b, c;
        cin >> b >> c;

        cout << obj.query(0, 0, n - 1, b - 1, c - 1) << endl;
    }
}