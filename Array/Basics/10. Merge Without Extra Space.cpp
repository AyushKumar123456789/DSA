// https://www.geeksforgeeks.org/problems/merge-two-sorted-arrays-1587115620/1

/*
Time Complexity : O((N+M)(log(N+M)))
Space Complexity : O(1)

arr1 contain smaller elements
arr2 contain larger elements
*/

#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int right1 = n - 1;
    int left2 = 0;
    while (left2 < m && right1 >= 0)
    {
        if (arr2[left2] < arr1[right1])
        {
            swap(arr2[left2], arr1[right1]);
            left2++;
            right1--;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}