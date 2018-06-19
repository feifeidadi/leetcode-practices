#if 0
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    int getListLength(ListNode *head); // implemented in lib/*.cpp

    ListNode* rotateRight(ListNode* head, int k) {
        int listLen = getListLength(head);

        if(listLen <= 1 || (k%listLen) == 0) return head;
                        
        if(k > listLen) k = k%listLen;

        ListNode *pCurNode = head;
        for(int i = 1; i < (listLen - k) && pCurNode != NULL; i++)
            pCurNode = pCurNode->next;

        if(pCurNode == NULL) return head;

        ListNode *pTmpNode = pCurNode->next;
        pCurNode->next = NULL; // Terminate the list after (listLen - k) element
        pCurNode = pTmpNode;

        ListNode *pHead = pCurNode;
        while(pCurNode->next != NULL)
        {
            pCurNode = pCurNode->next;
        }
        pCurNode->next = head;

        return pHead;
    }
};
