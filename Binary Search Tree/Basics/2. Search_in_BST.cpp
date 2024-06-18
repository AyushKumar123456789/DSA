#include "Basic_Bst_operation.cpp"

/*
Recursive approach:
Time complexity: O(h) where h is the height of the tree and h=log(n) in the case of a balanced BST and h=n in the case of a skewed BST.
Space complexity: O(h) for the recursive call stack.
*/

bool search(Node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (key < root->data)
    {
        return search(root->left, key);
    }
    return search(root->right, key);
}

/*
Search in BST using the iterative approach:
Time complexity: O(h) where h is the height of the tree and h=log(n) in the case of a balanced BST and h=n in the case of a skewed BST.
Space complexity: O(1).
*/

bool search_iterative(Node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return true;
        }
        if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return false;
}

int main()
{
    Node *root = createBst();
    cout << "Enter the key you want to search in the BST: ";
    int key;
    cin >> key;
    if (search(root, key))
    {
        cout << "Key found in the BST" << endl;
    }
    else
    {
        cout << "Key not found in the BST" << endl;
    }
    return 0;
}
