/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        auto n = prices.size();

        if (n == 0)
            return 0;

        // O(n), O(1) solution
        int buy = INT_MIN;
        int sell_1 = 0, sell_2 = 0;

        for (auto &i : prices)
        {
            buy = max(buy, sell_2 - i);
            sell_2 = sell_1;
            sell_1 = max(sell_1, buy + i);
        }

        return sell_1;

        // O(n), O(n) solution
        // vector<int> buy(n, 0);
        // vector<int> sell(n, 0);
        // buy[0] = -prices[0];

        //        for (int i = 1; i < n; i++)
        // {
        //     sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
        //     buy[i] = max(buy[i - 1], i >= 2 ? sell[i - 2] - prices[i] : -prices[i]);
        // }

        // return sell[n - 1];        
    }
};
// @lc code=end
