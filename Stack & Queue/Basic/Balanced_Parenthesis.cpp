// https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1

/*
question is easy just take care of edge cases, for example s=")}" then dont forget to check stack is empty or not before popping element from it
*/

#include <bits/stdc++.h>

usign namespace std;

bool ispar(string x)
{
    stack<char> st;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        if (x[i] == '[' || x[i] == '{' || x[i] == '(')
        {
            st.push(x[i]);
        }
        else if (!st.empty() && ((x[i] == ']' && st.top() == '[') || (x[i] == '}' && st.top() == '{') || (x[i] == ')' && st.top() == '(')))
        {

            st.pop();
        }
        else
        {
            return 0;
        }
    }
    if (st.empty())
    {
        return 1;
    }
    return 0;
}