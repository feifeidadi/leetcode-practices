// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *pHead =NULL, *pList = NULL, *pAnotherList = NULL;

        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        pList = (l1->val < l2->val ? l1 : l2);
        pAnotherList = (pList == l1 ? l2 : l1);
        pHead = pList; // The head of the new list

        while(pList != NULL) {
            while(pList->next != NULL && pList->next->val < pAnotherList->val) {
                pList = pList->next;
            }
            if(pList->next == NULL) {
                pList->next = pAnotherList;
                break;
            }
            ListNode* pTmpNode = pList->next;
            pList->next = pAnotherList;
            pList = pList->next;

            pAnotherList = pTmpNode;
        }

        return pHead;
    }
};
