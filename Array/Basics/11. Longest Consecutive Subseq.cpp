// https://www.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

/*
Time Complexity : O(R) , R is max number
Space Complexity : O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++)
    {
        freq[arr[i]]++;
    }
    int maxi = *max_element(arr, arr + N);
    int cnt = 1;
    int ans = 0;
    for (int i = maxi - 1; i >= 0; i--)
    {
        if (freq[i] > 0 && freq[i + 1] > 0)
        {
            cnt++;
        }
        else
        {
            ans = max(ans, cnt);
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    return ans;
}

/*
Time Complexity : O(N)
Space Complexity : O(1)

Logic :
1. Run a for loop on every element of array and check if this element can become the last element of consecutive values this can be done by checking if(freq[arr[i]+1])==0.
2. Then run backward from it and find the max length of consecutive elements.
*/

int findLongestConseqSubseq(int arr[], int N)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < N; i++)
    {
        freq[arr[i]]++;
    }
    int maxi = *max_element(arr, arr + N);
    int cnt = 0;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        if (freq[arr[i] + 1] == 0)
        {
            int temp = arr[i];
            while (freq[temp] > 0)
            {
                cnt++;
                temp--;
            }
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    return ans;
}