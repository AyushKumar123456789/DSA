// https://www.naukri.com/code360/problems/number-of-triangles-in-directed-and-undirected-graphs_1214931?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

/*
GO To simpe approach :
1. Run three loops and check if there is a path from i to j, j to k and k to i.
2. If there is a path then increment the count of triangles.
3. For directed graph every triangle will be counted 3 times and for undirected graph every triangle will be counted 6 times.
4. So divide the final count by 3 for directed graph and by 6 for undirected graph.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> countTriangles(int v1, vector<vector<int>> &edgeListOfDirectedGraph, int v2,
                           vector<vector<int>> &edgeListOfUnDirectedGraph)
{
    vector<vector<int>> graph1(v1, vector<int>(v1, 0));
    vector<vector<int>> graph2(v2, vector<int>(v2, 0));
    for (int i = 0; i < edgeListOfDirectedGraph.size(); i++)
    {
        graph1[edgeListOfDirectedGraph[i][0]][edgeListOfDirectedGraph[i][1]] = 1;
    }
    for (int i = 0; i < edgeListOfUnDirectedGraph.size(); i++)
    {
        graph2[edgeListOfUnDirectedGraph[i][0]][edgeListOfUnDirectedGraph[i][1]] = 1;
        graph2[edgeListOfUnDirectedGraph[i][1]][edgeListOfUnDirectedGraph[i][0]] = 1;
    }
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < v1; i++)
    {
        for (int j = 0; j < v1; j++)
        {
            for (int k = 0; k < v1; k++)
            {
                if (graph1[i][j] && graph1[j][k] && graph1[k][i])
                {
                    ans1++;
                }
                if (graph2[i][j] && graph2[j][k] && graph2[k][i])
                {
                    ans2++;
                }
            }
        }
    }
    return {ans1 / 3, ans2 / 6};
}