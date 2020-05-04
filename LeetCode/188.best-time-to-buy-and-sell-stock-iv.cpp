/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        if (k > prices.size() / 2)
        {
            int max_profit = 0 ;
            for (int i = 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[i - 1])
                    max_profit += prices[i] - prices[i - 1];
            }

            return max_profit;
        }

        vector<vector<int>> mp(prices.size(), vector<int>(k + 1, 0));
        int max_profit = 0;

        for (int j = 1; j <= k; j++)
        {
            int temp = mp[0][j - 1] - prices[0];

            for (int i = 1; i < prices.size(); i++)
            {               
                temp = max(temp, mp[i][j - 1] - prices[i]);
                mp[i][j] = max(mp[i - 1][j], temp + prices[i]);
            }
        }
        // vector<vector<vector<int>>> mp(prices.size(), vector<vector<int>>(k + 1, vector<int>(2, -32768)));

        // mp[0][0][0] = 0;    mp[0][0][1] = - prices[0];

        // int max_profit = 0;
        // for (int i = 1; i < prices.size(); i++)
        // {
        //     for (int j = 0; j <= k; j++)
        //     {
        //         mp[i][j][0] = j == 0 ? mp[i - 1][0][0] : max(mp[i - 1][j][0], mp[i - 1][j - 1][1] + prices[i]);
        //         mp[i][j][1] = max(mp[i - 1][j][1], mp[i - 1][j][0] - prices[i]);
        //         max_profit = max(max_profit, mp[prices.size() - 1][j][0]);
        //     }
        // }

        return mp[prices.size() - 1][k];
    }
};
// @lc code=end
