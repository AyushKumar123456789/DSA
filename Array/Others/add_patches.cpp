// https://leetcode.com/problems/patching-array/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Question  : Given a sorted positive integer array nums and an integer n, add/patch elements to the array such that any number in range [1, n]
inclusive can be formed by the sum of some elements in the array. Return the minimum number of patches required.
*/

/*


Sum Key Observation:
1. If we have all numbers from 1 to x, then we can atlesat make all numbers from 1 to 2x-1.
Because, Let say we have 1,2,3,4..x
then we can make x+1,x+2,x+3...(x+(x-1)) = 2x-1 & more.
But, it doesn't mean to form all number from 1 to n, we need to have all numbers from 1 to (n+1)/2. (i.e by 2x-1 = n)
because if you see ,
for n=1 we need 1
for n=2 we need 1,2
for n=3 we just need 1,2
So from here if we just include 4 to it then we can make 1,2,3,4,5,6,7 (i.e 1 to 2*x-1)
and then you need to add 8 to to form 8,9,10,11,12,13,14,15 (i.e 1 to 2*x-1)
Therefore, for n=4 we need 1,2,4
for n=5 we need 1,2,4
for n=6 we need 1,2,4
for n=7 we need 1,2,4
for n=8 we need 1,2,4,8
...
for n=15 we need 1,2,4,8



*/

class Solution
{
public:
    int minPatches(vector<int> &nums, int n)
    {
        long miss = 1, added = 0, i = 0;
        while (miss <= n)
        {
            if (i < nums.size() && nums[i] <= miss)
            {
                miss += nums[i++];
            }
            else
            {
                miss += miss;
                added++;
            }
        }
        return added;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 5, 10};
    cout << s.minPatches(nums, 20) << endl;
    return 0;
}