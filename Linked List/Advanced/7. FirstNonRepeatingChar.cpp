// https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*
Problem:
Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
B is formed such that we have to find first non-repeating character each time a character is inserted to the stream and append it at the end to B.
If no non-repeating character is found then append '#' at the end of B.

Approach:
1. Create a vector of size 26 and initialize it with 0.
2. Create a deque to store the characters.
3. Traverse the string and increment the count of the character in the vector.
4. If the count of the character is greater than 1, then pop the front element of the deque.
5. If the count of the character is less than or equal to 1, then push the character in the deque.
6. If the deque is empty, then append '#' to the answer string.
7. Else append the front element of the deque to the answer string.
8. Return the answer string.


*/

#include <bits/stdc++.h>
using namespace std;

string FirstNonRepeating(string A)
{
    string ans = "";
    vector<int> check(26, 0);
    deque<char> dq;
    for (int i = 0; i < A.size(); i++)
    {
        check[A[i] - 'a']++;
        while (!dq.empty() && check[dq.front() - 'a'] > 1)
        {
            dq.pop_front();
        }
        if (check[A[i] - 'a'] <= 1)
        {
            dq.push_back(A[i]);
        }
        if (dq.empty())
        {
            ans += ('#');
        }
        else
        {
            ans += (dq.front());
        }
    }
    return ans;
}

int main()
{
    string A = "aabbcc";
    cout << FirstNonRepeating(A) << endl;
    return 0;
}