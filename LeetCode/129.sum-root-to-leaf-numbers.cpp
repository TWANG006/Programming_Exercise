/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
 *
 * https://leetcode.com/problems/sum-root-to-leaf-numbers/description/
 *
 * algorithms
 * Medium (49.16%)
 * Likes:    1629
 * Dislikes: 43
 * Total Accepted:    284.2K
 * Total Submissions: 577.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path
 * could represent a number.
 * 
 * An example is the root-to-leaf path 1->2->3 which represents the number
 * 123.
 * 
 * Find the total sum of all root-to-leaf numbers.
 * 
 * Note: A leaf is a node with no children.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * Output: 25
 * Explanation:
 * The root-to-leaf path 1->2 represents the number 12.
 * The root-to-leaf path 1->3 represents the number 13.
 * Therefore, sum = 12 + 13 = 25.
 * 
 * Example 2:
 * 
 * 
 * Input: [4,9,0,5,1]
 * ⁠   4
 * ⁠  / \
 * ⁠ 9   0
 * / \
 * 5   1
 * Output: 1026
 * Explanation:
 * The root-to-leaf path 4->9->5 represents the number 495.
 * The root-to-leaf path 4->9->1 represents the number 491.
 * The root-to-leaf path 4->0 represents the number 40.
 * Therefore, sum = 495 + 491 + 40 = 1026.
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

/*-----------DFS: need a partialSum to track each level's result-------------*/
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        return helper(root, 0);
    }

    int helper(TreeNode *root, int partialSum)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr)
            return partialSum * 10 + root->val;

        return (helper(root->left, partialSum * 10 + root->val) + helper(root->right, partialSum * 10 + root->val));
    }
};

/*-----------BFS------------*/
// class Solution
// {
// public:
//     int sumNumbers(TreeNode *root)
//     {
//         if (root == nullptr)
//             return 0;

//         int sum = 0;
//         queue<pair<TreeNode*, int>> q;
//         q.push(make_pair(root, root->val));
        
//         while(!q.empty())
//         {
//             pair<TreeNode*, int> cur = q.front();
//             q.pop();

//             if(cur.first->left==nullptr && cur.first->right==nullptr)
//                 sum += cur.second;
            
//             if(cur.first->left!=nullptr)
//                 q.push({cur.first->left, (cur.second * 10 + cur.first->left->val)});
//             if(cur.first->right!=nullptr)
//                 q.push({cur.first->right, (cur.second * 10 + cur.first->right->val)});
//         }        

//         return sum;
//     }
// };

// @lc code=end
