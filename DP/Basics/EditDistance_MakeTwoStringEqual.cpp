
// https://www.geeksforgeeks.org/problems/edit-distance3702/1

#include <bits/stdc++.h>
using namespace std;

// Recursive Solution -> O(3^(max(s.size(),t.size()))) if no memoization is used

int f(string s, string t, int idx1, int idx2, vector<vector<int>> &dp)
{
    if (idx1 < 0 || idx2 < 0)
    {
        if (idx1 < 0)
        {
            return idx2 + 1;
        }
        else
        {
            return idx1 + 1;
        }
    }
    if (dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }
    int ans = 0;
    if (s[idx1] == t[idx2])
    {
        ans = f(s, t, idx1 - 1, idx2 - 1, dp);
    }
    else
    {
        ans = 1 + min(f(s, t, idx1 - 1, idx2, dp), min(f(s, t, idx1, idx2 - 1, dp), f(s, t, idx1 - 1, idx2 - 1, dp)));
    }
    return dp[idx1][idx2] = ans;
}

int editDistance(string s, string t)
{
    vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, -1));
    int ans = f(s, t, s.size() - 1, t.size() - 1, dp);
    return ans;
}

// Time Complexity: O(s.size()*t.size())
// Space Complexity: O(s.size()*t.size())->DP array size + O(max(s.size(),t.size())) for recursive stack

// Iterative Solution -> Bottom Up DP

// Here you have to think a little and remeber somethings
// 1. DP[i][j] represents the minimum number of operations required to convert s[0...i] to t[0...j]
// 2. Base case construction required two loops Because we need both dp[i-1][something] AND dp[something][j-1] to Calculate dp[i][j]
// 3. Base Case construction, DP[0][something] is how to convert s[0] = t[0...something] So, DP[0][j] = j + 1 until no letter of of t[0...j] matches with s[0] and when matches DP[0][j] = j Similary for DP[i][0]
// 4. Writing DP relation in loop ans = 1 + min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
//  Minimum of three choices:
//  1. Replace the character at S1[i-1] with S2[j-1]
//  2. Delete the character at S1[i-1]
//  3. Insert the character at S2[j-1] into S1
// Think of how to convert one string to another in differnt scenario
// 5. if(s[i]==t[j]) DP[i][j] = DP[i-1][j-1]; because no operation required

int editDistance(string s, string t)
{
    vector<vector<int>> dp(s.size(), vector<int>(t.size(), 0));
    bool check = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (s[0] == t[i] || check)
        {
            check = 1;
            dp[0][i] = i;
        }
        else
        {
            dp[0][i] = i + 1;
        }
    }
    check = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == t[0] || check)
        {
            check = 1;
            dp[i][0] = i;
        }
        else
        {
            dp[i][0] = i + 1;
        }
    }

    for (int i = 1; i < s.size(); i++)
    {
        for (int j = 1; j < t.size(); j++)
        {
            int ans = 0;
            if (s[i] == t[j])
            {
                ans = dp[i - 1][j - 1];
            }
            else
            {
                ans = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
            }
            dp[i][j] = ans;
        }
    }
    return dp[s.size() - 1][t.size() - 1];
}

// Time Complexity: O(s.size()*t.size())
// Space Complexity: O(s.size()*t.size())

// Some optimization can be done in space complexity by using 1D DP array instead of 2D DP array
// Space optimzation k lie dusre tarike se bnana hoga index shift krke

int editDistance(string s, string t)
{

    vector<int> prev(t.size() + 1, 0);
    vector<int> curr(t.size() + 1, 0);

    int n = s.size();
    int m = t.size();

    bool check = 0;

    for (int i = 0; i < m; i++)
    {
        if (s[0] == t[i] || check)
        {
            prev[i] = i;
            check = 1;
        }
        else
        {
            prev[i] = i + 1;
        }
    }
    check = 0;

    // if(s[0]==t[0] || check)
    // {
    //     check = 1;
    //     curr[0] = 0;
    // }

    for (int i = 1; i < n; i++)
    {
        if (s[i] == t[0] || check)
        {
            check = 1;
            curr[0] = i;
        }
        else
        {
            curr[0] = i + 1;
        }

        for (int j = 1; j < m; j++)
        {
            if (s[i] == t[j])
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
            }
        }
        prev = curr;
    }

    return prev[m - 1];
}