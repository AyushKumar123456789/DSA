// https://www.geeksforgeeks.org/maximum-sum-such-that-no-two-elements-are-adjacent/

/*
1. GO with 2D DP approach
*/

// C++ code to implement the approach

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum sum
int findMaxSum(vector<int> arr, int N)
{
    // Declare dp array
    int dp[N][2];
    if (N == 1)
    {
        return arr[0];
    }

    // Initialize the values in dp array
    dp[0][0] = 0;
    dp[0][1] = arr[0];

    // Loop to find the maximum possible sum
    for (int i = 1; i < N; i++)
    {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][1],
                       dp[i - 1][0]);
    }

    // Return the maximum sum
    return max(dp[N - 1][0], dp[N - 1][1]);
}

// Driver Code
int main()
{
    // Creating the array
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int N = arr.size();

    // Function call
    cout << findMaxSum(arr, N) << endl;
    return 0;
}

/*
Reduce Space Complexity to O(1)
*/

// C++ code to implement the above approach

#include <bits/stdc++.h>
using namespace std;

// Function to return max sum such that
// no two elements are adjacent
int FindMaxSum(vector<int> arr, int n)
{
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        // Current max excluding i
        excl_new = max(incl, excl);

        // Current max including i
        incl = excl + arr[i];
        excl = excl_new;
    }

    // Return max of incl and excl
    return max(incl, excl);
}

// Driver code
int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int N = arr.size();

    // Function call
    cout << FindMaxSum(arr, N);
    return 0;
}
