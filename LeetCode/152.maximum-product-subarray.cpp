/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;

        // dp[i][0] saves the max at i
        // dp[i][1] saves the min at i
        int dp[2][2], res;

        // dp[0]'s max and min are nums[0] itself
        dp[0][0] = dp[0][1] = res = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            int j = i % 2;
            int j_1 = (i - 1) % 2;

            dp[j][0] = max(max(dp[j_1][0] * nums[i], dp[j_1][1] * nums[i]), nums[i]);
            dp[j][1] = min(min(dp[j_1][0] * nums[i], dp[j_1][1] * nums[i]), nums[i]);

            res = max(res, dp[j][0]);
        }

        return res;
    }
};
// @lc code=end

