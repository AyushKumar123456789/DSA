// https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

/*
Easy peasy lemone squeezy

dp[i][j] = Minimum number of scalar multiplications needed to compute the matrix from i to j (j-i)->total matrices

Run loop on size of matrices in the chain (len -> 2 to N)

*/

#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int matrixMultiplication(int N, int arr[])
{
    memset(dp, 1000000, sizeof(dp));

    for (int i = 0; i < N - 1; i++)
        dp[i][i + 1] = 0;

    for (int len = 2; len < N; len++)
    {
        for (int i = 0; i < N - len; i++)
        {
            int j = i + len;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j]);
            }
        }
    }

    return dp[0][N - 1];
}

int main()
{
    int arr[] = {40, 20, 30, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << matrixMultiplication(n, arr) << endl;
    return 0;
}

// Time Complexity: O(N^3)
// Auxiliary Space: O(N^2)
// Company Tags: Amazon, Microsoft, Snapdeal
