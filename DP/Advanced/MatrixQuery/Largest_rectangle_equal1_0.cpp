// https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/

/*
Not Getting Right Answer
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> max_area_rectangle(vector<vector<int>> &mat, int row, int col)
{
    vector<vector<int>> prefix_row(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            prefix_row[j][i + 1] = prefix_row[j][i] + (mat[j][i] ? 1 : -1);
        }
    }

    int r1 = 0, r2 = 0, c1 = 0, c2 = 0;

    for (int i = 0; i < col; i++)
    {
        for (int j = i; j < col; j++)
        {
            int sum = 0;
            map<int, int> row_sum;
            row_sum[0] = 0;

            for (int k = 0; k < row; k++)
            {
                sum += (prefix_row[k + 1][j + 1] - prefix_row[k + 1][i]);

                if (row_sum.find(sum) == row_sum.end())
                {
                    row_sum[sum] = k + 1;
                }
                else
                {
                    int new_area = (k - row_sum[sum] + 1) * (j - i + 1);
                    int curr_area = (r2 - r1 + 1) * (c2 - c1 + 1);

                    if (new_area > curr_area)
                    {
                        r1 = row_sum[sum];
                        r2 = k;
                        c1 = i;
                        c2 = j;
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(r2 - r1 + 1, vector<int>(c2 - c1 + 1));
    for (int i = r1; i <= r2; i++)
    {
        for (int j = c1; j <= c2; j++)
        {
            ans[i - r1][j - c1] = mat[i][j];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 1, 1},
                               {0, 1, 1, 0},
                               {1, 1, 1, 0},
                               {1, 0, 0, 1}};

    int row = mat.size();
    int col = mat[0].size();

    vector<vector<int>> ans = max_area_rectangle(mat, row, col);

    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}