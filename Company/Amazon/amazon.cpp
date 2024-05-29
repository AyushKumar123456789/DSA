#include <bits/stdc++.h>
using namespace std;

#define ll long long

void update(ll idx, char ch, ll n, vector<vector<ll>> &fmwick, ll val)
{
    while (idx <= n)
    {
        fmwick[idx][ch - 'a'] += val;
        idx += (idx & (-idx));
    }
}

ll find(ll idx, char ch, ll n, vector<vector<ll>> &fmwick)
{
    ll sum = 0;
    while (idx >= 1)
    {
        sum += fmwick[idx][ch - 'a'];
        idx -= (idx & (-idx));
    }
    return sum;
}

int main()
{
    string str;
    cin >> str;
    ll n = str.size();
    vector<vector<ll>> fmwick(n + 1, vector<ll>(26, 0));

    for (ll i = 0; i < n; i++)
    {
        update(i + 1, str[i], n, fmwick, 1);
        // cout << str[i] << " : " << fmwick[i + 1][str[i] - 'a'] << endl;
    }

    ll q;
    cin >> q;
    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a == 1)
        {
            ll ans = 0;
            for (ll i = 0; i < 26; i++)
            {
                ans ^= (find(c, 'a' + i, n, fmwick) - find(b - 1, 'a' + i, n, fmwick));
            }
            cout << ans << endl;
        }
        else
        {
            char temp = 'a' + c - 1;
            // cout << str[b - 1] << " : " << fmwick[b][str[b - 1] - 'a'] << endl;
            // cout << (temp) << " : " << fmwick[b][temp - 'a'] << endl;
            update(b, str[b - 1], n, fmwick, -1);
            update(b, temp, n, fmwick, 1);
            // cout << str[b - 1] << " : " << fmwick[b][str[b - 1] - 'a'] << endl;
            // cout << (temp) << " : " << fmwick[b][temp - 'a'] << endl;
        }
    }
}