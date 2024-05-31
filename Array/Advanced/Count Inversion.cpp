// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

long long merge(long long arr[], long long l, long long m, long long r)
{
    long long val = 0;
    long long n1 = m - l + 1;
    long long n2 = r - m;

    long long *left = new long long[n1];
    long long *right = new long long[n2];

    for (long long i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (long long i = 0; i < n2; i++)
        right[i] = arr[m + 1 + i];

    long long i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
        {
            arr[k] = left[i];
            i++;
        }
        else
        {
            arr[k] = right[j];
            j++;
            val += (n1 - i); // Count inversions
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }

    delete[] left;
    delete[] right;
    return val;
}

void mergeSort(long long arr[], long long l, long long r, long long &cnt)
{
    if (l < r)
    {
        long long mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, cnt);
        mergeSort(arr, mid + 1, r, cnt);
        cnt += merge(arr, l, mid, r);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    long long int ans = 0;
    mergeSort(arr, 0, N - 1, ans);
    return ans;
}