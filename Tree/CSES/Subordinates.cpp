#include <bits/stdc++.h>
using namespace std;

#define ll long long

void dfs(vector<vector<ll>> &graph, ll node, vector<ll> &ans)
{
    for (auto ch : graph[node])
    {

        dfs(graph, ch, ans);
        ans[node] += (ans[ch] + 1);
    }
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n - 1);
    for (ll &x : arr)
        cin >> x;
    vector<vector<ll>> graph(n + 1);
    for (ll i = 0; i < n - 1; i++)
    {
        graph[arr[i]].push_back(i + 2); // reversing the graph
    }
    vector<ll> ans(n + 1, 0);

    dfs(graph, 1, ans);

    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}
