// https://www.geeksforgeeks.org/problems/leaf-at-same-level/1

void f(Node *root, int &leaf_level, int level, bool &check)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        if (leaf_level == -1)
        {
            leaf_level = level;
        }
        else
        {
            if (leaf_level != level)
            {
                check = 0;
            }
        }
    }

    f(root->left, leaf_level, level + 1, check);
    f(root->right, leaf_level, level + 1, check);
}

bool check(Node *root)
{
    bool check = 1;
    int temp = -1;
    f(root, temp, 0, check);
    return check;
}