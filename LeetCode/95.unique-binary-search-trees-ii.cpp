/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>();

        return helper(1, n);
    }

    vector<TreeNode *> helper(int start, int end)
    {
        if (start > end)
            return vector<TreeNode *>{nullptr};

        vector<TreeNode *> res;

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> left, right;

            left = helper(start, i - 1);
            right = helper(i + 1, end);

            for (auto &j : left)
            {
                for (auto &k : right)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = j;
                    root->right = k;

                    res.emplace_back(root);
                }
            }
        }

        return res;
    }
};
// @lc code=end
