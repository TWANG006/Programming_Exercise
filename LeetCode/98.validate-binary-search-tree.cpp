/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
 *
 * https://leetcode.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (26.62%)
 * Likes:    2612
 * Dislikes: 382
 * Total Accepted:    510.1K
 * Total Submissions: 1.9M
 * Testcase Example:  '[2,1,3]'
 *
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * 
 * The left subtree of a node contains only nodes with keys less than the
 * node's key.
 * The right subtree of a node contains only nodes with keys greater than the
 * node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 
 * Input: [2,1,3]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 
 * Input: [5,1,4,null,null,3,6]
 * Output: false
 * Explanation: The root node's value is 5 but its right child's value is 4.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;

        long int min = (1 << 31); min = min -1;
        long int max = (1 << 31) - 1; max = max +1;

       return isValidBST_property(root, min, max);
    }

    /* Method 2: Use the property of the binary-search-tree*/
    bool isValidBST_property(TreeNode *root, long long int min, long long int max)
    {
        if (root == NULL)
            return true;
        if (min >= root->val)
            return false;
        if (max <= root->val)
            return false;
        return isValidBST_property(root->left, min, root->val) && isValidBST_property(root->right, root->val, max);
    }

    /* Method 1: in-order traverse the tree to see if the returned array is in ascend order*/
    // bool isValidBST_inorder(TreeNode *root)
    // {
    //     vector<int> traversed;

    //     if (root)
    //     {
    //         inOrder(root, traversed);
    //         set<int> unique_elms(traversed.begin(), traversed.end());
    //         if (traversed == vector<int>(unique_elms.begin(), unique_elms.end()))
    //             return true;
    //         else
    //             return false;
    //     }
    //     else
    //     {
    //         return true;
    //     }
        
    // }
    // void inOrder(TreeNode *root, vector<int>& traversed)
    // {
    //     if (root)
    //     {
    //         inOrder(root->left);
    //         traversed.push_back(root->val);
    //         inOrder(root->right);
    //     }
    // }
};
// @lc code=end
