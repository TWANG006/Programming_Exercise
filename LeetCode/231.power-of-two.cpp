/*
 * @lc app=leetcode id=231 lang=cpp
 *
 * [231] Power of Two
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        // NOTE: Order of operands
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
// @lc code=end

