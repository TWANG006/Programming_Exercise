/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;

        // mp[day][transactions][have stock or not]
        int mp[prices.size()][3][2];

        // initial state
        mp[0][0][0] = 0, mp[0][0][1] = -prices[0];
        mp[0][1][0] = -32768, mp[0][1][1] = -32768;
        mp[0][2][0] = -32768, mp[0][2][1] = -32768;

        // dp update
        for (int i = 1; i < prices.size(); i++)
        {
            mp[i][0][0] = mp[i - 1][0][0];
            mp[i][0][1] = max(mp[i - 1][0][1], mp[i - 1][0][0] - prices[i]);

            mp[i][1][0] = max(mp[i - 1][1][0], mp[i - 1][0][1] + prices[i]);
            mp[i][1][1] = max(mp[i - 1][1][1], mp[i - 1][1][0] - prices[i]);

            mp[i][2][0] = max(mp[i - 1][2][0], mp[i - 1][1][1] + prices[i]);
        }

        int end = prices.size() - 1;

        return max(max(mp[end][0][0], mp[end][1][0]), mp[end][2][0]);
    }
};
// @lc code=end

