#include <bits/stdc++.h>
using namespace std;

/*

Very Very Nice Problem. No other option than remembering the solution.

Problem :
Given n eggs and k floors, find the minimum number of trials needed in the worst case to find the critical floor in the worst case.


Approach:
dp[i][j] = minimum number of trials needed in the worst case with i eggs and j floors.

Transition:
Logic: We have 2 choices, either the egg breaks or it doesn't break.
If the egg breaks, we need to check all floors below the current floor
    -> So, dp[i][j] = 1 + dp[i - 1][x - 1] for x = 1 to j - 1  // i-1 because we have 1 less egg now and x-1 because we need to check all floors below the current floor.
If the egg doesn't break, we need to check all floors above the current floor.
    -> So, dp[i][j] = 1 + dp[i][j - x] for x = 1 to j - 1  // j-x because we need to check all floors above the current floor.

So, we need to take the maximum of these 2 cases because we need to consider the worst case.

dp[i][j] = min(1 + max(dp[i - 1][x - 1], dp[i][j - x])) for x = 1 to j (checking all floors from 1 to j)


Base Cases:
dp[1][j] = j because with 1 egg we need to check all floors from 1 to j // and so we start from down and in worst case the critical floor is the top floor
dp[i][1] = 1 because with 1 floor we need only 1 trial

Time Complexity: O(n*k^2)
Space Complexity: O(n*k)


*/

int eggDrop(int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i == 1)
            {
                dp[i][j] = j;
            }
            else if (j == 1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int ans = INT_MAX;
                for (int x = 1; x <= j; x++)
                {
                    ans = min(ans, 1 + max(dp[i - 1][x - 1], dp[i][j - x]));
                }
                dp[i][j] = ans;
            }
        }
    }
    return dp[n][k];
}