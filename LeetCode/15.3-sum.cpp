/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.17%)
 * Likes:    4851
 * Dislikes: 578
 * Total Accepted:    695.7K
 * Total Submissions: 2.8M
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * Given an array nums of n integers, are there elements a, b, c in nums such
 * that a + b + c = 0? Find all unique triplets in the array which gives the
 * sum of zero.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate triplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> v3(3, 0);
        int len = nums.size();

        // 1. Return empty vector if nums.size() < 3
        if (len < 3)
            return res;

        // 2. Sort nums
        sort(nums.begin(), nums.end());        

        // 3. Scan nums & calculate
        for (int i = 0; i < len - 2; i++)
        {
            // 3.1 If the first element is >=0, no solution
            if (nums[i] > 0)
                return res;

            // 3.2 Skip duplicates in a
            if (i >= 1 && nums[i] == nums[i - 1])
            {
                continue;
            }

            // 3.3 General case: binary search b & c 
            int a = nums[i];
            int l = i + 1;
            int r = len - 1;
            while(l < r)
            {
                int sum = a + nums[l] + nums[r];
                if(sum > 0) r--;
                else if(sum < 0) l++;
                else
                {
                    v3[0] = a; 
                    v3[1] = nums[l];
                    v3[2] = nums[r];
                    res.push_back(v3);

                    // Avoid duplicates in b & c
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    
                    l++;
                    r--;
                }
            }
        }

        return res;
    }

    /* Map implementation, 311 failed due to time limit exceeded.*/
    // vector<vector<int>> threeSum_map(vector<int> &nums)
    // {
    //     if (nums.size() < 3)
    //         return vector<vector<int>>();

    //     // 1. Sort the nums to avoid repeat evaluation
    //     set<vector<int>> set_res;
    //     sort(nums.begin(), nums.end());

    //     for (int i = 0; i < nums.size() - 2; i++)
    //     {
    //         if (i >= 1 && nums[i - 1] == nums[i])
    //         {
    //             continue;
    //         }
    //         int a = nums[i];
    //         unordered_set<int> abset;
    //         for (int j = i + 1; j < nums.size(); j++)
    //         {
    //             auto it = abset.find(nums[j]);
    //             if (it == abset.end())
    //             {
    //                 abset.insert(-a - nums[j]);
    //             }
    //             else
    //             {
    //                 set_res.insert(vector<int>{a, -a - nums[j], nums[j]});
    //             }
    //         }
    //     }

    //     return vector<vector<int>>(set_res.begin(), set_res.end());
    // }
};
// @lc code=end
