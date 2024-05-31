// https://www.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1

/*
Total Rain Water Tapping , there is another question also with max rain water tapping
*/

long long trappingWater(int arr[], int n)
{
    // Edge case
    if (n <= 1)
        return 0;

    // Arrays to store the maximum height to the left and right of each element
    std::vector<long long> leftMax(n, 0);
    std::vector<long long> rightMax(n, 0);

    // Fill leftMax array
    leftMax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        leftMax[i] = std::max(leftMax[i - 1], (long long)arr[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        rightMax[i] = std::max(rightMax[i + 1], (long long)arr[i]);
    }

    // Calculate the trapped water
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += std::min(leftMax[i], rightMax[i]) - arr[i];
    }

    return ans;
}

// Expected Time Complexity: O(N)
// Expected Auxiliary Space : O(N)