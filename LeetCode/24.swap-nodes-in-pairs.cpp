/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    ListNode *swapPairs(ListNode *head)
    {

        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode dummy(0);
        ListNode *p = &dummy;
        dummy.next = head;

        while (p->next != nullptr && p->next->next != nullptr)
        {
            ListNode* n = p->next;
            ListNode* nn = p->next->next;
            p->next = nn;
            n->next = nn->next;
            nn->next = n;
            p = p->next->next;
        }

        return dummy.next;
    }
};
// @lc code=end
