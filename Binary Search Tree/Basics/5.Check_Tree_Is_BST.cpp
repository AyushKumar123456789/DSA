#include "Basic_Bst_operation.cpp"

// https://leetcode.com/problems/validate-binary-search-tree/description/

bool check(Node *root, long long int mini, long long int maxi)
{
    if (root == NULL)
        return 1;
    if (root->data >= maxi || root->data <= mini)
        return 0;
    return check(root->left, mini, root->data) && check(root->right, root->data, maxi);
}

bool isBST(Node *root)
{
    return check(root, (long long int)INT_MIN - 1, (long long int)INT_MAX + 1);
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    cout << isBST(root) << endl;
    return 0;
}
