/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/description/
 *
 * algorithms
 * Medium (39.26%)
 * Likes:    1696
 * Dislikes: 183
 * Total Accepted:    263.4K
 * Total Submissions: 669.8K
 * Testcase Example:  '[1,2,3,4,5,null,7]'
 *
 * Given a binary tree
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Follow up:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, you may assume implicit stack space does not
 * count as extra space for this problem.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A), your function should
 * populate each next pointer to point to its next right node, just like in
 * Figure B. The serialized output is in level order as connected by the next
 * pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 6000.
 * -100 <= node.val <= 100
 * 
 * 
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

/*--------DFS-----------*/
// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         if (!root)
//             return NULL;

//         // 1. both left&right have
//         if (root->left && root->right)
//             root->left->next = root->right;

//         // 2. inter connection
//         else if (root->left)
//         {
//             root->left->next = Next(root->next);
//         }

//         if (root->right)
//         {
//             root->right->next = Next(root->next);
//         }

//         connect(root->right);
//         connect(root->left);

//         return root;
//     }

//     Node *Next(Node *root)
//     {
//         if (!root)
//             return NULL;

//         while (root && !root->left && !root->right)
//             root = root->next;

//         return root ? (root->left ? root->left : root->right) : NULL;
//     }
// };

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        Node *curLevel = root;
        Node *endLevel = root;
        Node *endWhole = root;

        while (curLevel)
        {
            if (curLevel->left)
            {
                endWhole->next = curLevel->left;
                endWhole = endWhole->next;
            }
            if (curLevel->right)
            {
                endWhole->next = curLevel->right;
                endWhole = endWhole->next;
            }
            if(curLevel == endLevel)
            {
                curLevel = curLevel->next;
                endLevel->next = NULL;
                endLevel = endWhole;
            }
            else
            {
                curLevel = curLevel->next;
            }            
        }

        return root;
    }
};
// @lc code=end
