// https://leetcode.com/problems/reorganize-string/submissions/1365424584/

#include <bits/stdc++.h>
using namespace std;

string reorganizeString(string s)
{
    vector<int> freq(26, 0);

    for (char c : s)
    {
        freq[c - 'a']++;
    }

    vector<pair<int, char>> frq;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
        {
            frq.push_back({freq[i], i + 'a'});
        }
    }

    sort(frq.rbegin(), frq.rend());

    if (frq[0].first > (s.size() + 1) / 2)
    {
        return "";
    }

    string ans(s.size(), ' ');
    int idx = 0;

    for (auto &[count, ch] : frq)
    {
        while (count > 0 && idx < s.size())
        {
            ans[idx] = ch;
            idx += 2;
            count--;
        }
        if (idx >= s.size())
        {
            idx = 1;
        }
        while (count > 0)
        {
            ans[idx] = ch;
            idx += 2;
            count--;
        }
    }

    return ans;
}

int main()
{
    string s = "aab";
    cout << reorganizeString(s) << endl;
    return 0;
}