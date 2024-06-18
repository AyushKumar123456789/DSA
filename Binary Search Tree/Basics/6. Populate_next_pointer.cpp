// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/

// Given a binary tree, connect the nodes that are at the same level. You'll be given the tree in level order format.

// Example 1:

// Input:
//       3
//      / \
//     4   2
// Output:
// 3 -> NULL
// 4 -> 2 -> NULL

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    struct Node *next;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
        next = NULL;
    }
};

void populateNext(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            temp->next = q.front();

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(2);

    populateNext(root);

    return 0;
}