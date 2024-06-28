#include <bits/stdc++.h>
using namespace std;

void update(int index, int val, vector<int> &BIT)
{
    int n = BIT.size();
    while (index <= n)
    {
        BIT[index] += val;
        index = index + (index & -index);
    }
}

int query(int index, vector<int> &BIT)
{
    int sum = 0;
    while (index > 0)
    {
        sum += BIT[index];
        index = index - (index & -index);
    }
    return sum;
}

int main()
{
    cout << "Enter the size of array: ";
    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    vector<int> BIT(n + 1, 0);

    cout << "Enter the elements of array: ";
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        update(i, arr[i], BIT);
    }

    cout << "Enter the number of queries: ";
    int q;
    cin >> q;
    while (q--)
    {
        cout << "Enter the type of query (1 for update, 2 for query): ";
        int type;
        cin >> type;
        if (type == 1)
        {
            cout << "Enter the index and value to update: ";
            int index, val;
            cin >> index >> val;
            update(index, val, BIT);
        }
        else
        {
            cout << "Enter the left index : ";
            int l, r;
            cin >> l;
            cout << "Enter the right index : ";
            cin >> r;
            cout << "Sum of elements from l  " << l << " to " << r << " is: " << query(r, BIT) - query(l - 1, BIT) << endl;
        }
    }
}