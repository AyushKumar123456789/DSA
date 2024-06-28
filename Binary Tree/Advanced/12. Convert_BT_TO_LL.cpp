/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        TreeNode *temp_l = root->left;
        TreeNode *temp_r = root->right;
        if (prev == NULL)
        {
            prev = root;
            prev->left = NULL;
        }
        else
        {
            prev->right = root;
            prev->left = NULL;
            prev = prev->right;
        }
        flatten(temp_l);
        flatten(temp_r);
    }
};