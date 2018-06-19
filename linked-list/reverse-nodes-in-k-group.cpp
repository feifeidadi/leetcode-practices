#if 0
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    ListNode* reverseK(ListNode* head, int k, ListNode **pNewHead, ListNode **pNewTail) {
        ListNode *pHead = head;
        ListNode *pCur = head;

        *pNewTail = head;
        for(int j = 1; j < k; j++) {
            ListNode *pTmp = pHead->next->next;
            pHead->next->next = pCur;
            pCur = pHead->next;
            pHead->next = pTmp;
        }

        *pNewHead = pCur;
        return head->next;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = getListLength(head);
        if(len == 0 || len == 1 || k > len) return head;

        ListNode *pReturnNode = head;
        for(int i = 1; i < k; i++) {
            pReturnNode = pReturnNode->next;
        }

        ListNode *pNextHead = head;
        ListNode *pHead = NULL;
        ListNode *pTail = NULL;
        ListNode *pPrevTail = NULL;
        for(int i = 0; i < (len/k); i++) {
            pNextHead = reverseK(pNextHead, k, &pHead, &pTail);
            if(pPrevTail == NULL) {
                pPrevTail = pTail;
            } else {
                pPrevTail->next = pHead;
                pPrevTail = pTail;
            }
        }

        return pReturnNode;
    }
};
