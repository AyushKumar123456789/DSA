// https://leetcode.com/problems/balance-a-binary-search-tree/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
    {
        val = x;
        left = right = NULL;
    }
};

TreeNode *createBT()
{
    cout << "Enter node data: ";
    int x;
    cin >> x;
    if (x == -1)
        return NULL;
    TreeNode *root = new TreeNode(x);
    cout << "Enter left of " << x << endl;
    root->left = createBT();
    cout << "Enter right of " << x << endl;
    root->right = createBT();
    return root;
}

/*
Optimal Approach :

Using Simple Inorder Taversal Concept,

Since , inorder array is alredy sorted
so to make it balance just always take middle element of inorder array and create node of it.

This requrie a vector to store inorder array .

Time Complexity : O(N)
Space Complexity : O(N) for vector + O(H) for stack space

*/

void Inorder(vector<int> &arr, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(arr, root->left);
    arr.push_back(root->val);
    Inorder(arr, root->right);
}

TreeNode *Balance(vector<int> &arr, int start, int end, TreeNode *n_root)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    TreeNode *temp = new TreeNode(arr[mid]);
    n_root = temp;
    n_root->left = Balance(arr, start, mid - 1, n_root->left);
    n_root->right = Balance(arr, mid + 1, end, n_root->right);
    return n_root;
}

TreeNode *balanceBST(TreeNode *root)
{
    vector<int> arr;
    Inorder(arr, root);
    TreeNode *n_root = NULL;
    return Balance(arr, 0, arr.size() - 1, n_root);
}