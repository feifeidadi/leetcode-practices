#if 0
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *pHead = head;
        ListNode *pPrev = NULL;
        ListNode *pReturnNode = (head != NULL && head->next != NULL ? head->next : head);

        while(pHead != NULL && pHead->next != NULL) {
            ListNode *pTmp = pHead->next->next;
            pHead->next->next = pHead;
            if(pPrev != NULL) 
                pPrev->next = pHead->next;

            pHead->next = pTmp;
            pPrev = pHead;
            pHead = pTmp;
        }

        return pReturnNode;
    }
};
