/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

// @lc code=start
class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int min_diff = INT_MAX;
        int res = 0;

        auto len = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < len - 2; i++)
        {
            int a = nums[i];

            int l = i + 1;
            int r = len - 1;

            while (l < r)
            {
                int sum = a + nums[l] + nums[r];
                if (sum == target)
                    return target;
                else if(sum>target)
                    r--;
                else
                    l++;

                int diff = abs(sum - target);

                if (diff < min_diff)
                {
                    min_diff = diff;
                    res = sum;
                }
            }
        }

        return res;
    }
};
// @lc code=end
