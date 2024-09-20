// https://www.thejoboverflow.com/p/p2477/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 1000000ll);
    dp[1] = 1;
    dp[2] = 2;
    for (ll i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (ll j = 2; j * j <= i; j++)
        {
            if (i % j == 0)
            {
                dp[i] = min(dp[max(j, i / j)] + 1, dp[i]);
            }
        }
    }
    cout << dp[n] << endl;
}