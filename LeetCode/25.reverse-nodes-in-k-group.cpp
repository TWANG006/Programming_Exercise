/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int count = 0;
        ListNode *curr = head;

        while (count != k && curr != nullptr)
        {
            curr = curr->next;
            count++;
        }

        if (count == k)
        {
            curr = reverseKGroup(curr, k);

            while (count > 0)
            {
                // head->next --> curr, curr --> head, head --> head->next
                ListNode *next = head->next;
                head->next = curr;
                curr = head;
                head = next;
                count--;
            }

            // in order to use one return
            head = curr;
        }

        // no change needed, then return head
        return head;
    }
};
// @lc code=end
