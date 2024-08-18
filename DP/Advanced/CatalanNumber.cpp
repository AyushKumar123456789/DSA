// https://www.geeksforgeeks.org/problems/geek-and-his-binary-strings1951/1

/*

Given an integer N, the task is to find the number of binary strings of size 2*N such that
each string has exactly N 1's and each prefix of the string
has more than or an equal number of 1's than 0's.

Example 1:

Input: N = 2
Output: 2 {1100, 1010}


Approach:
The number of binary strings of size 2*N such that each string has exactly N 1's is (2*N)! / ((N+1)! * N!).
Which is Catalan Number.

Catalan Number = (2*N)! / ((N+1)! * N!)

Importance of Catalan Number:
1. Number of ways to form a binary tree with N+1 nodes.
2. Number of ways to form a polygon with N+2 sides.
3. Number of ways to form a valid parenthesis with N pairs of parenthesis.
4. Number of ways to form a mountain range with N peaks.
5. Number of ways to form a Dyck word of length 2*N.



*/

#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = (res * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// a^-1 = a^(mod-2) % mod
long long MI(long long a, long long mod)
{
    return binpow(a, mod - 2, mod);
}

int prefixStrings(int N)
{
    long long mod = 1000000007;
    long long ans = 1;

    // Calculate (N+1) * (N+2) * ... * (2*N)
    for (int i = N + 1; i <= 2 * N; i++)
    {
        ans = (ans * i) % mod;
    }

    // Calculate the modular inverse for (2 * (N+1)) * ... * (N+1)
    for (int i = 2; i <= N + 1; i++)
    {
        ans = (ans * MI(i, mod)) % mod;
    }

    return ans;
}