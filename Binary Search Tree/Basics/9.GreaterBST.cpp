// https://leetcode.com/problems/convert-bst-to-greater-tree/description/

void inorder(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;
    inorder(root->left, sum);
    sum += (root->val);
    inorder(root->right, sum);
}

void put_inorder(TreeNode *root, int &sum)
{
    if (root == NULL)
        return;
    put_inorder(root->left, sum);
    int temp = root->val;
    root->val = sum;
    sum -= (temp);
    put_inorder(root->right, sum);
}

TreeNode *convertBST(TreeNode *root)
{
    int sum = 0;
    inorder(root, sum);
    put_inorder(root, sum);
    return root;
}

// Time Complexity: O(n) where n is the number of nodes in the tree.
// Space Complexity: O(n) where n is the number of nodes in the tree.

/*
Instead of traversing the tree two times we can do it in one pass.
*/

class Solution
{
private:
    int sum = 0;

    void traverse(TreeNode *root)
    {
        if (root)
        {
            traverse(root->right); // Traverse the right subtree
            sum += root->val;      // Update the sum
            root->val = sum;       // Update the current node's value
            traverse(root->left);  // Traverse the left subtree
        }
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        traverse(root);
        return root;
    }
};