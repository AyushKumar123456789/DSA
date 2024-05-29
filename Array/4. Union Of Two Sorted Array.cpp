/*
1. Approach : Use Set TIME COMPLEXITY : (O(M+N)log(M+N)) & Space O(M+N)
2. Approach : Use array TIME COMPLEXITY :  (O(M+N)) & Space O(M+N)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> freq;
    vector<int> ans;
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        while (arr2[idx] <= arr1[i] && idx < m)
        {
            freq[arr2[idx]]++;
            if (freq[arr2[idx]] == 1)
            {
                ans.push_back(arr2[idx]);
            }
            idx++;
        }

        freq[arr1[i]]++;
        if (freq[arr1[i]] == 1)
        {
            ans.push_back(arr1[i]);
        }
    }

    while (idx < m)
    {
        freq[arr2[idx]]++;
        if (freq[arr2[idx]] == 1)
        {
            ans.push_back(arr2[idx]);
        }
        idx++;
    }
    return ans;
}