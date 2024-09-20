#include <bits/stdc++.h>
using namespace std;

bool check(int mid, vector<int> &arr, int k)
{
    int val = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        val += (arr[i] / mid);
    }
    return val >= k;
}

int f(vector<int> &arr, int k)
{
    int ans = 0;
    int n = arr.size();
    int l = 0;
    int h = *max_element(arr.begin(), arr.end());
    while (l < h)
    {
        int mid = (l + h) / 2;
        if (check(mid, arr, k))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &x : arr)
        cin >> x;
    int k;
    cin >> k;
    int ans = f(arr, k);
    cout << ans << endl;
}