// https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
This Problem use concept of next smaller , it is the first index whose element is less than this element.

So For this create a stack which store the indexes of elements is increasing order and from bottom to top, and whenever find
the bigger element keep removing elements form stack until the element in stack is smaller than the currect element.

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> right_smaller(n);
    stack<int> nxt_smaller;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!nxt_smaller.empty() && arr[nxt_smaller.top()] >= arr[i])
        {
            nxt_smaller.pop();
        }
        right_smaller[i] = (nxt_smaller.empty() ? n : nxt_smaller.top());
        nxt_smaller.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << right_smaller[i] << " ";
    }
    cout << endl;
    stack<int> prev_smaller;
    vector<int> lft_smaller(n);
    for (int i = 0; i < n; i++)
    {
        while (!prev_smaller.empty() && arr[prev_smaller.top()] >= arr[i])
        {
            prev_smaller.pop();
        }
        lft_smaller[i] = (prev_smaller.empty() ? -1 : prev_smaller.top());
        prev_smaller.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << lft_smaller[i] << " ";
    }
    cout << endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, (right_smaller[i] - lft_smaller[i] - 1) * arr[i]);
    }
    cout << ans << endl;
}