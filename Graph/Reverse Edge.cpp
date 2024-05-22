// https://www.naukri.com/code360/problems/reverse-edges_1200162?topList=love-babbar-dsa-sheet-problems&utm_source=website&utm_medium=affiliate&utm_campaign=450dsatracker&leftPanelTabValue=PROBLEM

/*
Two Ways to solve it :
1. Convert to Directed Graph and USE Dijkstra , Time Complexity : O(ElogV)
2. 0-1 BFS , Time Complexity: O(V+E)
*/

// 1. Dijkstra , Time Complexity : O(ElogV) and Space Complexity : O(V+E)

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    pq.push({0, S});
    dist[S] = 0;
    while (!pq.empty())
    {
        auto temp = pq.top();
        pq.pop();
        auto node = temp.second;
        auto cur_node_dist = temp.first;
        if (dist[node] < cur_node_dist)
            continue;
        for (auto ch : adj[node])
        {
            int child_dist = cur_node_dist + ch[1];
            if (child_dist < dist[ch[0]])
            {
                dist[ch[0]] = child_dist;
                pq.push({child_dist, ch[0]});
            }
        }
    }
    return dist;
}

int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
    vector<vector<int>> graph[n];
    for (int i = 0; i < edgeList.size(); i++)
    {
        graph[edgeList[i][0]].push_back({edgeList[i][1], 0});
        graph[edgeList[i][1]].push_back({edgeList[i][0], 1});
    }

    vector<int> dist = dijkstra(n, graph, start);

    return dist[end];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v, e;
        cin >> v >> e;
        int st, en;
        cin >> st >> en;
        vector<vector<int>> arr;
        for (int i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            arr.push_back({a, b});
        }

        cout << reverseEdges(v, st, en, arr) << endl;
    }
}

// 2. 0-1 BFS , Time Complexity: O(V+E) and Space Complexity : O(V+E)

#include <bits/stdc++.h>

int reverseEdges(int n, int start, int end, vector<vector<int>> &edgeList)
{
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < edgeList.size(); i++)
    {
        graph[edgeList[i][0]].push_back({0, edgeList[i][1]});
        graph[edgeList[i][1]].push_back({1, edgeList[i][0]});
    }
    vector<int> dist(n, 1000000);
    deque<int> Q;
    Q.push_back(start);
    dist[start] = 0;
    while (!Q.empty())
    {
        int node = Q.front();
        Q.pop_front();
        for (auto ch : graph[node])
        {
            if (dist[ch.second] > dist[node] + ch.first)
            {
                dist[ch.second] = ch.first + dist[node];
                if (ch.first == 1)
                {
                    Q.push_back(ch.second);
                }
                else
                {
                    Q.push_front(ch.second);
                }
            }
        }
    }
    return dist[end];
}