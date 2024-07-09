// https://www.geeksforgeeks.org/problems/water-connection-problem5822/1

/*
It is basically a graph problem
*/

void dfs(int st, int node, int diameter, vector<pair<int, int>> graph[], vector<vector<int>> &ans)
{
    // cout<<"node : "<<node<<endl;
    bool check = 0;
    for (auto ch : graph[node])
    {
        check = 1;
        dfs(st, ch.first, min(diameter, ch.second), graph, ans);
    }
    if (!check && st != node)
    {
        // cout<<"st : "<<st<<" end : "<<node<<endl;
        ans.push_back({st, node, diameter});
    }
}

vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    vector<pair<int, int>> graph[n + 1];
    for (int i = 0; i < p; i++)
    {
        graph[a[i]].push_back({b[i], d[i]});
    }
    vector<int> indegree(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (auto ch : graph[i])
        {
            indegree[ch.first]++;
        }
    }
    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            dfs(i, i, 1000000, graph, ans);
        }
    }
    return ans;
}