
// https://www.geeksforgeeks.org/rearrange-characters-string-no-two-adjacent/

#include <bits/stdc++.h>
using namespace std;

/*
Greedy Approach is optimal
*/

string reorganizeString(string s)
{
    int n = s.size();
    string ans(n, ' '); // Initialize ans with n spaces
    vector<int> freq(26, 0);

    // Fill frequency array
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }

    // Find the character with the maximum frequency
    int max_freq = 0;
    char max_char;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > max_freq)
        {
            max_freq = freq[i];
            max_char = 'a' + i;
        }
    }

    // If the most frequent character is more than half the length of the string, it's impossible to reorganize
    if (max_freq > (n + 1) / 2)
    {
        return "";
    }

    // Place the most frequent character at even indexes
    int idx = 0;
    while (freq[max_char - 'a'] > 0)
    {
        ans[idx] = max_char;
        idx += 2;
        freq[max_char - 'a']--;
    }

    // Place remaining characters
    for (int i = 0; i < 26; i++)
    {
        while (freq[i] > 0)
        {
            // If we reach the end of even indexes, start placing at odd indexes
            if (idx >= n)
                idx = 1;
            ans[idx] = 'a' + i;
            idx += 2;
            freq[i]--;
        }
    }

    return ans;
}

int main()
{
}