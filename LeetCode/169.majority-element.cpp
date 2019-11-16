/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 *
 * https://leetcode.com/problems/majority-element/description/
 *
 * algorithms
 * Easy (54.76%)
 * Likes:    2122
 * Dislikes: 184
 * Total Accepted:    461.1K
 * Total Submissions: 841.4K
 * Testcase Example:  '[3,2,3]'
 *
 * Given an array of size n, find the majority element. The majority element is
 * the element that appears more than ⌊ n/2 ⌋ times.
 * 
 * You may assume that the array is non-empty and the majority element always
 * exist in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,2,3]
 * Output: 3
 * 
 * Example 2:
 * 
 * 
 * Input: [2,2,1,1,1,2,2]
 * Output: 2
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = nums.size() / 2;

        for(auto &i : nums)
        {
            cMap[i] += 1;
            if(cMap[i] > count)
                return i;
        }

        return -1;
    }

private:
    unordered_map<int, int> cMap;
};
// @lc code=end

