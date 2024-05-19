// https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

/*
USE DFS IF NEED TO FIND PATH VECTOR and This Is a good question
*/

#include <bits/stdc++.h>
using namespace std;

bool check(int a, int b, int n, vector<vector<int>> &m)
{
    if (a < n && a >= 0 && b < n && b >= 0 && m[a][b] == 1)
    {
        return 1;
    }
    return 0;
}

void dfs(int idx1, int idx2, vector<vector<int>> &m, string &curr_path, vector<string> &path, int n, vector<vector<int>> &vis)
{
    if (check(idx1, idx2, n, m) && idx1 == n - 1 && idx2 == n - 1)
    {
        path.push_back(curr_path);
        return;
    }

    vis[idx1][idx2] = 1; // Isko Agar Upar Likh denge Code k starting m to End point P Ek bar hing Jp payga
    if (check(idx1 + 1, idx2, n, m) && !vis[idx1 + 1][idx2])
    {
        curr_path += "D";
        dfs(idx1 + 1, idx2, m, curr_path, path, n, vis);
        curr_path.pop_back();
    }

    if (check(idx1, idx2 + 1, n, m) && !vis[idx1][idx2 + 1])
    {
        curr_path += "R";
        dfs(idx1, idx2 + 1, m, curr_path, path, n, vis);
        curr_path.pop_back();
    }
    if (check(idx1, idx2 - 1, n, m) && !vis[idx1][idx2 - 1])
    {
        curr_path += "L";
        dfs(idx1, idx2 - 1, m, curr_path, path, n, vis);
        curr_path.pop_back();
    }
    if (check(idx1 - 1, idx2, n, m) && !vis[idx1 - 1][idx2])
    {
        curr_path += "U";
        dfs(idx1 - 1, idx2, m, curr_path, path, n, vis);
        curr_path.pop_back();
    }
    vis[idx1][idx2] = 0;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> path;
    string curr_path = "";
    vector<vector<int>> vis(n, vector<int>(n, 0));
    if (m[0][0] == 0)
    {
        return path;
    }
    dfs(0, 0, m, curr_path, path, n, vis);
    return path;
}