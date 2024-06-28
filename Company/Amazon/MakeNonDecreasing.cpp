/*
Given an array add value to any subbarray  such that the array becomes non-decreasing. Find the minimum sum of that values that needs to be added.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int add = 0;
        int ans = 0;
        for (int i = 1; i < a.size(); i++)
        {
            if (a[i] < a[i - 1])
            {
                int val = a[i - 1] - a[i];
                if (add >= val)
                {
                    a[i] += add;
                }
                else
                {
                    a[i] += (val - add);
                    ans += (val - add);
                    add = val - add;
                }
            }
            else
            {
                add = 0;
            }
        }
        cout << ans << endl;
    }
}