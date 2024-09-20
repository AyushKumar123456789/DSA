class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        // Ensure nums1 is the smaller array
        if (n > m)
            return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int h = n; // note: h = n, not n-1

        while (l <= h)
        {
            int mid1 = (l + h) / 2;
            int mid2 = (n + m + 1) / 2 - mid1; // ensure proper partitioning

            int n_lft = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int n_rt = (mid1 == n) ? INT_MAX : nums1[mid1];

            int m_lft = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int m_rt = (mid2 == m) ? INT_MAX : nums2[mid2];

            // Check if partition is correct
            if (n_lft <= m_rt && m_lft <= n_rt)
            {
                // If total number of elements is odd
                if ((n + m) % 2 == 1)
                {
                    return max(n_lft, m_lft);
                }
                // If total number of elements is even
                else
                {
                    return (max(n_lft, m_lft) + min(n_rt, m_rt)) / 2.0;
                }
            }
            // Adjust binary search bounds
            else if (n_lft > m_rt)
            {
                h = mid1 - 1; // move to the left in nums1
            }
            else
            {
                l = mid1 + 1; // move to the right in nums1
            }
        }

        return -1.0; // Should never reach here if inputs are valid
    }
};
