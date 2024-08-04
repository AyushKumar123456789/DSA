#include <bits/stdc++.h>
using namespace std;

#define ll long long

void preProcess(vector<vector<ll>> &ancestor, ll v)
{
    for (int j = 1; j <= 20; j++)
    {
        for (int i = 1; i <= v; i++)
        {
            if (ancestor[i][j - 1] != -1)
            {
                ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
            }
        }
    }
}

ll query(vector<vector<ll>> &ancestor, ll v, ll x, ll k)
{
    if (k == 0)
    {
        return x;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (k >= (1 << i))
        {
            x = ancestor[x][i];
            if (x == -1)
            {
                return x;
            }
            k -= (1 << i);
        }
    }
    return x;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> parent(n + 1, vector<ll>(21, -1));
    for (ll i = 2; i <= n; i++)
    {
        ll x;
        cin >> x;
        parent[i][0] = x;
    }

    preProcess(parent, n);

    while (q--)
    {
        ll x, k;
        cin >> x >> k;
        cout << query(parent, n, x, k) << endl;
    }
}