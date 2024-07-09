#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    int freq;
    node *left, *right;
    node(char data, int freq)
    {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

struct compare
{
    bool operator()(node *l, node *r)
    {
        return (l->freq > r->freq);
    }
};

void printCodes(node *root, string str)
{
    if (!root)
        return;
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void huffmanCodes(char data[], int freq[], int size)
{
    node *left, *right, *top;
    priority_queue<node *, vector<node *>, compare> minHeap;
    for (int i = 0; i < size; i++)
        minHeap.push(new node(data[i], freq[i]));
    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        top = new node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
    printCodes(minHeap.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffmanCodes(arr, freq, size);
    return 0;
}