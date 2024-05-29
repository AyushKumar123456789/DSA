// https://www.geeksforgeeks.org/problems/kadanes-algorithm-1587115620/1

/*
Easy Problem : Kadan's Algorithm
*/

#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{

    long long sum = 0, max_sum = -10000000;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        max_sum = max(max_sum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_sum;
}
