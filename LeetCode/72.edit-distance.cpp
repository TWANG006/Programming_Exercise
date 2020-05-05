/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        /*dp[i][j]: the minimum edits making the first i characters in word1 coincide with
        the first j characters in word2*/
        auto m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(min(dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1),
                                   dp[i - 1][j] + 1),
                               dp[i][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

