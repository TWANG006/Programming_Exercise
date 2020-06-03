/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution
{
public:
    int myAtoi(string str)
    {
        int res = 0;
        stringstream ss;
        ss << str;
        ss >> res;

        return res;
    }
};
// @lc code=end
