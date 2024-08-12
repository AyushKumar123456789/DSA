#include <bits/stdc++.h>
using namespace std;

/*

Easy Peasy

Given a 2D matrix of integers, find the submatrix with the largest sum such that the sum of all elements is 0.

Approach:
1. We will use the concept of prefix sum.
2. We will calculate the prefix sum of each row from left to right.
3. Then we will iterate over all the columns fixing the left and right column of the submatrix and calculate the sum of the submatrix.

*/

vector<vector<int>> sumZeroMatrix(vector<vector<int>> a)
{
    int row = a.size();
    int col = a[0].size();

    vector<vector<int>> temp(row + 1, vector<int>(col + 1, 0));

    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            temp[i][j] = temp[i][j - 1] + a[i - 1][j - 1];
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
                sum += (temp[k + 1][j + 1] - temp[k + 1][i]);

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
            ans[i - r1][j - c1] = a[i][j];
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> a = {{1, 2, 3, 4},
                             {5, 6, 7, 8},
                             {9, 10, 11, 12},
                             {13, 14, 15, 16}};

    vector<vector<int>> ans = sumZeroMatrix(a);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}