
// https://leetcode.com/problems/binary-tree-cameras

int preorder(TreeNode *root, int &camera)
{
    // 1 : leaf/add camera ,2: node is survillenced but by childs camera so skip it , 3: node is not survillenced but it will be better to add camera on its parent node
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    auto lft = preorder(root->left, camera);
    auto rt = preorder(root->right, camera);
    if (lft == 1 || rt == 1)
    {
        camera++;
        return 2;
    }
    else if (lft == 2 || rt == 2)
    {
        return 3;
    }
    else if (lft == 3 || rt == 3)
    {
        return 1;
    }
    return 0;
}

int minCameraCover(TreeNode *root)
{
    int ans = 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int temp = preorder(root, ans);
    if (temp == 1)
        ans++;
    return ans;
}