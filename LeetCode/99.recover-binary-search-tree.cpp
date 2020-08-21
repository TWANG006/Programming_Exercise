/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (39.78%)
 * Likes:    1661
 * Dislikes: 77
 * Total Accepted:    169.5K
 * Total Submissions: 426.2K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
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

/* O(n) space solution with in-order traversal*/
// class Solution
// {
// public:
//     void recoverTree(TreeNode *root)
//     {
//         TreeNode *s=nullptr, *t = nullptr, *prev = new TreeNode(INT_MIN);
//         inOrder(root, prev, s, t);
//         swap(s->val, t->val);
//     }

//     void inOrder(TreeNode* cur, TreeNode*& prev, TreeNode*& s, TreeNode*& t)
//     {
//         if (cur == nullptr) return;
//         inOrder(cur->left, prev, s, t);
//         if(cur->val < prev->val) s = s==nullptr? prev:s, t = cur;
//         prev = cur;
//         inOrder(cur->right, prev, s, t);
//     }

/*O(1) space solution with Morris in-order traverse*/
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        if (root == nullptr)
            return;

        TreeNode *s = nullptr, *t = nullptr;

        MorrisInOrder(root, s, t);
        swap(s->val, t->val);
    }

    void MorrisInOrder(TreeNode *cur, TreeNode *&s, TreeNode *&t)
    {
        TreeNode *prev = new TreeNode(INT_MIN);

        while (cur != nullptr)
        {
            // Find the rightmost node of the left subtree
            if (cur->left != nullptr)
            {
                TreeNode *tmp = cur->left;
                while (tmp->right != nullptr && tmp->right != cur)
                {
                    tmp = tmp->right;
                }
                if (tmp->right == nullptr)
                {
                    tmp->right = cur;
                    cur = cur->left;
                }
                else
                {
                    tmp->right = nullptr;
                    /*deal with the cur node*/
                    if (prev->val > cur->val)
                    {
                        s = s == nullptr ? prev : s, t = cur;
                    }
                    prev = cur;
                    cur = cur->right;
                }
            }
            else
            {
                /*deal with the cur node*/
                if (prev->val > cur->val)
                {
                    s = s == nullptr ? prev : s, t = cur;
                }
                prev = cur;
                cur = cur->right;
            }
        }
    }
};
// @lc code=end
