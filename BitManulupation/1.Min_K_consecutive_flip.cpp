// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

/*
Logic :
1. We will use a flip variable to keep track of the number of flips done till now.
2. We will use a isFlipped array to keep track whether a flip operation is active at a particular index.(1 if active, 0 if not active) ,  means the flip effect on variable done by the index at i-k to be removed.
3. We will iterate over the array and check if the current element is equal to flip or not.
4. If it is equal to flip, then we will check if we can flip the bits or not.
5. If we can flip the bits, then we will increment the flip variable and isFlipped array.
6. If we can't flip the bits, then we will return -1.
7. If we reach the end of the array, then we will return the answer.


*/

int minKBitFlips(vector<int> &nums, int k)
{
    int n = nums.size();
    int flip = 0;
    int ans = 0;
    vector<int> isFlipped(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i >= k)
        {
            flip ^= isFlipped[i - k];
        }
        if (nums[i] == flip)
        {
            if (i + k > n)
                return -1;
            flip ^= 1;
            isFlipped[i] = 1;
            ans++;
        }
    }
    return ans;
}