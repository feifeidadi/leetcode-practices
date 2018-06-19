#if 0
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pNode = head;

        while(pNode != NULL) {
            ListNode *pTmp = pNode->next;
            while(pTmp != NULL && pNode->val == pTmp->val) {
                pTmp = pTmp->next;
            }
            pNode->next = pTmp;
            pNode = pNode->next;
        }

        return head;
    }
};
