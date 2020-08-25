/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return res;

        helper(root, sum);
        return res;
    }

    void helper(TreeNode *root, int sum)
    {
        if (root == nullptr)
            return;

        cur.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr && root->val == sum)
        {
            res.push_back(cur);
        }

        helper(root->left, sum - root->val);
        helper(root->right, sum - root->val);

        cur.pop_back();
    }

private:
    vector<vector<int>> res;
    vector<int> cur;
};
// @lc code=end
