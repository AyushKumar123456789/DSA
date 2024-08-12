// https://www.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1

/*
Similar to previous Q, but difference is , two subtree must have size more than 1.
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
    str += root->data;
    str += inorder(root->right);
    str += ")";
    if (dp[str] == 1)
    {
        int cnt = 0;
        for (auto it : str)
        {
            if (it != '(' && it != ')')
            {
                cnt++;
            }
        }
        if (cnt > 1)
        {
            ans.push_back(root);
        }
    }
    dp[str]++;
    return str;
}
int dupSub(Node *root)
{
    inorder(root);
    return ans.size() > 0;
}
