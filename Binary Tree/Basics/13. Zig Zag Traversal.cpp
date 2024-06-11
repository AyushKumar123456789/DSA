// https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1

vector<int> zigZagTraversal(Node *root)
{
    vector<int> ans;
    queue<Node *> Q;
    Q.push(root);
    Q.push(NULL);
    vector<int> temp;
    int idx = 0;
    while (!Q.empty())
    {
        auto node = Q.front();
        Q.pop();
        if (node == NULL)
        {
            if (idx % 2 == 1)
            {
                for (int i = temp.size() - 1; i >= 0; i--)
                {
                    ans.push_back(temp[i]);
                }
            }
            else
            {
                for (int i = 0; i < temp.size(); i++)
                {
                    ans.push_back(temp[i]);
                }
            }
            if (!Q.empty())
            {
                Q.push(NULL);
            }
            idx++;
            temp.clear();
            continue;
        }
        temp.push_back(node->data);
        if (node->left)
        {
            Q.push(node->left);
        }
        if (node->right)
        {
            Q.push(node->right);
        }
    }
    return ans;
}