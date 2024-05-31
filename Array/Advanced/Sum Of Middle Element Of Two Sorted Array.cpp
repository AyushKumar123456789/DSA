#include <bits/stdc++.h>
using namespace std;

int findMidSum(int ar1[], int ar2[], int n)
{
    int l2 = 0, r1 = n - 1;
    while (l2 < n && r1 >= 0)
    {
        if (ar2[l2] < ar1[r1])
        {
            swap(ar2[l2], ar1[r1]);
            l2++;
            r1--;
        }
        else
        {
            break;
        }
    }
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return ar1[n - 1] + ar2[0];
}

//

int findMidSum(int arr1[], int arr2[], int n)
{
    int l1 = 0, l2 = 0;
    int merged[2 * n];
    int k = 0;
    while (l1 < n && l2 < n)
    {
        if (arr1[l1] < arr2[l2])
        {
            merged[k++] = arr1[l1++];
        }
        else
        {
            merged[k++] = arr2[l2++];
        }
    }
    while (l1 < n)
    {
        merged[k++] = arr1[l1++];
    }
    while (l2 < n)
    {
        merged[k++] = arr2[l2++];
    }
    return merged[n] + merged[n - 1];
}

int findMidSum(int arr1[], int arr2[], int n)
{
    int l1 = 0, l2 = 0;
    int k = 0;
    int mid1 = -1, mid2 = -1; // to store the middle elements

    while (l1 < n && l2 < n)
    {
        int current;
        if (arr1[l1] < arr2[l2])
        {
            current = arr1[l1];
            l1++;
        }
        else
        {
            current = arr2[l2];
            l2++;
        }

        if (k == n - 1)
        {
            mid1 = current; // first middle element
        }
        if (k == n)
        {
            mid2 = current;     // second middle element
            return mid1 + mid2; // sum of middle elements
        }
        k++;
    }

    // If we exit the loop without finding both mid elements,
    // it means remaining elements are all from one array
    while (l1 < n)
    {
        int current = arr1[l1];
        if (k == n - 1)
        {
            mid1 = current;
        }
        if (k == n)
        {
            mid2 = current;
            return mid1 + mid2;
        }
        l1++;
        k++;
    }

    while (l2 < n)
    {
        int current = arr2[l2];
        if (k == n - 1)
        {
            mid1 = current;
        }
        if (k == n)
        {
            mid2 = current;
            return mid1 + mid2;
        }
        l2++;
        k++;
    }

    return -1; // In case something goes wrong, though logically it shouldn't
}

/*
Binary Search

Initialize low = 0 and high = n, where n is the size of the first array.
Find the point to partition the ar1 into 2 parts using Binary Search.
First halve should have the elements smaller or equal to the first middle element and second halve should have the element greater or equal to the second middle element. And each half will have n elements.
Using the partition point of ar1, find the partition point for ar2.
Check whether all the elements in first half is smaller than second half.
l1 = largest element of the first half from ar1
l2 = largest element of the first half from ar2
r1 = smallest element of the second half from ar1
r2 = smallest element of the second half from ar2
Since l1 is already less than r1 and l2 is already less than r2,
if(l1 > r2)
high = cut1 – 1
if(l2 > r1)
low = cut1+1
else
return max(l1, l2) + min(r1, r2)
Since max of the largest elements of first halves from ar1 and ar2  will be the maximum in first half and min of the smallest elements from second halves from ar1 and ar2 will be the smallest in the second half, return the sum of the max(l1, l2) and min(r1, r2).


*/

// C++ code for the above approach:

int findMidSum(int ar1[], int ar2[], int n)
{
    if (n == 1)
    {
        return ar1[0] + ar2[0];
    }
    if (n == 2)
    {
        return max(ar1[0], ar2[0]) + min(ar1[1], ar2[1]);
    }
    // code here
    int low = 0, high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = n - cut1;

        int l1 = (cut1 == 0 ? INT_MIN : ar1[cut1 - 1]);
        int l2 = (cut2 == 0 ? INT_MIN : ar2[cut2 - 1]);
        int r1 = (cut1 == n ? INT_MAX : ar1[cut1]);
        int r2 = (cut2 == n ? INT_MAX : ar2[cut2]);

        if (l1 > r2)
        {
            high = cut1 - 1;
        }
        else if (l2 > r1)
        {
            low = cut1 + 1;
        }
        else
        {
            ans = max(l1, l2) + min(r1, r2);
            break;
        }
    }
    return ans;
}

// C++ code for the above approach:
int main()
{

    int ar1[] = {1, 2, 4, 6, 10};
    int ar2[] = {4, 5, 6, 9, 12};
    int n = sizeof(ar1) / sizeof(ar1[0]);
    // Function Call
    cout << findMidSum(ar1, ar2, n);

    return 0;
}
