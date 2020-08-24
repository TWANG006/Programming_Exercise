/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (47.30%)
 * Likes:    1976
 * Dislikes: 38
 * Total Accepted:    247.4K
 * Total Submissions: 522.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * inorder = [9,3,15,20,7]
 * postorder = [9,15,7,20,3]
 * 
 * Return the following binary tree:
 * 
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inMap);
    }

    TreeNode *buildTree(
        vector<int> &inorder, int inStart, int inEnd,
        vector<int> &postorder, int postStart, int postEnd,
        unordered_map<int, int> &inMap)
    {
        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        TreeNode *root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int num_left_nodes = inRoot - inStart;

        root->left = buildTree(inorder, inStart, inRoot - 1, postorder, postStart, postStart + num_left_nodes - 1, inMap);
        root->right = buildTree(inorder, inRoot + 1, inEnd, postorder, postStart + num_left_nodes, postEnd - 1, inMap);

        return root;
    }

private:
    unordered_map<int, int> inMap;
};
// @lc code=end
