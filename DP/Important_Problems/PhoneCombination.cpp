// https: // leetcode.com/problems/letter-combinations-of-a-phone-number/

/*
Easy Problem
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void f(vector<string> &mp, vector<string> &ans, string &temp, string &digits, int idx)
    {
        if (idx == digits.size())
        {
            if (temp.size() > 0)
            {
                ans.push_back(temp);
            }
            return;
        }
        int dig = digits[idx] - '0';
        for (int i = 0; i < mp[dig].size(); i++)
        {
            temp += (mp[dig][i]);
            f(mp, ans, temp, digits, idx + 1);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits)
    {
        vector<string> mp(10);
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        vector<string> ans;
        string temp = "";
        f(mp, ans, temp, digits, 0);
        return ans;
    }
};