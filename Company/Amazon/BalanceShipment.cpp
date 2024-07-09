/*
Problem Statement:

Amazon has multiple delivery centers for the distribution of its goods. In one such center, parcels are arranged in a sequence where the
𝑖
ith parcel has a weight of weight[i]. A shipment is constituted of a contiguous segment of parcels in this arrangement. For example, if the parcels are arranged with weights [3, 6, 3], a shipment can be formed from parcels with weights [3], [6], [3], [3, 6], [6, 3], [3, 6, 3], but not with weights [3, 3]. These shipments are to be loaded for delivery and must be balanced.

A shipment is said to be balanced if the weight of the last parcel of the shipment is not the maximum weight among all the weights in that shipment. For example, a shipment with weights [3, 9, 4, 7] is balanced since the last weight is 7, while the maximum weight in the shipment is 9. However, the shipment [4, 7, 2, 7] is not balanced because the last weight (7) is the maximum weight in that shipment.

Task:

Given the weights of
𝑛
n parcels placed in a sequence, find the maximum number of balanced shipments that can be formed such that each parcel belongs to exactly one shipment. Each shipment must consist of only a contiguous segment of parcels, and each shipment must be balanced. If there are no balanced shipments, return 0.

Example :
1 2 3 2 6 3

Ans: 1 2 3 2  & 6 3

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll solve()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (ll &x : arr)
        cin >> x;

    ll maxi = *max_element(arr.begin(), arr.end());
    if (maxi == arr[n - 1])
    {
        return 0;
    }
    maxi = arr[n - 1];
    ll ans = 0;
    for (ll i = n - 2; i >= 0; i--)
    {
        if (maxi < arr[i])
        {
            ans++;
            if (i - 1 >= 0)
            {
                maxi = arr[i - 1];
                // cout << "maxi : " << maxi << endl;
            }
        }
    }
    ll ans1 = 0;
    maxi = 0;
    vector<ll> temp;
    for (ll i = 0; i < n; i++)
    {
        maxi = max(arr[i], maxi);
        if (arr[i] != maxi)
        {
            temp.push_back(maxi);
            ans1++;
            maxi = 0;
        }
    }
    while (!temp.empty() && temp.back() < maxi)
    {
        temp.pop_back();
    }

    return (max(ans, (ll)temp.size()));
}

int main()
{
    cout << solve() << endl;
}