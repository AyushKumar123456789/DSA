#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll ans = 0ll;

ll f(ll node, vector<vector<ll>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    if (graph[node].size() == 0)
    {
        return 0;
    }
    vector<ll> hts;
    for (auto ch : graph[node])
    {
        if (!visited[ch])
        {
            ll ht = f(ch, graph, visited) + 1;
            hts.push_back(ht);
        }
    }
    if (hts.size() == 0)
    {
        return 0;
    }
    sort(hts.begin(), hts.end(), greater<ll>());
    if (hts.size() >= 2)
    {
        ans = max(ans, hts[0] + hts[1]);
    }
    else
    {
        ans = max(ans, hts[0]);
    }
    return hts[0];
}

int main()
{
    ll n;
    cin >> n;

    vector<vector<ll>> graph(n + 1);

    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // Since it's an undirected tree
    }

    vector<bool> visited(n + 1, false);
    f(1, graph, visited); // Assuming 1 is the root node

    cout << ans << endl;
}

/*
Better Logic :
Find the max distance node from the starting node, then from that node find the max distance node
*/

#include <bits/stdc++.h>
using namespace std;

// Define the maximum number of nodes
const int MAX = 2e5 + 5;
// Create an adjacency list for the tree
vector<int> adj[MAX];
// Create an array to store the distance of each node from
// the root
int dist[MAX];

// Depth-First Search function
void dfs(int node, int parent)
{
    // Iterate over all children of the current node
    for (auto child : adj[node])
    {
        // If the child is not the parent
        if (child != parent)
        {
            // Update the distance of the child
            dist[child] = dist[node] + 1;
            // Recursively call DFS for the child
            dfs(child, node);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Number of nodes (static input)
    int n = 5;

    // Edges of the tree (static input)
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {3, 4}, {3, 5}};

    // Add edges to the adjacency list
    for (auto edge : edges)
    {
        int a = edge.first, b = edge.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Initialize the distance of the first node and call
    // DFS
    dist[1] = 0;
    dfs(1, 0);

    // Find the node with the maximum distance from the
    // first node
    int maxDist = 0, node = 1;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
            node = i;
        }
    }

    // Reset the distances and call DFS from the farthest
    // node
    for (int i = 1; i <= n; i++)
    {
        dist[i] = 0;
    }
    dfs(node, 0);

    // Find the maximum distance from the farthest node
    maxDist = 0;
    for (int i = 1; i <= n; i++)
    {
        maxDist = max(maxDist, dist[i]);
    }

    // Print the diameter of the tree
    cout << maxDist << "\n";

    return 0;
}
