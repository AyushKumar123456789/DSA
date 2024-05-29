// https://atcoder.jp/contests/abc355/tasks/abc355_d

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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // start
    ll n;
    cin >> n;
    vector<pi> arr(n);
    FOR(i, n)
    {
        cin >> arr[i].fi;
        cin >> arr[i].se;
    }
    vec_sort(arr);
    vi strt(n);
    FOR(i, n)
    {
        strt[i] = arr[i].fi;
    }
    ll ans = 0;
    FOR(i, n)
    {
        ll temp = arr[i].se;
        ll idx = upper_bound(all(strt), temp) - strt.begin();
        ans += (idx - i - 1);
    }
    cout << ans << endl;
    // END
}