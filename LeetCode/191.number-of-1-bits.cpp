/*
 * @lc app=leetcode id=191 lang=cpp
 *
 * [191] Number of 1 Bits
 */

// @lc code=start
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        for (; n; n &=(n - 1))
            ++res;

        return res;
    }
};
// @lc code=end
