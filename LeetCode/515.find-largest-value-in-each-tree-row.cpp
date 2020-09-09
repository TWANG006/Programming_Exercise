/*
 * @lc app=leetcode id=515 lang=cpp
 *
 * [515] Find Largest Value in Each Tree Row
 *
 * https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
 *
 * algorithms
 * Medium (61.16%)
 * Likes:    978
 * Dislikes: 65
 * Total Accepted:    109.1K
 * Total Submissions: 177.8K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given the root of a binary tree, return an array of the largest value in
 * each row of the tree (0-indexed).
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [1,3,2,5,3,null,9]
 * Output: [1,3,9]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [1,2,3]
 * Output: [1,3]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: root = [1]
 * Output: [1]
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: root = [1,null,2]
 * Output: [1,2]
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: root = []
 * Output: []
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree will be in the range [0, 10^4].
 * -2^31 <= Node.val <= 2^31 - 1
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
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr) return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> res;
        
        while(!q.empty())
        {
            int max_per_row = INT_MIN;
            int level_sz = q.size();
            
            for(int i=0; i<level_sz; i++)
            {
                TreeNode* cur = q.front();
                q.pop();
                
                max_per_row = max(max_per_row, cur->val);
                
                if(cur->left!=nullptr) q.push(cur->left);
                if(cur->right!=nullptr) q.push(cur->right);
            }
            
            res.push_back(max_per_row);
        }
        
        return res;
    }
};
// @lc code=end

