// https://leetcode.com/problems/word-break/

/*
Easy Peasy Lemon Squeezy
dp[i] will represent if string upto i is present in dictionary or not starting from any index j.
*/

#include <bits/stdc++.h>
using namespace std;

bool wordBreak(string s, vector<string> &wordDict)
{
    int n = wordDict.size();
    unordered_map<string, int> exist;
    for (int i = 0; i < n; i++)
    {
        exist[wordDict[i]] = 1;
    }
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    // dp[i] string upto i is exist in dictionary
    for (int i = 1; i <= s.size(); i++)
    {
        string temp = "";
        for (int j = i; j >= 1; j--)
        {
            temp = s[j - 1] + temp;

            if (exist[temp])
            {
                dp[i] = (dp[i] || dp[j - 1]);
            }
        }
    }
    return dp[s.size()];
}

int main()
{
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    cout << wordBreak(s, wordDict) << endl;
    return 0;
}
