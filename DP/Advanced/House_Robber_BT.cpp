// https://leetcode.com/problems/house-robber-iii

/*
index 0 : not take root
index 1 : take root
*/

vector<int> f(TreeNode *root)
{
    if (root == NULL)
    {
        return {0, 0};
    }
    auto lft = f(root->left);
    auto rt = f(root->right);
    int a = lft[1] + rt[1] + root->val;
    int b = max(lft[1] + rt[1], max(lft[0] + rt[0], max(lft[1] + rt[0], lft[0] + rt[1])));
    return {a, b};
}

int rob(TreeNode *root)
{
    auto temp = f(root);
    return max(temp[0], temp[1]);
}