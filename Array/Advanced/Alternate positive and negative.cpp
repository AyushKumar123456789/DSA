// https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

#include <bits/stdc++.h>
using namespace std;

/*
GooD Question
*/

/*
Approach 1: O(n) time and O(n) space
Approach 2: O(n^2) time and O(1) space
*/

// Approach 1

void rearrange(int arr[], int n)
{
    vector<int> pos, neg;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
            pos.push_back(arr[i]);
        else
            neg.push_back(arr[i]);
    }
    int i = 0, j = 0, k = 0;
    while (i < pos.size() && j < neg.size())
    {
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }
    while (i < pos.size())
        arr[k++] = pos[i++];
    while (j < neg.size())
        arr[k++] = neg[j++];
}

// Approach 2

/*
LOGIC :
1. If the current element is negative and the index is even, then we need to find the next positive element and right rotate the array by one
2. If the current element is positive and the index is odd, then we need to find the next negative element and right rotate the array by one

Time Complexity: O(n^2)
Space Complexity: O(1)
*/

void rearrange(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (arr[i] < 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] >= 0)
                    {
                        int temp = arr[j];
                        for (int k = j; k > i; k--)
                        {
                            arr[k] = arr[k - 1];
                        }
                        arr[i] = temp;
                        break;
                    }
                }
            }
        }
        else
        {
            if (arr[i] >= 0)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[j] < 0)
                    {
                        int temp = arr[j];
                        for (int k = j; k > i; k--)
                        {
                            arr[k] = arr[k - 1];
                        }
                        arr[i] = temp;
                        break;
                    }
                }
            }
        }
    }
}