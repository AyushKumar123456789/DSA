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

bool isIsomorphic(Node *root1, Node *root2)
{

    if (root1 == NULL || root2 == NULL)
    {
        return root1 == root2;
    }

    if (root1->data != root2->data)
    {
        return 0;
    }
    return (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left)) || (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right));
}