// https://www.geeksforgeeks.org/problems/is-binary-tree-heap/1

// Check if a given binary tree is a heap.

/*
A binary tree is a Max-Heap if all of the following are true :
1. It is a complete tree (i.e. all levels except possibly the last, are completely filled, and all nodes are as left as possible).
2. Every parent node's value is greater than or equal to its child node (considering the max-heap).

*/

/*
Time Complexity: Analysis
is_cbt() function is called for every node in the tree. So, the time complexity is O(n) where n is the number of nodes in the tree.
check_heap() function is called for every node in the tree. So, the time complexity is O(n) where n is the number of nodes in the tree.
count_nodes() function is called for every node in the tree. So, the time complexity is O(n) where n is the number of nodes in the tree.
So, the overall time complexity is O(n) + O(n) + O(n) = O(n).

Space Complexity: Analysis

The space complexity is O(n) because the maximum space used by the recursion stack is O(n) due to at most n recursive calls on the stack at any time.



*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

bool is_cbt(Node *root, int idx, int total_node)
{
    if (root == NULL)
    {
        return true;
    }

    if (idx >= total_node)
    {
        return false;
    }

    return is_cbt(root->left, 2 * idx + 1, total_node) && is_cbt(root->right, 2 * idx + 2, total_node);
}

bool check_heap(Node *tree)
{
    if (tree == NULL)
    {
        return true;
    }

    bool check = true;
    if (tree->left)
    {
        if (tree->left->data > tree->data)
        {
            check = false;
        }
    }
    if (tree->right)
    {
        if (tree->right->data > tree->data)
        {
            check = false;
        }
    }

    bool lft = check_heap(tree->left);
    bool rt = check_heap(tree->right);
    return (lft && rt && check);
}

int count_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

bool isHeap(struct Node *tree)
{
    if (tree == NULL)
    {
        return true;
    }

    int total_nodes = count_nodes(tree);

    return is_cbt(tree, 0, total_nodes) && check_heap(tree);
}

Node *newNode(int k)
{
    Node *node = new Node;
    node->data = k;
    node->right = node->left = NULL;
    return node;
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(9);
    root->right = newNode(8);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    root->left->left->left = newNode(3);
    root->left->left->right = newNode(2);
    root->left->right->left = newNode(1);

    if (isHeap(root))
    {
        cout << "Given binary tree is a Heap\n";
    }
    else
    {
        cout << "Given binary tree is not a Heap\n";
    }

    return 0;
}