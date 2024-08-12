// https://www.geeksforgeeks.org/problems/duplicate-subtrees/1

/*
Question : Find all the duplicate subtrees in a binary tree.

Approach : The idea is to use hashing. We store inorder traversals of subtrees in a hash. Since simple inorder traversal cannot uniquely identify a tree, we use symbols like ‘(‘ and ‘)’ to represent NULL nodes.

We pass an Unordered Map in C++ as an argument to the helper function which recursively calculates inorder string and increases its count in map.
If any string gets repeated, then it will imply duplication of the subtree rooted at that node
so push that node in the Final result and return the vector of these nodes.
*/

#include <bits/stdc++.h>
using namespace std;

map<string, int> dp;
vector<Node *> ans;
string inorder(Node *root)
{
    if (root == NULL)
    {
        return "";
    }
    string str = "(";
    str += inorder(root->left);
    str += to_string(root->data);
    str += inorder(root->right);
    str += ")";
    if (dp[str] == 1)
    {
        ans.push_back(root);
    }
    dp[str]++;
    return str;
}

vector<Node *> printAllDups(Node *root)
{
    inorder(root);
    return ans;
}

int main()
{
    // Create a tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);
    vector<Node *> res = printAllDups(root);
    for (auto x : res)
    {
        cout << x->data << " ";
    }
    return 0;
}
