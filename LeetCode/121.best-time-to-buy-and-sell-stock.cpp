/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if (prices.size() == 0)
            return 0;

        int res = 0;
        int min_price = prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] - min_price > res)
                res = prices[i] - min_price;

            if (prices[i] < min_price)
                min_price = prices[i];
        }

        return res;
    }
};
// @lc code=end

