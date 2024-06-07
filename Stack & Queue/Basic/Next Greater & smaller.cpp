
// https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1

// https://www.geeksforgeeks.org/problems/help-classmates--141631/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    vector<long long> ans(n);
    stack<long long> st;
    for (long long i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans[i] = -1;
            st.push(arr[i]);
        }
        else
        {
            if (arr[i] < st.top())
            {
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else
            {
                while (!st.empty() && arr[i] >= st.top())
                {
                    st.pop();
                }
                if (st.empty())
                {
                    ans[i] = -1;
                }
                else
                {
                    ans[i] = st.top();
                }
                st.push(arr[i]);
                ;
            }
        }
    }
    return ans;
}

vector<int> help_classmate(vector<int> arr, int n)
{
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans[i] = -1;
            st.push(arr[i]);
        }
        else
        {
            if (arr[i] > st.top())
            {
                ans[i] = st.top();
                st.push(arr[i]);
            }
            else
            {
                while (!st.empty() && arr[i] <= st.top())
                {
                    st.pop();
                }
                if (st.empty())
                {
                    ans[i] = -1;
                }
                else
                {
                    ans[i] = st.top();
                }
                st.push(arr[i]);
                ;
            }
        }
    }
    return ans;
}