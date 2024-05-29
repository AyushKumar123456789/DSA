// https://leetcode.com/problems/word-break-ii/description/?envType=daily-question&envId=2024-05-25

// Time Complexity: O(2^n)
// Space Complexity: O(2^n*n) catalan number of n=2^n

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(int idx, string s, unordered_map<string, int> &freq, string temp, string temp_str, vector<string> &ans)
    {
        if (idx == s.size())
        {
            if (freq[temp] == 1)
            {
                if (temp_str.size() == 0)
                {
                    temp_str += temp;
                }
                else
                {
                    temp_str += (" " + temp);
                }
                if (temp_str[temp_str.size() - 1] == ' ')
                {
                    temp_str.pop_back();
                }
                ans.push_back(temp_str);
                return;
            }
            else
            {
                return;
            }
        }

        temp += s[idx];
        if (freq[temp] == 1)
        {
            if (temp_str.size() == 0)
            {
                f(idx + 1, s, freq, "", temp_str + temp, ans);
            }
            else
            {
                f(idx + 1, s, freq, "", temp_str + " " + temp, ans);
            }
        }
        f(idx + 1, s, freq, temp, temp_str, ans);
    }

    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_map<string, int> freq;
        for (int i = 0; i < wordDict.size(); i++)
        {
            freq[wordDict[i]] = 1;
        }
        vector<string> ans;
        string temp = "";
        string temp_str = "";
        f(0, s, freq, temp, temp_str, ans);
        set<string> var(ans.begin(), ans.end());
        ans.clear();
        for (auto it : var)
        {
            ans.push_back(it);
        }
        return ans;
    }
};