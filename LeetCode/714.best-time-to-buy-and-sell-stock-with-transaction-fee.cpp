/*
 * @lc app=leetcode id=714 lang=cpp
 *
 * [714] Best Time to Buy and Sell Stock with Transaction Fee
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int buy = -prices[0], sell = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            sell = max(buy + prices[i] - fee, sell);
            buy = max(sell - prices[i], buy);
        }

        return sell;
    }
};
// @lc code=end
