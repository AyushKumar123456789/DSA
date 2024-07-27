/*
    Dearrangement is number of way to arrange elements such that no element is in their right position
    SO,
    f(n)->number of way to arrange n element such that no element is in right position
    So, first element has n-1 way places to go
    Now, there are two cases if first element goes to ith index and ith index element comes to first index then there are total (n-1)*f(n-1) way

    second case is the the ith element not goes to first index then total ways are (n-1)*f(n-2)

    therefor f(n) = (n-1)*(f(n-1)+f(n-2))
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[3];
    arr[1] = 0;
    arr[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        arr[i % 3] = (i - 1) * (arr[(i - 1) % 3] + arr[(i - 2) % 3]);
    }
    cout << arr[n % 3] << endl;
}