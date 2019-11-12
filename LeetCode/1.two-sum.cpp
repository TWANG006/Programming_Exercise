/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (44.74%)
 * Likes:    12425
 * Dislikes: 434
 * Total Accepted:    2.3M
 * Total Submissions: 5.1M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers, return indices of the two numbers such that they
 * add up to a specific target.
 * 
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 * 
 * Example:
 * 
 * 
 * Given nums = [2, 7, 11, 15], target = 9,
 * 
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return vector<int>();

        vector<int> res(2,0);

        for(int i=0; i<nums.size(); i++){
            int sub = target - nums[i];
            auto it = elmMap.find(sub);
            if(it!=elmMap.end()){
                res[0] = it->second;
                res[1] = i;
            }
            else{
                elmMap[nums[i]] = i;
            }        
        }       

        return res;
    }

private:
    unordered_map<int, int> elmMap;
};
// @lc code=end

