// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

/*
No DP is needed , we can solve this problem using greedy approach.
Time Complexity : O(n)
Space Complexity : O(1)
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int range = arr[0];
    int prev = 1;
    int ans = 1;
    if (n == 1)
    {
        return 0;
    }
    while (1)
    {
        if (prev > range)
        {
            return -1;
        }
        else if (range >= n - 1)
        {
            return ans;
        }
        else
        {
            ans++;
            int temp = 0;
            for (int i = prev; i <= range; i++)
            {
                temp = max(temp, arr[i] + i);
            }
            prev = range + 1;
            range = temp;
        }
    }
    return -1;
}