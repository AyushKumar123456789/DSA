#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n, q;
    cin >> n >> q;
    vector<vector<ll>> pre(n + 1, vector<ll>(n + 1, 0));
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '*')
            {
                pre[i][j] = pre[i - 1][j] + 1;
            }
            else
            {
                pre[i][j] += pre[i - 1][j];
            }
        }
    }

    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= n; j++)
        {
            pre[i][j] += pre[i][j - 1];
        }
    }

    for (ll i = 0; i < q; i++)
    {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        ll ans = pre[y2][x2] - pre[y1 - 1][x2] - pre[y2][x1 - 1] + pre[y1 - 1][x1 - 1];
        cout << ans << endl;
    }
}