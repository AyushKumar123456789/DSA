#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll binpow(ll a, ll b, ll m)
{
    a %= m;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll a, ll m)
{
    return binpow(a, m - 2, m);
}

ll nCr(ll n, ll r, ll m)
{
    if (r > n)
        return 0;
    if (r == 0)
        return 1;
    ll res = 1;
    for (ll i = 1; i <= r; i++)
    {
        res = (res * (n - i + 1)) % m;
        res = (res * modInverse(i, m)) % m;
    }
    return res;
}

int main()
{
    ll n, r, m;
    cin >> n >> r >> m;
    cout << nCr(n, r, m) << endl;
    return 0;
}