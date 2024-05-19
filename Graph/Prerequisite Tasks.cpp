#include <bits/stdc++.h>
using namespace std;

// Toposort possible if all the nodes are visited

bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
{
    vector<int> indegree(N, 0);
    vector<int> graph[N];
    for (int i = 0; i < P; i++)
    {
        indegree[prerequisites[i].first]++;
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
    }
    queue<int> Q;
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            Q.push(i);
        }
    }
    int cnt = 0;
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop();
        cnt++;
        for (auto ch : graph[node])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
            {
                Q.push(ch);
            }
        }
    }

    if (cnt < N)
    {
        return 0;
    }
    return 1;
}

// Expected Time Complexity: O(N + P)
//Expected Auxiliary Space : O(N + P)