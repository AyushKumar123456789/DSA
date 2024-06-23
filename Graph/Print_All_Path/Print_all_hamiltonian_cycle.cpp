#include <bits/stdc++.h>

using namespace std;

void dfsHamiltonianCycle(int node, int start, vector<vector<int>> &graph, vector<int> &vis, vector<int> &temp, vector<vector<int>> &ans, int n)
{
    vis[node] = 1;
    temp.push_back(node);
    if (temp.size() == n)
    {
        if (find(graph[node].begin(), graph[node].end(), start) != graph[node].end())
        {
            temp.push_back(start);
            ans.push_back(temp);
            temp.pop_back();
        }
    }
    else
    {
        for (auto ch : graph[node])
        {
            if (!vis[ch])
            {
                dfsHamiltonianCycle(ch, start, graph, vis, temp, ans, n);
            }
        }
    }
    temp.pop_back();
    vis[node] = 0;
}

vector<vector<int>> findAllHamiltonianCycles(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        vector<int> vis(n, 0);
        vector<int> temp;
        dfsHamiltonianCycle(i, i, graph, vis, temp, ans, n);
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}};

    vector<vector<int>> hamiltonianCycles = findAllHamiltonianCycles(graph);
    cout << "Hamiltonian Cycles:" << endl;
    for (const auto &cycle : hamiltonianCycles)
    {
        for (int node : cycle)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
  0 → 1
  ↓   ↑
  3 → 2
  ↓   ↑
  0 → 1

*/