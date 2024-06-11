// https://www.geeksforgeeks.org/problems/common-elements1132/1

#include <bits/stdc++.h>
using namespace std;

/*
Easy Logic
Time Complexity: O(n1 + n2 + n3)
Space Complexity: O(1)
*/

vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
{
    int i = 0, j = 0, k = 0;
    vector<int> ans;
    while (i < n1 && j < n2 && k < n3)
    {
        if (A[i] < B[j] || A[i] < C[k])
        {
            i++;
        }
        else if (B[j] < A[i] || B[j] < C[k])
        {
            j++;
        }
        else if (C[k] < A[i] || C[k] < B[j])
        {
            k++;
        }
        else if (A[i] == B[j] && A[i] == C[k])
        {
            if (ans.size() != 0)
            {
                if (ans.back() != A[i])
                {
                    ans.push_back(A[i]);
                }
            }
            else
            {
                ans.push_back(A[i]);
            }
            i++;
            j++;
            k++;
        }
    }
    return ans;
}