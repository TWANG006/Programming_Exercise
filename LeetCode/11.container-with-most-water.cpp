/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

// @lc code=start
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int max_area = 0;

        while (l != r)
        {
            max_area = max(max_area, (r - l) * min(height[l], height[r]));

            if(height[l] < height[r])
                l++;
            else
                r--;
        }

        return max_area;
    }
};
// @lc code=end
