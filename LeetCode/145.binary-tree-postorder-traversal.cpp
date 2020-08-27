/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        
        if(root==nullptr)
            return res;
        
        stack<TreeNode*> s;
        s.push(root);
        unordered_set<TreeNode*> visited;
        
        while(!s.empty())
        {
            TreeNode* cur = s.top();
            if(nullptr!=cur->left && visited.find(cur->left)==visited.end())
            {
                s.push(cur->left);
            }
            else if(nullptr!=cur->right && visited.find(cur->right)==visited.end())
            {    
                s.push(cur->right);
            }
            else
            {
                s.pop();
                res.push_back(cur->val);
                visited.insert(cur);
            }
        }
        
        return res;
    }
};
// @lc code=end

