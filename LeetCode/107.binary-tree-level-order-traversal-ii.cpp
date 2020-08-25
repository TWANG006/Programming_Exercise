/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
 *
 * algorithms
 * Easy (53.63%)
 * Likes:    1590
 * Dislikes: 217
 * Total Accepted:    364.7K
 * Total Submissions: 679.4K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the bottom-up level order traversal of its
 * nodes' values. (ie, from left to right, level by level from leaf to root).
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
 * return its bottom-up level order traversal as:
 * 
 * [
 * ⁠ [15,7],
 * ⁠ [9,20],
 * ⁠ [3]
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int depth(TreeNode *root)
    {
        return root == nullptr ? 0 : max(depth(root->left), depth(root->right)) + 1;
    }

    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr)
            return vector<vector<int>>();

        int id = depth(root) - 1;
        vector<vector<int>> res(id + 1, vector<int>());

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int level_num = q.size();

            vector<int> curLayer(level_num, 0);
            for (int i = 0; i < level_num; i++)
            {
                TreeNode *cur = q.front();
                q.pop();
                curLayer[i] = cur->val;

                if (cur->left != nullptr)
                    q.push(cur->left);
                if (cur->right != nullptr)
                    q.push(cur->right);
            }
            res[id] = curLayer;
            id--;
        }

        return res;
    }
};
// @lc code=end
