// https://codeforces.com/contest/1354/problem/D

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e6 + 5;
vector<ll> fenwick(N, 0);

void update(ll idx, ll val)
{
    ll n = 1000000 + 5;
    while (idx <= n)
    {
        fenwick[idx] += val;
        idx += (idx & -idx);
    }
}

ll sum(ll idx)
{
    ll sum = 0;
    while (idx > 0)
    {
        sum += fenwick[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        update(a[i], 1);
    }

    for (ll i = 0; i < q; i++)
    {
        ll temp;
        cin >> temp;
        if (temp > 0)
        {
            update(temp, 1);
        }
        else
        {
            temp = -temp;
            ll k_dig = 0;
            ll l = 0, r = N - 1;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if (sum(mid) >= temp)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            update(r, -1);
        }
    }

    ll ans = 0;

    for (ll i = 1; i <= n; i++)
    {
        if (fenwick[i] > 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}