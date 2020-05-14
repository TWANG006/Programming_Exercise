/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        return Solution1(S, T);
    }

    // Solution 1: using stack, time O(N), space O(N)
    bool Solution1(string &S, string &T)
    {
        stack<char> sS;
        stack<char> sT;

        for (auto &i : S)
        {
            if (!sS.empty() && i == '#')
                sS.pop();
            else if (i != '#')
                sS.push(i);
        }

        for (auto &i : T)
        {
            if (!sT.empty() && i == '#')
                sT.pop();
            else if (i != '#')
                sT.push(i);
        }

        return sS == sT;
    }
};
// @lc code=end
