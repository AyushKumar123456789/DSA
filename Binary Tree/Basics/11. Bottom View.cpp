/*
Two Concept is Used here :
1. Level Order Traversal with queue of pair storing horizontal position ie, 0 for root ans +1 for right ans -1 for left
2. Map that store key as horizontal position and value as node value in sorted order.

Time Complexity : O(NlogN) + O(N) = O(NlogN)
Space : O(N) + O(N) = O(N) for map and queue

*/

vector<int> bottomView(Node *root)
{
    map<int, int> mp;
    vector<int> ans;
    queue<pair<Node *, int>> Q;
    Q.push({root, 0});
    while (!Q.empty())
    {
        auto temp = Q.front();
        Q.pop();
        mp[temp.second] = temp.first->data;
        if (temp.first->left)
        {
            Q.push({temp.first->left, temp.second - 1});
        }
        if (temp.first->right)
        {
            Q.push({temp.first->right, temp.second + 1});
        }
    }

    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}