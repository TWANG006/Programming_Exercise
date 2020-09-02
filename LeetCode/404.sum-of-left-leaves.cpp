/*
 * @lc app=leetcode id=404 lang=cpp
 *
 * [404] Sum of Left Leaves
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==nullptr) return 0;
        
        stack<TreeNode*> s;
        unordered_set<TreeNode*> visited;
        
        s.push(root);
        
        int res = 0;
        
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            
            if(cur->left!=nullptr && visited.find(cur->left)==visited.end())
            {
                if(cur->left->left==nullptr && cur->left->right==nullptr)
                    res += cur->left->val;
                
                s.push(cur->left);
            }
            else if(cur->right!=nullptr && visited.find(cur->right)==visited.end())
            {
                s.push(cur->right);
            }
            else
            {
                s.pop();
                visited.insert(cur);
            }
        }
        
        return res;
    }
};
// @lc code=end

