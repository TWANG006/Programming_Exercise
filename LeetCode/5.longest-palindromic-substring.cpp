/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution
{
public:
    string longestPalindrome(string s)
    {
        vector<vector<bool>> p(s.size(), vector<bool>(s.size(), false));

        if (s.size() < 2)
            return s;

        
        int len = 1, start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            for (int y = i; y < s.size(); y++)
            {
                int x = y - i;

                if (x == y)
                    p[x][y] = true;
                else if (x == y - 1)
                    p[x][y] = (s[x] == s[y]);
                else
                    p[x][y] = (s[x] == s[y]) && p[x + 1][y - 1];

                if (p[x][y] && (y - x + 1 > len))
                {
                    start = x;
                    len = y - x + 1;
                }
            }
        }

        return s.substr(start, len);
    }
};
// @lc code=end
