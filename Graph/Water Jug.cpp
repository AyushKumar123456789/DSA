/*
BFS ALGO
*/

#include <bits/stdc++.h>
using namespace std;

int ninjaAndVessels(int m, int n, int w)
{
    map<pair<int, int>, int> vis;
    queue<pair<pair<int, int>, int>> Q;
    Q.push({{0, 0}, 0});
    vis[{0, 0}] = 1;

    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();

        auto node = temp.first;
        int steps = temp.second;

        if (node.first == w || node.second == w)
        {
            return steps;
        }

        // Jug1 -> full
        if (vis[{m, node.second}] != 1)
        {
            Q.push({{m, node.second}, steps + 1});
            vis[{m, node.second}] = 1;
        }

        // Jug2 -> full
        if (vis[{node.first, n}] != 1)
        {
            Q.push({{node.first, n}, steps + 1});
            vis[{node.first, n}] = 1;
        }

        // Jug1 -> jug2 transfer
        int left2 = n - node.second;
        if (node.first > left2)
        {
            if (vis[{node.first - left2, n}] != 1)
            {
                Q.push({{node.first - left2, n}, steps + 1});
                vis[{node.first - left2, n}] = 1;
            }
        }
        else
        {
            if (vis[{0, node.first + node.second}] != 1)
            {
                Q.push({{0, node.first + node.second}, steps + 1});
                vis[{0, node.first + node.second}] = 1;
            }
        }

        // Jug2 -> Jug1 transfer
        int left1 = m - node.first;
        if (node.second > left1)
        {
            if (vis[{m, node.second - left1}] != 1)
            {
                Q.push({{m, node.second - left1}, steps + 1});
                vis[{m, node.second - left1}] = 1;
            }
        }
        else
        {
            if (vis[{node.first + node.second, 0}] != 1)
            {
                Q.push({{node.first + node.second, 0}, steps + 1});
                vis[{node.first + node.second, 0}] = 1;
            }
        }

        // Jug1 -> empty
        if (vis[{0, node.second}] != 1)
        {
            Q.push({{0, node.second}, steps + 1});
            vis[{0, node.second}] = 1;
        }

        // Jug2 -> empty
        if (vis[{node.first, 0}] != 1)
        {
            Q.push({{node.first, 0}, steps + 1});
            vis[{node.first, 0}] = 1;
        }
    }

    return -1;
}
