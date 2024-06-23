// https: // leetcode.com/problems/all-paths-from-source-to-target/

void dfs(int node, vector<vector<int>> &graph, vector<int> &vis, vector<int> &temp, vector<vector<int>> &ans)
{
    vis[node] = 1;
    temp.push_back(node);
    if (node == graph.size() - 1)
    {
        ans.push_back(temp);
    }
    for (auto ch : graph[node])
    {
        if (!vis[ch])
        {
            dfs(ch, graph, vis, temp, ans);
        }
    }
    temp.pop_back();
    vis[node] = 0;
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<int> vis(graph.size(), 0);
    vector<vector<int>> ans;
    vector<int> temp;
    dfs(0, graph, vis, temp, ans);
    return ans;
}