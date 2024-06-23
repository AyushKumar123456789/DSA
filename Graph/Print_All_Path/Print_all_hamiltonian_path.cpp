#include <iostream>
#include <vector>

using namespace std;

/*
Similar to print all path code just base case change & take every node as src
*/

void dfsHamiltonianPath(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &temp, vector<vector<int>> &ans, int n)
{
    vis[node] = 1;
    temp.push_back(node);
    if (temp.size() == n)
    {
        ans.push_back(temp);
    }
    for (auto ch : graph[node])
    {
        if (!vis[ch])
        {
            dfsHamiltonianPath(ch, graph, vis, temp, ans, n);
        }
    }
    temp.pop_back();
    vis[node] = 0;
}

vector<vector<int>> findAllHamiltonianPaths(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n; ++i)
    {
        vector<int> vis(n, 0);
        vector<int> temp;
        dfsHamiltonianPath(i, graph, vis, temp, ans, n);
    }
    return ans;
}

int main()
{
    vector<vector<int>> graph = {
        {1, 2},
        {3},
        {1},
        {2}};

    vector<vector<int>> hamiltonianPaths = findAllHamiltonianPaths(graph);
    cout << "Hamiltonian Paths:" << endl;
    for (const auto &path : hamiltonianPaths)
    {
        for (int node : path)
        {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
  0 → 1
  ↓   ↓
  2<-3
  ↓
  1

*/
