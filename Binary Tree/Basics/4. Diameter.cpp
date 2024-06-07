#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
    Node(int data)
    {
        this->data = data;
    }
};

Node *CreateBinaryTree(Node *root)
{
    int data;
    cout << "Enter data : ";
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter left child of " << data << " : ";
    root->left = CreateBinaryTree(root->left);
    cout << "Enter right child of " << data << " : ";
    root->right = CreateBinaryTree(root->right);
    return root;
}

/*
Similar Code as Height of Node the differnce is we are adding the max height of left and right and minus 1 because root it counted twice.
*/

int height(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int ht_l = 0, ht_r = 0;
    ht_l = max(ht_l, height(root->left, ans) + 1);
    ht_r = max(ht_r, height(root->right, ans) + 1);
    ans = max(ans, ht_l + ht_r - 1);
    return max(ht_l, ht_r);
}

int diameter(Node *root)
{
    int ans = 0;
    int ht = height(root, ans);
    return ans;
}

int main()
{
    Node *root = NULL;
    root = CreateBinaryTree(root);
    cout << endl;
    cout << "Diameter of the tree is : " << diameter(root);
    return 0;
}