/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (66.33%)
 * Likes:    496
 * Dislikes: 1362
 * Total Accepted:    68.4K
 * Total Submissions: 103.3K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        
        /*
        base case: dp[1] = false;
        state transfer:
        dp[i] = i % x && !dp[i - x]
        */
        vector<bool> dp(N+1, false);
                
        for(int i=2; i<=N; i++)
        {
            for(int j=1; j<=i/2; j++)
            {
                if (i%j==0 && !dp[i - j])
                    dp[i] = true;
            }
        }
        
        return dp[N];
    }
};
// @lc code=end

