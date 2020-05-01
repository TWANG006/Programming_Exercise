/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> res(triangle[n - 1]);

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                res[j] = triangle[i][j] + min(res[j], res[j + 1]);
            }
        }

        return res[0];
    }
};
// @lc code=end
