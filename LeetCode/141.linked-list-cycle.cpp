/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head)
    {
        // return Solution1(head);
        return Solution2(head);
    }

    // 1. Solution 1: using set & find
    bool Solution1(ListNode *head)
    {
        unordered_set<ListNode *> nodeSet;

        while (head != NULL)
        {
            if (nodeSet.find(head) != nodeSet.end())
                return true;
            else
            {
                nodeSet.insert(head);
            }
            head = head->next;
        }

        return false;
    }

    // 2. Solution 2: using detect cycle
    bool Solution2(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// @lc code=end
