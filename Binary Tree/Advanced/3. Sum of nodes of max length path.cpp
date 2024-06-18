// https://www.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1

/*
Easy Question
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
        left = NULL;
        right = NULL;
    }
};

Node *create_tree(Node *root)
{
    int n;
    cout << "Enter value : ";
    cin >> n;
    if (n == -1)
    {
        return NULL;
    }
    Node *temp = new Node(n);
    cout << " Enter Left Node : ";
    temp->left = create_tree(temp->left);
    cout << "Enter Right Node : ";
    temp->right = create_tree(temp->right);
    root = temp;
    return root;
}

void f(Node *root, int &max_level, int &max_sum, int curr_level, int curr_sum)
{
    if (root == NULL)
    {
        return;
    }
    if (curr_level >= max_level)
    {
        if (max_level == curr_level)
        {
            max_sum = max(max_sum, curr_sum + root->data);
        }
        else
        {
            max_level = curr_level;
            max_sum = curr_sum + root->data;
        }
    }
    f(root->left, max_level, max_sum, curr_level + 1, curr_sum + root->data);
    f(root->right, max_level, max_sum, curr_level + 1, curr_sum + root->data);
}

int sumOfLongRootToLeafPath(Node *root)
{
    int max_level = 0;
    int max_sum = 0;
    f(root, max_level, max_sum, 0, 0);
    return max_sum;
}

int main()
{
    Node *root = NULL;
    root = create_tree(root);
    cout << "sum of longest path : " << endl;
    cout << sumOfLongRootToLeafPath(root) << endl;
}