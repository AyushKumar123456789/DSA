// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

/*
Little variation of previous code , just reverse postorder traversal and traverse right first then left.
*/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *f(vector<int> &postorder, vector<int> &inorder, int &index, int in_start, int in_end)
{
    if (index == postorder.size() || in_start > in_end)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(postorder[index]);
    index++;
    int temp = -1;
    for (int i = in_start; i <= in_end; i++) // This function is removed by using map
    {
        if (inorder[i] == root->val)
        {
            temp = i;
            break;
        }
    }
    root->right = f(postorder, inorder, index, temp + 1, in_end);
    root->left = f(postorder, inorder, index, in_start, temp - 1);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postOrderIndex = 0;
    reverse(postorder.begin(), postorder.end());
    TreeNode *ans = f(postorder, inorder, postOrderIndex, 0, inorder.size() - 1);
    return ans;
}