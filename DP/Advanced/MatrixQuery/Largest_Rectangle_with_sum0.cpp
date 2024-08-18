// https://www.geeksforgeeks.org/problems/largest-rectangular-sub-matrix-whose-sum-is-0/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
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

    void printMatrix(vector<vector<int>> a)
    {
        for (auto i : a)
        {
            for (auto j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void test()
    {
        /*
        9, 7, 16, 5
          1,-6,-7, 3
          1, 8, 7, 9
          7, -2, 0, 10
        */
        vector<vector<int>> a = {{9, 7, 16, 5},
                                 {1, -6, -7, 3},
                                 {1, 8, 7, 9},
                                 {7, -2, 0, 10}};

        vector<vector<int>> ans = sumZeroMatrix(a);
        printMatrix(ans);
    }
};

int main()
{
    Solution s;
    s.test();
    return 0;
}