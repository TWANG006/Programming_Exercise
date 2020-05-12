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
        return Solution2(head);
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
    ListNode *Solution2(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        bool hasCycle = false;

        while (slow != NULL && fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (fast == slow)
            {
                hasCycle = true;
                break;
            }
        }

        if (!hasCycle)
            return NULL;

        slow = head;

        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};
// @lc code=end
