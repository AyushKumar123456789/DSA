// https://leetcode.com/problems/4sum/description/

// Approach : Use Sorting, Time Complexity: O(N^3) , Space Complexity: O(1)
// Similar to 3Sum, but with an additional loop.
// 1. Sort the array.
// 2. Fix the first element, and then use 3Sum logic to find the remaining 3 elements.
// 3. Skip duplicates