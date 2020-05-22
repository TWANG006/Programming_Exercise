/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode *root)
    {
        // return solution1(root, root);
        return solution2(root);
    }

    /*Solution 1: recursion*/
    bool solution1(TreeNode *tree1, TreeNode *tree2)
    {
        if (tree1 == nullptr && tree2 == nullptr)
            return true;
        else if (tree1 == nullptr || tree2 == nullptr)
            return false;
        else
        {
            return (tree1->val == tree2->val) && solution1(tree1->right, tree2->left) && solution1(tree1->left, tree2->right);
        }
    }

    /*Solution 2: iteration*/
    bool solution2(TreeNode *root)
    {
        queue<TreeNode *> nodeQ;

        nodeQ.push(root);
        nodeQ.push(root);

        while (!nodeQ.empty())
        {
            TreeNode *tree1 = nodeQ.front(); nodeQ.pop();
            TreeNode *tree2 = nodeQ.front(); nodeQ.pop();

            if (tree1 == nullptr && tree2 == nullptr)
                continue;
            if (tree1 == nullptr || tree2 == nullptr)
                return false;
            if (tree1->val != tree2->val)
                return false;

            nodeQ.push(tree1->left);
            nodeQ.push(tree2->right);
            nodeQ.push(tree1->right);
            nodeQ.push(tree2->left);
        }

        return true;
    }
};
// @lc code=end
