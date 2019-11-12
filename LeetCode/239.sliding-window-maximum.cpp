/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (39.91%)
 * Likes:    2264
 * Dislikes: 134
 * Total Accepted:    198.8K
 * Total Submissions: 498.2K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // If nums is empty, return an empty vector
        if (nums.empty()) return vector<int>();

        deque<int> window;  // Use double-sided queue to maintain the largest number in the front
        vector<int> res;    // Used to store the results

        for(int i=0; i<nums.size(); i++){
            // If window is empty, just push_back the first element
            if(window.empty()) window.push_back(i);
            else{
                // If the front id is out of range, pop it
                if(i>=k && window.front()<=i-k){
                    window.pop_front();
                }
                // Keep the front as the max. Pop any existing element that are less than the new element
                while(!window.empty() && nums[window.back()]<=nums[i]){
                    window.pop_back();
                }
                // Push_back the new element
                window.push_back(i);
            }
            // Release the result after k steps
            if(i>=k-1) res.push_back(nums[window.front()]);
        }
        return res;
    }
};
// @lc code=end

