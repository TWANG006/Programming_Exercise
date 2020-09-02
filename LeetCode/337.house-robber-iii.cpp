/*
 * @lc app=leetcode id=337 lang=cpp
 *
 * [337] House Robber III
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
    int rob(TreeNode* root) {
        if(root==nullptr) return 0;
        
        stack<TreeNode*> s;
        s.push(root);
        unordered_set<TreeNode*> visited;
        unordered_map<TreeNode*, int> money;
        money[nullptr] = 0;
        
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
                money[cur] = 
                    max(money[cur->left] + money[cur->right], 
                       cur->val + (cur->left==nullptr?0: (money[cur->left->left] + money[cur->left->right])) + (cur->right==nullptr?0:(money[cur->right->left] + money[cur->right->right])));
                visited.insert(cur);
            }
        }
                        
        return money[root];
    }
};
// @lc code=end

