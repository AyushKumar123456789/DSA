// https://leetcode.com/problems/minimum-window-substring/description/

// Amazon

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        vector<int> freq(128, -1);
        for (int i = 0; i < m; i++)
        {
            if (freq[t[i]] == -1)
            {
                freq[t[i]] = 0;
            }
            freq[t[i]]++;
        }
        int cnt = m;
        int start = 0, end = 0;
        int minLen = INT_MAX;
        int a = -1, b = -1;
        while (end < n)
        {
            if (freq[s[end]] > 0)
            {
                freq[s[end]]--;
                end++;
                cnt--;
            }
            else
            {
                freq[s[end]]--;
                end++;
            }
            while (cnt == 0)
            {
                if (end - start + 1 < minLen)
                {
                    a = start;
                    b = end;
                    minLen = b - a + 1;
                }

                if (freq[s[start]] == 0)
                {
                    freq[s[start]]++;
                    cnt++;
                    start++;
                }
                else
                {
                    freq[s[start]]++;
                    start++;
                }
            }
        }
        return minLen == INT_MAX ? "" : s.substr(a, minLen - 1);
    }
};