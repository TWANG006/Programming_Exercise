/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int x = 2;
        int y = 1;
        int r = 0;

        for(int i = 3; i <= n; i++)
        {
            r = x + y;
            y = x;
            x = r;
        }

        return r;
    }
};
// @lc code=end
