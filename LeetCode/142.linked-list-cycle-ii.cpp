/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        return Solution1(head);
    }

    // 1. Solution 1: using set, O(n), O(n)
    ListNode *Solution1(ListNode *head)
    {
        unordered_set<ListNode *> nodeSet;
        while (head != NULL)
        {
            if (nodeSet.find(head) != nodeSet.end())
            {
                return head;
            }
            else
            {
                nodeSet.insert(head);
            }
            head = head->next;
        }
        return NULL;
    }

    // 2. Solution 2: 
};
// @lc code=end
