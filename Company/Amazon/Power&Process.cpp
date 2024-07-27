#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<ll> power(n);
    set<ll> st;
    for (auto &x : power)
    {
        cin >> x;
        st.insert(x);
    }
    ll m;
    cin >> m;
    vector<pair<ll, ll>> processor(m);
    for (ll i = 0; i < m; i++)
    {
        cin >> processor[i].first;
        st.insert(processor[i].first);
    }
    for (ll i = 0; i < m; i++)
    {
        cin >> processor[i].second;
        st.insert(processor[i].second);
    }
    unordered_map<ll, ll> mp;
    int idx = 0;
    for (auto it : st)
    {
        mp[it] = idx++;
    }
    vector<ll> mp_power(idx + 1, 0);
    vector<ll> mp_power_cnt(idx + 1, 0);
    for (auto it : power)
    {
        mp_power[mp[it]] += it;
        mp_power_cnt[mp[it]] += 1;
    }
    vector<ll> mp_power_prefix(idx + 100, 0);
    vector<ll> mp_power_prefix_cnt(idx + 100, 0);
    for (ll i = 1; i <= mp_power.size(); i++)
    {
        mp_power_prefix[i] = mp_power_prefix[i - 1] + mp_power[i - 1];
        mp_power_prefix_cnt[i] = mp_power_prefix_cnt[i - 1] + mp_power_cnt[i - 1];
    }
    for (auto it : processor)
    {
        ll total_pwr = mp_power_prefix[mp[it.second] + 1] - mp_power_prefix[mp[it.first]];
        ll total_cnt = mp_power_prefix_cnt[mp[it.second] + 1] - mp_power_prefix_cnt[mp[it.first]];
        cout << total_cnt << " " << total_pwr << endl;
    }
}