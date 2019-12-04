/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (50.85%)
 * Likes:    1992
 * Dislikes: 55
 * Total Accepted:    471.9K
 * Total Submissions: 923.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return vector<vector<int>>();

        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto level_size = q.size();
            vector<int> curr_level;

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *tmpNode = q.front();
                q.pop();
                curr_level.push_back(tmpNode->val);
                if (tmpNode->left!=NULL) q.push(tmpNode->left);
                if (tmpNode->right!=NULL) q.push(tmpNode->right);
            }
            res.push_back(curr_level);
        }

        return res;
    }
};
// @lc code=end
