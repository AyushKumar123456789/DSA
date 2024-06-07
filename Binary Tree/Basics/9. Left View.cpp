#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void left_view(Node *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (ans.size() == level)
    {
        ans.push_back(root->data);
    }
    left_view(root->left, level + 1, ans);
    left_view(root->right, level + 1, ans);
}

vector<int> leftView(Node *root)
{
    vector<int> ans;
    left_view(root, 0, ans);
    return ans;
}

/*
Another Approach using levelOrder Traversal and Using Null in Queue to point the end of each level and putting it in vector
*/