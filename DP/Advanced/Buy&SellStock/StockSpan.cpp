// https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

/*
Good Question

Question is same to stack next greater element but on the left side.

At index i , stack will contain the elements which are smaller then arr[i] and are on the left side of arr[i].
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    vector<int> ans(n, 1);
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (st.empty())
        {
            ans[i] = 1;
            st.push(i);
        }
        else
        {
            while (!st.empty() && price[st.top()] <= price[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = i + 1;
            }
            else
            {
                ans[i] = i - st.top();
            }
            st.push(i);
        }
    }
    return ans;
}

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(price) / sizeof(price[0]);
    vector<int> ans = calculateSpan(price, n);
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)

// Test case:
// Input: price[] = {100, 80, 60, 70, 60, 75, 85}
// Output: 1 1 1 2 1 4 6
