// https://www.geeksforgeeks.org/problems/minimum-number-of-jumps-1587115620/1

/*
No DP is needed , we can solve this problem using greedy approach.
Time Complexity : O(n)
Space Complexity : O(1)
*/

/*
Things to take care is of some edge cases
1st Edge Case : if there is only stone which is starting aswell as end stone return 0.
2nd initialisation of ans = 1, because if starting and ending stone are not same then there is one jump from 0 to 1-range becuas
the for loop starts from prev+1 to range
*/

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{
    int range = arr[0];
    int prev = 1;
    int ans = 1;
    if (n == 1)
        return 0;
    while (range < n - 1)
    {
        if (prev > range)
        {
            return -1;
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
    return ans;
}