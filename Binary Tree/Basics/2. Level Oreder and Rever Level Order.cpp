#include <bits/stdc++.h>
using namespace std;

void LevelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *current = q.front();
        if (current == NULL)
        {
            cout << endl;
            q.pop();
            if (!q.empty()) // Queue is not empty
            {
                q.push(NULL);
            }
            continue;
        }

        cout << current->data << " ";
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        q.pop();
    }
}

/*
Reverse m bs Right wale ko pehle kholte hai and last me total reverse krte hai
*/

vector<int> reverseLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<Node *> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        Node *current = q.front();

        ans.push_back(current->data);
        if (current->right != NULL)
        {
            q.push(current->right);
        }
        if (current->left != NULL)
        {
            q.push(current->left);
        }
        q.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}