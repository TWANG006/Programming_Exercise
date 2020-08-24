/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
 *
 * https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (48.98%)
 * Likes:    3692
 * Dislikes: 100
 * Total Accepted:    380.9K
 * Total Submissions: 776.4K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * For example, given
 * 
 * 
 * preorder = [3,9,20,15,7]
 * inorder = [9,3,15,20,7]
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            inMap.insert({{inorder[i], i}});
        }

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

    /*
    1. Right nodes of node N in a pre-order traversal is the left sub-tree of N of left + right or 
       right sub-tree of N, so the structure cannot be uniquely determined.
    2. Left nodes of node N in a in-order traversal is the left sub-tree of N while the right nodes 
       of node N is the right sub-tree.
    3. Use 1 & 2, the binary tree can be uniquely constructed: number of the left nodes in pre-order 
       should be equal to those in the in-order
    4. Assume no duplicates means we can use Hash table as a buffer always.
    */
    TreeNode *buildTree(
        vector<int> &preorder, int preStart, int preEnd,
        vector<int> &inorder, int inStart, int inEnd,
        unordered_map<int, int> &inMap)
    {
        // already at the leaves
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        // create the root node
        TreeNode *root = new TreeNode(preorder[preStart]);

        // calculate the number of left and right nodes of the root
        int inRootId = inMap[root->val];
        int num_left_nodes = inRootId - inStart;

        // visit the left and right subtree
        root->left = buildTree(preorder, preStart + 1, preStart + num_left_nodes, inorder, inStart, inRootId - 1, inMap);
        root->right = buildTree(preorder, preStart + 1 + num_left_nodes, preEnd, inorder, inRootId + 1, inEnd, inMap);

        return root;
    }

private:
    unordered_map<int, int> inMap;
};
// @lc code=end
