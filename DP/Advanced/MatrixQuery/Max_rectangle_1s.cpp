/*
Little Tough Logic to visualize the problem. But once you get the logic, it is easy to implement.

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Approach:
1. For each row, calculate the maximum area of rectangle with the current row as the bottom row.
2. To do this, we need to calculate the left boundary, right boundary and height of each cell.
Left boundary of a cell is the leftmost cell with value 0 to the left of the current cell.
Right boundary of a cell is the rightmost cell with value 0 to the right of the current cell.
Height of a cell is the number of consecutive 1's above the current cell.


*/

#include <bits/stdc++.h>
using namespace std;

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
    {
        return 0;
    }

    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> left(n, 0);
    vector<int> right(n, n);
    vector<int> height(n, 0);
    int maxArea = 0;

    for (const auto &row : matrix)
    {
        int curLeft = 0, curRight = n;

        // Update height array
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '1')
            {
                height[j]++;
            }
            else
            {
                height[j] = 0;
            }
        }

        // Update left boundary array
        for (int j = 0; j < n; j++)
        {
            if (row[j] == '1')
            {
                left[j] = max(left[j], curLeft);
            }
            else
            {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

        // Update right boundary array
        for (int j = n - 1; j >= 0; j--)
        {
            if (row[j] == '1')
            {
                right[j] = min(right[j], curRight);
            }
            else
            {
                right[j] = n;
                curRight = j;
            }
        }

        // Calculate maximum area for each cell
        for (int j = 0; j < n; j++)
        {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }

    return maxArea;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};

    cout << maximalRectangle(matrix) << endl;

    return 0;
}