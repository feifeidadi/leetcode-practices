#if 0
Reverse a singly linked list.
A linked list can be reversed either iteratively or recursively. Could you implement both?

#endif

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode *pHead = head;
        ListNode *pNext = head->next;
        pHead->next = NULL;

        while (pNext != NULL) {
            ListNode *pTmp = pNext->next;
            pNext->next = pHead;
            pHead = pNext;
            pNext = pTmp;
        }

        return pHead;
    }
};
