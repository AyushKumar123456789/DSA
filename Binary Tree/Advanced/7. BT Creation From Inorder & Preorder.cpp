// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

/*
Logic :
1. First Element of preorder is root node and then find its index in inorder array, then the left of that index is part of left subtree and
right of it is part of right subtree .
2. Keep in mind preorder first index is passed with refrence & inorder array index is just used to check if to pass null or not.
3. Take Care Dont pass two much attribute to fucntion "f" , just , preorder and inorder and index and inorder start and inorder end.


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

TreeNode *f(vector<int> &preorder, vector<int> &inorder, int &index, int in_start, int in_end)
{
    if (index == preorder.size() || in_start > in_end)
    {
        return NULL;
    }

    TreeNode *root = new TreeNode(preorder[index]);
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
    root->left = f(preorder, inorder, index, in_start, temp - 1);
    root->right = f(preorder, inorder, index, temp + 1, in_end);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preOrderIndex = 0;
    TreeNode *ans = f(preorder, inorder, preOrderIndex, 0, inorder.size() - 1);
    return ans;
}
