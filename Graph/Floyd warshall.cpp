
/*
One Thing To remember if that K which is the intermediate node should be the outermost loop because we must calculate the distance between all the nodes before calculating the distance between the nodes through the intermediate node.
*/

#include <bits/stdc++.h>
using namespace std;

void shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][k] != -1 && matrix[k][j] != -1)
                {
                    if (matrix[i][j] == -1 || matrix[i][k] + matrix[k][j] < matrix[i][j])
                    {
                        matrix[i][j] = matrix[i][k] + matrix[k][j];
                    }
                }
            }
        }
    }
}

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)