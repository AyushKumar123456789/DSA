/*
Very Important , This question was asked to me in interview of company name Onefinnet (Elevate 2.0).
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

struct value
{
    int maxi = -100000;
    int mini = 1000000;
    bool is_bst = 0;
    int sz = 0;
};

Node *create_BinaryTree(Node *root)
{
    cout << "Enter value Or if want to stop enter -1 : ";
    int n;
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }

    root = new Node(n);
    root->left = create_BST(root->left);
    root->right = create_BST(root->right);
    return root;
}

value max_size_BST(Node *root, int &ans)
{
    if (root == NULL)
    {
        value temp;
        temp.is_bst = 1;
        return temp;
    }

    value lft = max_size_BST(root->left, ans);
    value rt = max_size_BST(root->right, ans);
    if (root->data > lft.maxi && root->data < rt.mini && lft.is_bst && rt.is_bst)
    {
        value temp;
        temp.is_bst = 1;
        temp.maxi = max(rt.maxi, root->data);
        temp.mini = min(lft.mini, root->data);
        temp.sz = lft.sz + rt.sz + 1;
        ans = max(ans, temp.sz);
        return temp;
    }
    value temp;
    temp.is_bst = 0;
    return temp;
}

int main()
{
    Node *root = NULL;
    root = create_BinaryTree(root);
    int ans = 0;
    max_size_BST(root, ans);
    cout << ans;
    return 0;
}

// Time Complexity : O(N)
// Space Complexity : O(N)

// Input : 10 5 15 1 8 -1 -1 -1 -1 7 9 -1 -1 -1 -1
/*
Tree :
        10
       /  \
      5    15
     / \   / \
    1   8 7   9
*/
// Output : 3
