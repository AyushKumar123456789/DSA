#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> retailer(n, vector<ll>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> retailer[i][j];
        }
    }
    ll m;
    cin >> m;
    vector<vector<ll>> request(m, vector<ll>(2));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> request[i][j];
        }
    }

    map<ll, vector<ll>> pos_y;
    for (int i = 0; i < n; i++)
    {
        pos_y[retailer[i][1]].push_back(retailer[i][0]);
    }
    for (auto it : pos_y)
    {
        sort(it.second.begin(), it.second.end());
    }
    vector<ll> ans(m, 0);
    for (int i = 0; i < request.size(); i++)
    {
        int req_x = request[i][0];
        int req_y = request[i][1];
        for (auto it : pos_y)
        {
            if (it.first >= req_y)
            {
                int after_req_x = it.second.end() - lower_bound(it.second.begin(), it.second.end(), req_x);
                ans[i] += after_req_x;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << endl;
    }
}