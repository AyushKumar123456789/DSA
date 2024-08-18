// https://leetcode.com/problems/longest-palindromic-substring

#include <bits/stdc++.h>
using namespace std;

/*
Easily solved without using DP in O(n^2) time complexity & O(1) space complexity.
*/

string longestPalindrome(string s)
{
    int n = s.size();
    int st = 0, ed = 0;

    // Check for palindromes centered around each character
    for (int i = 0; i < n; i++)
    {
        // Odd-length palindromes
        int a = i, b = i;
        while (a >= 0 && b < n && s[a] == s[b])
        {
            if (b - a > ed - st)
            {
                st = a;
                ed = b;
            }
            a--;
            b++;
        }

        // Even-length palindromes
        a = i;
        b = i + 1;
        while (a >= 0 && b < n && s[a] == s[b])
        {
            if (b - a > ed - st)
            {
                st = a;
                ed = b;
            }
            a--;
            b++;
        }
    }

    return s.substr(st, ed - st + 1);
}