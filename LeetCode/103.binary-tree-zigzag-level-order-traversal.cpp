/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (48.38%)
 * Likes:    2371
 * Dislikes: 103
 * Total Accepted:    398.8K
 * Total Submissions: 823.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the zigzag level order traversal of its nodes'
 * values. (ie, from left to right, then right to left for the next level and
 * alternate between).
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
 * return its zigzag level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        /*--Idea: BFS of the tree with order in each level controlled by 
        the paramter isLeft2Right--*/
        if (root == nullptr)
            return vector<vector<int>>();

        bool isLeft2Right = true;

        // BFS of the tree based on isLeft2Right param
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            auto level_size = q.size();
            vector<int> curr_level(level_size, 0);

            for (int i = 0; i < level_size; i++)
            {
                TreeNode *curr = q.front();
                q.pop();

                int id = isLeft2Right ? i : level_size - i - 1;
                curr_level[id] = curr->val;
                
                if(curr->left!=nullptr) q.push(curr->left);
                if(curr->right!=nullptr) q.push(curr->right);              
            }
            
            res.push_back(curr_level);
            isLeft2Right = !isLeft2Right;
        }

        return res;
    }
};
// @lc code=end
