/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        unordered_map<char, char> lr({{')', '('},
                                      {']', '['},
                                      {'}', '{'}});
        stack<char> cstack;

        for (auto &i : s)
        {
            if (lr.find(i) == lr.end())
            {
                cstack.push(i);
            }
            else if (!cstack.empty() && lr[i] == cstack.top())
            {
                cstack.pop();
            }
            else
                return false;
        }

        return cstack.empty();
    }
};
// @lc code=end
