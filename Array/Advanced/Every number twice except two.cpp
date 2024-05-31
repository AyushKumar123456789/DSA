// https://leetcode.com/problems/single-number-iii/?envType=daily-question&envId=2024-05-31

// https://leetcode.com/problems/single-number-iii/solutions/5233120/find-significant-bit-of-xor-split-in-2-group-with-math-proof-0ms-beats-100/?envType=daily-question&envId=2024-05-31

/*
    Good Question
*/

vector<int> singleNumber(vector<int> &nums)
{
    long long XOR = accumulate(nums.begin(), nums.end(), 0ll, bit_xor<int>());

    XOR = (XOR & (-XOR));
    int A = 0, B = 0;
    for (auto it : nums)
    {
        if ((it & XOR) == 0)
        {
            A ^= it;
        }
        else
        {
            B ^= it;
        }
    }

    return {A, B};
}