// https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

/*
problem statement :  Given an undirected graph and an integer M. The task is to determine if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color. Here coloring of a graph means the assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.

Logic :
1. We will use backtracking to solve this problem.
2. We will start from the first node and check if we can color it with any color.
3. If we can color it with any color then we will move to the next node and if any eher further we are not able to color any node then we will backtrack and change the color of the previous node.
4. We will keep on doing this until we reach the last node and if we are able to color all the nodes then we will return 1 else 0.

Time complexity : O(M^N) where N is the number of nodes and M is the number of colors.
Why ? Becuase Every node has M choices to color and we have N nodes.
Space complexity : O(N) + O(N)  because we are using a color array of size N and stack space of size N (recursion stack space).

*/

#include <bits/stdc++.h>
using namespace std;

bool check(int node, bool graph[101][101], int n, int c, vector<int> &color)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[i][node] || graph[node][i])
        {
            if (c == color[i])
                return 0;
        }
    }
    return 1;
}

bool dfs(int node, bool graph[101][101], int m, int n, vector<int> &color)
{
    if (node == n)
    {
        return 1;
    }

    for (int i = 0; i < m; i++)
    {
        if (check(node, graph, n, i, color))
        {
            color[node] = i;
            if (dfs(node + 1, graph, m, n, color))
            {
                return 1;
            }
        }
    }

    return 0;
}

bool graphColoring(bool graph[101][101], int m, int n)
{
    vector<int> color(n, -1);
    bool check = 1;

    check = (1 && dfs(0, graph, m, n, color));

    return check;
}