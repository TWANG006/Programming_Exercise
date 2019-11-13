/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (31.86%)
 * Likes:    1353
 * Dislikes: 268
 * Total Accepted:    275.1K
 * Total Submissions: 863.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        auto len = nums.size();

        // 1. len<4, no solution
        if (len < 4)
            return res;

        // 2. Sort to easily avoid duplicates
        sort(nums.begin(), nums.end());

        // 3. Iterates the array to get the res
        for (int i = 0; i < len - 3; i++)
        {
            // Avoid duplicates in a
            if (i >= 1 && nums[i] == nums[i - 1])
            {
                continue;
            }
            auto a = nums[i];

            find_bcd(nums, i, a, target, res);
        }

        return res;
    }

    void find_bcd(vector<int> &nums, int i, int a, int target, vector<vector<int>> &res)
    {
        vector<int> quad(4, 0);
        auto len = nums.size();
        // Find b, c, d
        for (int j = i + 1; j < len - 2; j++)
        {
            // Avoid duplicates in b
            if (j >= i + 2 && nums[j] == nums[j - 1])
                continue;

            auto b = nums[j];

            int l = j + 1;
            int r = len - 1;
            while (l < r)
            {
                int sum = a + b + nums[l] + nums[r];
                if (sum > target)
                    r--;
                else if (sum < target)
                    l++;
                else
                {
                    quad[0] = a;
                    quad[1] = b;
                    quad[2] = nums[l];
                    quad[3] = nums[r];

                    res.push_back(quad);

                    while (l < r && nums[l] == nums[l + 1])
                        l++;
                    while (l < r && nums[r] == nums[r - 1])
                        r--;
                    l++;
                    r--;
                }
            }
        }
    }
};
// @lc code=end
