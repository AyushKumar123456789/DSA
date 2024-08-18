// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

/*
Activity Selection Problem , Concept
*/

#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

class Solution
{
public:
    int findLongestChain(vector<vector<int>> &pairs)
    {
        int n = pairs.size();
        vector<pair<int, int>> temp(n);
        for (int i = 0; i < n; i++)
        {
            temp[i].first = pairs[i][0];
            temp[i].second = pairs[i][1];
        }
        sort(temp.begin(), temp.end(), comp);
        for (int i = 0; i < n; i++)
        {
            cout << "(" << temp[i].first << " " << temp[i].second << ") ";
        }
        cout << endl;
        int ans = 0;
        int end = -10000;
        for (int i = 0; i < n; i++)
        {
            if (temp[i].first > end)
            {
                end = temp[i].second;
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> pairs = {{1, 2}, {2, 3}, {3, 4}};
    cout << s.findLongestChain(pairs) << endl;
    return 0;
}