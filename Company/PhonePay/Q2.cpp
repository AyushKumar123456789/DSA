// https : // www.geeksforgeeks.org/get-k-th-letter-of-the-decoded-string-formed-by-repeating-substrings/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int total = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
        {
            total *= (s[i] - '0');
        }
        else
        {
            total++;
        }
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        k %= total;
        if (isdigit(s[i]))
        {
            total /= (s[i] - '0');
        }
        else
        {
            if (k == 0)
            {
                cout << s[i] << endl;
                break;
            }
            total--;
        }
    }
}