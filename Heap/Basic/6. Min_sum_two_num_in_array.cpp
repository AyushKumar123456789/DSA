// https://www.geeksforgeeks.org/problems/minimum-sum4058/1

#include <bits/stdc++.h>
using namespace std;

/*
Further optimized to O(N) becuase in array only one digit nuber exists so it can be sorted in O(N)
*/

string solve(int arr[], int n)
{
    vector<int> pq;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        pq.push_back(arr[i]);
    }
    int carry = 0;
    string ans = "";
    while (pq.size() != 0)
    {
        int sum = 0;
        sum += (carry + pq.back());
        pq.pop_back();
        if (pq.size() > 0)
        {
            sum += pq.back();
            pq.pop_back();
        }
        ans.push_back('0' + (sum % 10));
        carry = sum / 10;
    }

    if (carry > 0)
    {
        ans.push_back('0' + carry);
    }

    while (ans.back() == '0' && ans.size() > 1)
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}
