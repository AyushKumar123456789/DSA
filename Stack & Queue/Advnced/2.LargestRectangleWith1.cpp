// https://leetcode.com/problems/maximal-rectangle/description/

/*
Use histogram concept
*/
class Solution
{
public:
    int largestRectangleArea(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> right_smaller(n);
        stack<int> nxt_smaller;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!nxt_smaller.empty() && arr[nxt_smaller.top()] >= arr[i])
            {
                nxt_smaller.pop();
            }
            right_smaller[i] = (nxt_smaller.empty() ? n : nxt_smaller.top());
            nxt_smaller.push(i);
        }
        stack<int> prev_smaller;
        vector<int> lft_smaller(n);
        for (int i = 0; i < n; i++)
        {
            while (!prev_smaller.empty() && arr[prev_smaller.top()] >= arr[i])
            {
                prev_smaller.pop();
            }
            lft_smaller[i] = (prev_smaller.empty() ? -1 : prev_smaller.top());
            prev_smaller.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (right_smaller[i] - lft_smaller[i] - 1) * arr[i]);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int ans = 0;
        vector<int> histogram(matrix[0].size(), 0);
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (matrix[i][j] == '1')
                {
                    histogram[j]++;
                }
                else
                {
                    histogram[j] = 0;
                }
            }

            ans = max(ans, largestRectangleArea(histogram));
        }
        return ans;
    }
};