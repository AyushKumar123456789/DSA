int ht(Node *root, bool &check)
{
    if (root == NULL)
        return 0;
    int lt = ht(root->left, check) + 1;
    int rt = ht(root->right, check) + 1;
    if (abs(lt - rt) > 1)
    {
        check = 0;
    }
    return max(lt, rt);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return 1;
    bool check = 1;
    ht(root, check);
    return !check;
}