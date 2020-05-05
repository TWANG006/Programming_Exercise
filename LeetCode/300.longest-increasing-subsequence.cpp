/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;

        /*Solution 1: DP, O(n^2)*/
        // LIS length at i 
        // vector<int> dp(nums.size(), 1);
        // int res = 1;

        // for (int i = 0; i < nums.size(); i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         if (nums[j] < nums[i])
        //             dp[i] = max(dp[i], dp[j] + 1);
        //     }
        //     res = max(res, dp[i]);
        // }

        // return res;

        /*Solution 2: O(nlogn), binary search*/
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if(it == res.end())
                res.push_back(nums[i]);
            else
                *it = nums[i];
        }
        return res.size();
    }
};
// @lc code=end

