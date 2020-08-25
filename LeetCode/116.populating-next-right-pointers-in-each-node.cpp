/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (45.41%)
 * Likes:    2193
 * Dislikes: 145
 * Total Accepted:    379.1K
 * Total Submissions: 833K
 * Testcase Example:  '[1,2,3,4,5,6,7]'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
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
 * Input: root = [1,2,3,4,5,6,7]
 * Output: [1,#,2,3,#,4,5,6,7,#]
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B. The serialized output is in level order as connected by the
 * next pointers, with '#' signifying the end of each level.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the given tree is less than 4096.
 * -1000 <= node.val <= 1000
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

/*--------Two pointer solution-----------*/
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;

        Node* p = root;
        Node* q = NULL;

        while(p->left)
        {
            q = p;
            while(q)
            {
                q->left->next = q->right;

                if(q->next)
                    q->right->next = q->next->left;

                q = q->next;
            }

            p = p->left;
        }

        return root;
    }
};

/*------DFS solution uses implicit stack--------*/
// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         if (!root)
//             return root;

//         if (root->left && root->right)
//             root->left->next = root->right;
//         if(root->next && root->left)
//             root->right->next = root->next->left;
        
//         if(root->left) connect(root->left);
//         if (root->right)
//             connect(root->right);
        
//         return root;
//     }
// };

/*-------BFS is straightforward, but requires O(n) space--------*/
// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         if (root == nullptr)
//             return root;

//         queue<Node *> q;
//         q.push(root);

//         while (!q.empty())
//         {
//             int level_size = q.size();

//             for (int i = 0; i < level_size; i++)
//             {
//                 Node *cur = q.front();
//                 q.pop();

//                 if (i == level_size - 1)
//                     cur->next = NULL;
//                 else
//                     cur->next = q.front();

//                 if (cur->left)
//                     q.push(cur->left);
//                 if (cur->right)
//                     q.push(cur->right);
//             }
//         }

//         return root;
//     }
// };
// @lc code=end
