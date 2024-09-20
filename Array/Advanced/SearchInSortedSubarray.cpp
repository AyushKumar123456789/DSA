// https://leetcode.com/problems/search-in-rotated-sorted-array/

/*
Problem:
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values),
which is rotated at an unknown pivot index. You have to search for the target element in the array.

Approach:
So, the array is not increasing order but it increasing upto some point and suddenly decreasing and then again increasing.
FOr example let array be [4,5,6,7,0,1,2] here 4,5,6,7 is increasing and 0,1,2 is also increasing.
So, basically low and high pointer either lies on different sections for  example low lies on 4,5,6,7 and high lies on 0,1,2
Or , both low and high lies on one section for example low and high both lies on 4,5,6,7 or 0,1,2.
Therefore we have if for both cases.

if nums[low]<=nums[high] then they are in same section.
else they are in different section.



*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            cout << low << " " << mid << " " << high << endl;
            if (nums[low] <= nums[high])
            {
                if (target > nums[mid])
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
            else
            {
                if (nums[low] <= nums[mid])
                {
                    if (target <= nums[mid] && target >= nums[low])
                    {
                        high = mid - 1;
                    }
                    else
                    {
                        low = mid + 1;
                    }
                }
                else
                {
                    if (target >= nums[mid] && target <= nums[high])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }
            }
        }
        if (nums[low] == target)
        {
            return low;
        }
        return -1;
    }
};