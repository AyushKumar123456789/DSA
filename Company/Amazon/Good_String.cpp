#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pi pair<ll, ll>

void update(ll idx, char ch, ll n, vector<vector<ll>> &fmwick, ll val)
{
    while (idx <= n)
    {
        fmwick[idx][ch - 'a'] += val;
        idx += (idx & (-idx));
    }
}

ll find(ll idx, char ch, vector<vector<ll>> &fmwick)
{
    ll sum = 0;
    while (idx >= 1)
    {
        sum += fmwick[idx][ch - 'a'];
        idx -= (idx & (-idx));
    }
    return sum;
}

bool check(vector<pi> &query, vector<vector<ll>> &fmwick)
{
    for (auto &q : query)
    {
        ll a = q.first;
        ll b = q.second;

        for (ll j = 0; j < 26; j++)
        {
            char temp = 'a' + j;
            if ((find(a, temp, fmwick) - find(b - 1, temp, fmwick)) > 1)
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    ll n, q;
    cin >> n >> q;
    string str;
    cin >> str;
    vector<ll> arr(n);
    for (ll &x : arr)
    {
        cin >> x;
    }
    vector<pi> query(q);
    for (auto &x : query)
    {
        cin >> x.first >> x.second;
    }

    vector<vector<ll>> fmwick(n + 1, vector<ll>(26, 0));

    for (ll i = 0; i < n; i++)
    {
        update(i + 1, str[i], n, fmwick, 1);
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        if (check(query, fmwick))
        {
            break;
        }
        char temp = 'A' + i;
        update(arr[i], str[arr[i] - 1], n, fmwick, -1);
        str[arr[i] - 1] = temp;
        ans++;
    }
    cout << ans << endl;
}
