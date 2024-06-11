// https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1

/*
GOOD QUESTION : Add k upto index i and decrese K from index i+1 to n-1
LOGIC : https://www.geeksforgeeks.org/minimize-the-maximum-difference-between-the-heights/
*/

#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    for (int i = 0; i < n - 1; i++)
    {
        int maxi = max(arr[i] + k, arr[n - 1] - k);
        int mini = min(arr[0] + k, arr[i + 1] - k);
        if (maxi < 0 || mini < 0)
        {

            continue;
        }
        ans = min(ans, maxi - mini);
    }
    return ans;
}