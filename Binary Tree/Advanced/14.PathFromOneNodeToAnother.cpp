// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/

/*
Write it again if have time
*/

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

private:
    TreeNode *lca(TreeNode *root, int node1, int node2)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (root->val == node1 || root->val == node2)
        {
            return root;
        }
        TreeNode *lft = lca(root->left, node1, node2);
        TreeNode *rt = lca(root->right, node1, node2);
        if (lft == NULL)
        {
            return rt;
        }
        if (rt == NULL)
        {
            return lft;
        }
        return root;
    }

    string height(TreeNode *root, int node, string &path)
    {
        if (root == NULL)
        {
            return "";
        }
        if (root->val == node)
        {
            return path;
        }
        path += "U";
        string pth_lft = height(root->left, node, path);
        string pth_rt = height(root->right, node, path);
        if (pth_lft.size() > 0)
        {
            return pth_lft;
        }
        if (pth_rt.size() > 0)
        {
            return pth_rt;
        }
        path.pop_back();
        return "";
    }

    string Marg(TreeNode *st, int end, string &path)
    {
        if (st == NULL)
        {
            return "";
        }
        if (st->val == end)
        {
            return path;
        }
        path += "L";
        string pth_lft = Marg(st->left, end, path);
        path.pop_back();
        path += "R";
        string pth_rt = Marg(st->right, end, path);
        path.pop_back();
        if (pth_lft.size() > 0)
        {
            return pth_lft;
        }
        if (pth_rt.size() > 0)
        {
            return pth_rt;
        }
        return "";
    }

public:
    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        TreeNode *LCA = lca(root, startValue, destValue);
        string ans1 = "";
        string ans2 = "";
        string temp = "";
        if (LCA->val == startValue)
        {
            cout << "case 1 " << endl;
            ans1 = Marg(LCA, destValue, temp);
        }
        else if (LCA->val == destValue)
        {
            cout << "case 2 " << endl;
            ans1 = height(LCA, startValue, temp);
        }
        else
        {
            cout << "case 3" << endl;
            ans1 = height(LCA, startValue, temp);
            temp = "";
            ans2 = Marg(LCA, destValue, temp);
        }
        cout << ans1 << " " << ans2 << endl;
        return ans1 + ans2;
    }
};