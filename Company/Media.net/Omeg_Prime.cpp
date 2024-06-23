// https://www.thejoboverflow.com/problem/202/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long

const int mod = 1e9 + 7;
map<int, int> val;
vector<int> primes;
vector<vector<int>> dp(31, vector<int>((1ll << 10), -1));

int solve(int num, int mask)
{
    if (num == 31)
        return mask != 0;
    int newMask = mask;
    bool flag = 1;
    if (dp[num][mask] != -1)
    {
        return dp[num][mask];
    }
    for (int i = 0; i < 10; i++)
    {
        int x = primes[i];
        if (num % x != 0)
            continue;
        if (x > num)
            break;
        if ((mask & (1LL << i)) != 0)
        {
            flag = 0;
            break;
        }
        (newMask |= (1LL << i));
    }
    int pick = 0;
    if (flag)
    {
        pick = (val[num] % mod * solve(num + 1, newMask) % mod) % mod;
    }
    int not_pick = solve(num + 1, mask) % mod;
    return dp[num][mask] = ((pick % mod) + (not_pick % mod)) % mod;
}

int32_t main()
{
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    primes.push_back(11);
    primes.push_back(13);
    primes.push_back(17);
    primes.push_back(19);
    primes.push_back(23);
    primes.push_back(29);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] % 4 == 0 || a[i] % 9 == 0 || a[i] % 16 == 0 || a[i] % 25 == 0)
        {
            continue;
        }
        val[a[i]]++;
    }
    int x = 1;
    for (int i = 1; i <= val[1]; i++)
    {
        x *= 2;
        x %= mod;
    }
    cout << ((x % mod * solve(2, 0) % mod) % mod) << endl;
    return 0;
}