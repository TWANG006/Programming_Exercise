/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> res(n + 1, 0);

        res[0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                res[i] += res[j] * res[i - j - 1];
            }
        }

        return res[n];
    }
};
// @lc code=end
