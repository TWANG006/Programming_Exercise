/*
 * @lc app=leetcode id=501 lang=cpp
 *
 * [501] Find Mode in Binary Search Tree
 *
 * https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
 *
 * algorithms
 * Easy (42.42%)
 * Likes:    969
 * Dislikes: 356
 * Total Accepted:    89.9K
 * Total Submissions: 211.5K
 * Testcase Example:  '[1,null,2,2]'
 *
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the
 * most frequently occurred element) in the given BST.
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than or equal
 * to the node's key.
 * The right subtree of a node contains only nodes with keys greater than or
 * equal to the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * For example:
 * Given BST [1,null,2,2],
 * 
 * 
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  2
 * 
 * 
 * 
 * 
 * return [2].
 * 
 * Note: If a tree has more than one mode, you can return them in any order.
 * 
 * Follow up: Could you do that without using any extra space? (Assume that the
 * implicit stack space incurred due to recursion does not count).
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
    vector<int> findMode(TreeNode* root) {
        if(not root) return vector<int>();
        
        vector<int> res;
        int prev = 0, cnt = 0, maxFreq = INT_MIN;
        
        inOrder(root, res, prev, cnt, maxFreq);
        
        return res;
    }
    
    void inOrder(TreeNode* root, vector<int>& res, int& prev, int& cnt, int& maxFreq)
    {
        if(root==nullptr) return;
        
        inOrder(root->left, res, prev, cnt, maxFreq);
        
        if(root->val == prev) ++cnt;
        else cnt = 1;
        
        if(cnt > maxFreq)
        {
            res.clear();
            res.push_back(root->val);
            maxFreq = cnt;
        }
        if(cnt == maxFreq)
        {
            if(root->val != res.back())
                res.push_back(root->val);
        }
        
        prev = root->val;
        
        inOrder(root->right, res, prev, cnt, maxFreq);
    }
};
// @lc code=end

