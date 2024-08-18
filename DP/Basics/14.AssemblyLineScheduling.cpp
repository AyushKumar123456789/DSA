// https://www.geeksforgeeks.org/problems/assembly-line-scheduling/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

/*
Easy Peasy Lemon Squeezy

Problem Statement:
There are 2 assembly lines and n stations. A car chassis must pass through all stations in order before reaching the exit.
The time taken to pass through station i on line j is S[i][j], and the time taken to move from station i on line j to station i+1 on line j is T[i][j].
After it passes through station n, it will move to the exit.
Now, the car chassis can move in one of the two lines. Find the minimum time it will take to build a car chassis.

*/

int carAssembly(vector<vector<int>> &a, vector<vector<int>> &T, vector<int> &e, vector<int> &x)
{
    // dp[i][0] represent min time to reach ith index of row 1
    // dp[i][1] represent min time to reach ith index of row 2
    /*
    Transition:
    dp[i][0] = min(dp[i-1][1] + T[i][1] + a[i][0],dp[i-1][0] + a[i][0])
    dp[i][1] = min(dp[i-1][0] + T[i][0] + a[i][1],dp[i-1][1] + a[i][1])

    Base Case:
    dp[0][0] = a[0][0] + e[0];
    dp[1][0] = a[1][0] + e[1];

    */
    int n = a[0].size();
    vector<vector<int>> dp(2, vector<int>(n + 1, 0));
    dp[0][0] = a[0][0] + e[0];
    dp[1][0] = a[1][0] + e[1];
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = min(dp[1][i - 1] + T[1][i] + a[0][i], dp[0][i - 1] + a[0][i]);
        dp[1][i] = min(dp[0][i - 1] + T[0][i] + a[1][i], dp[1][i - 1] + a[1][i]);
        // cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    }
    return min(dp[1][n - 1] + x[1], dp[0][n - 1] + x[0]);
}

int main()
{
    vector<vector<int>> a = {{4, 5, 3, 2},
                             {2, 10, 1, 4}};
    vector<vector<int>> T = {{0, 7, 4, 5},
                             {0, 9, 2, 8}};
    vector<int> e = {10, 12};
    vector<int> x = {18, 7};
    cout << carAssembly(a, T, e, x) << endl;
    return 0;
}