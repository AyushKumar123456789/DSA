#include <bits/stdc++.h>
using namespace std;

/*
Use Kadane's Algorithm to find the maximum sum subarray in a 1D array.
Then, use this to find the maximum sum rectangle in a 2D array by fixing the left and right columns and running Kadane's Algorithm on the rows.
*/

int maximumSumRectangle(int R, int C, vector<vector<int>> M)
{
    vector<vector<int>> prefix(R + 1, vector<int>(C + 1, 0));
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            prefix[i][j] = prefix[i][j - 1] + M[i - 1][j - 1];
        }
    }
    int ans = -100000;
    for (int c1 = 1; c1 <= C; c1++)
    {
        for (int c2 = c1; c2 <= C; c2++)
        {
            int sum = 0;
            for (int r = 1; r <= R; r++)
            {
                sum += (prefix[r][c2] - prefix[r][c1 - 1]);
                ans = max(ans, sum);
                if (sum < 0)
                {
                    sum = 0;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int R = 4, C = 5;
    vector<vector<int>> M = {{1, 2, -1, -4, -20},
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};
    cout << maximumSumRectangle(R, C, M) << "\n"; // 29
    return 0;
}
