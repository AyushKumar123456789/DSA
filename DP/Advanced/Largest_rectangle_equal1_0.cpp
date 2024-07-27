// https://www.geeksforgeeks.org/largest-area-rectangular-sub-matrix-equal-number-1s-0s/

#include <bits/stdc++.h>
using namespace std;

int max_area_rectangle(vector<vector<int>> &mat, int row, int col)
{
    vector<vector<int>> prefix_row(row + 1, vector<int>(col + 1, 0));
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            prefix_row[j][i + 1] = prefix_row[j][i] + (mat[j][i] ? 1 : 0);
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
        }
    }
}

int main()
{

    vector<vector<int>> mat = { {0, 0, 1, 1},
                                {0, 1, 1, 0},
                                {1, 1, 1, 0},
                                {1, 0, 0, 1} }

    int row = 4,
                        col = 4;
    cout << max_area_rectangle(mat, row, col) << endl;
}