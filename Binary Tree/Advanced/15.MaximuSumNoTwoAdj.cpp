// https://www.geeksforgeeks.org/problems/maximum-sum-of-non-adjacent-nodes/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

/*
Question : Find the maximum sum of non-adjacent nodes in a binary tree.
*/

/*
Easy question but DP is used,
So, for any node we have 4 options:
1. Include the node and exclude its children so include its grandchildren.
2. Exclude the node and include its children.
3. Exclude the node and include its one children and one grandchildren. (This results in two cases ,
either left child and right grandchild or right child and left grandchild)

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

map<Node *, int> dp;
int getMaxSum(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (dp.find(root) != dp.end())
    {
        return dp[root];
    }
    int lft = getMaxSum(root->left);
    int rt = getMaxSum(root->right);
    int val1 = 0;
    if (root->left)
    {
        val1 = getMaxSum(root->left->left) + getMaxSum(root->left->right);
    }
    int val2 = 0;
    if (root->right)
    {
        val2 = getMaxSum(root->right->right) + getMaxSum(root->right->left);
    }
    return dp[root] = max({lft + rt, val1 + val2 + root->data, val1 + rt, val2 + lft});
}

int main()
{
    // Create a tree
    Node *root = new Node(10);
    root->left = new Node(1);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(5);
    cout << getMaxSum(root) << endl;
    return 0;
}