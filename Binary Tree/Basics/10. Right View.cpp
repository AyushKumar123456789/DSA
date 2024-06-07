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

// Should return  right view of tree
class Solution
{
public:
    // Function to return list containing elements of right view of binary tree.
    void left_view(Node *root, int level, vector<int> &ans)
    {
        if (root == NULL)
            return;
        if (ans.size() == level)
        {
            ans.push_back(root->data);
        }
        left_view(root->right, level + 1, ans);
        left_view(root->left, level + 1, ans);
    }
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        left_view(root, 0, ans);
        return ans;
    }
};
