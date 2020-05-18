/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> res;
//        recursiveSolution(root, res);
        iterativeSolution(root, res);

        return res;
    }
    
    /* Solution 2: iterative solution using stack*/
    void iterativeSolution(TreeNode* root, vector<int>& res)
    {
        stack<TreeNode*> sNode;

        while(root!=nullptr || !sNode.empty())
        {
            while (root != nullptr)
            {
                sNode.push(root);
                root = root->left;
            }
            root = sNode.top();
            sNode.pop();
            res.push_back(root->val);
            root = root->right;
        }
    }

    /* Solution 1: recursion*/
    void recursiveSolution(TreeNode* root, vector<int>& res)
    {
        if (root != nullptr)
        {
            if (root->left != nullptr)
            {
                recursiveSolution(root->left, res);
            }
            res.push_back(root->val);

            if(root->right!=nullptr)
            {
                recursiveSolution(root->right, res);
            }
        }
    }
};
// @lc code=end
