/*
You are given n services numbered from 1 to n in a system, and there are m requests to be processed. Each request is
cached in one of the services, indicated by the array cache[]. If a request is processed by the service in which it is cached,
 it takes 1 unit of time; otherwise, it takes 2 units of time. Different services can process different requests simultaneously,
 but each service can only process one request at a time. You need to find the minimum time required to process all the requests.

The example given is:

n = 3
m = 5
cache = [1, 1, 3, 1, 1]
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, n) for (ll i = 0; i < ll(n); i++)
#define FORb(i, n) for (ll i = n; i >= 0; i--)
#define vi vector<ll>
#define pb push_back
#define print_array(array, length)  \
    for (ll i = 0; i < length; i++) \
        cout << (array[i]) << " ";
typedef long double ld;
typedef pair<ll, ll> pi;
const long long mod = 1e9 + 7;
const long long Mod = 998244353;
const long long inf = 1e18;
#define all(x) x.begin(), x.end()
#define MP make_pair
#define REP(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define el cout << endl;
#define sz(x) (ll)(x).size()
#define vec_sort(a) sort(a.begin(), a.end())
#define vec_rev(a) reverse(a.begin(), a.end())
#define vec_sort_r(a) sort(a.begin(), a.end(), comp)
#define setbits(x) __builtin_popcountll(x) // count number of setbits in a number
#define pi pair<ll, ll>
#define fi first
#define se second
#define ft front
#define all(x) x.begin(), x.end()
#define yess cout << "YES" << endl;
#define noo cout << "NO" << endl;

bool check(vi &freq, ll n, ll mid)
{
    ll task = 0;
    ll i = 0;
    if (freq[0] <= mid)
        return 1;
    for (; i < n; i++)
    {
        if (freq[i] > mid)
        {
            task += (freq[i] - mid);
        }
        else
        {
            break;
        }
    }
    task *= 2;
    for (; i < n; i++)
    {
        ll temp = mid - freq[i];
        task -= temp;
    }
    return task <= 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // start
    ll n, m;
    cin >> n >> m;
    vi cache(m);
    FOR(i, m)
    cin >> cache[i];
    vi freq(n, 0);
    FOR(i, m)
    {
        freq[cache[i] - 1]++;
    }
    vec_sort(freq);
    vec_rev(freq);
    ll l = 1, r = 1e5;
    ll ans;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        // cout << mid << endl;
        if (check(freq, n, mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    // END
}