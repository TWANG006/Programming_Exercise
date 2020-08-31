/*
 * @lc app=leetcode id=257 lang=cpp
 *
 * [257] Binary Tree Paths
 *
 * https://leetcode.com/problems/binary-tree-paths/description/
 *
 * algorithms
 * Easy (51.56%)
 * Likes:    1880
 * Dislikes: 112
 * Total Accepted:    331.6K
 * Total Submissions: 641.3K
 * Testcase Example:  '[1,2,3,null,5]'
 *
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input:
 * 
 * ⁠  1
 * ⁠/   \
 * 2     3
 * ⁠\
 * ⁠ 5
 * 
 * Output: ["1->2->5", "1->3"]
 * 
 * Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        
        if(root==nullptr) return res;
        
        helper(res, "", root);
        
        return res;
    }
    
    void helper(vector<string>& res, string path, TreeNode* root)
    {        
        if(root->left==nullptr && root->right==nullptr) res.push_back(path + to_string(root->val));
        if(root->left!=nullptr) helper(res, path + to_string(root->val) +"->", root->left);
        if(root->right!=nullptr) helper(res, path + to_string(root->val) +"->", root->right);
    }
};
// @lc code=end

