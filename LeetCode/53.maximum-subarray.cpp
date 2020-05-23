/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return solution1(nums);
    }

    /* Solution 1: dp*/
    int solution1(vector<int> &nums)
    {
        int curr = 0, res = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            curr = max(curr + nums[i], nums[i]);
            res = max(res, curr);
        }

        return res;
    }
};
// @lc code=end
