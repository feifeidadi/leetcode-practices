#if 0
Reverse a linked list from position m to n. Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.
Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverse(ListNode* pNodeM, int k) {
        ListNode *pTail = pNodeM;

        ListNode *pNode = pNodeM;
        ListNode *pNextNode = pNodeM->next;
        for(int i = 0; i < k; i++) {
            if(pNode == NULL || pNextNode == NULL)
                break;

            ListNode *pTmp = pNextNode->next;
            pNextNode->next = pNode;
            pNode = pNextNode;
            pNextNode = pTmp;
        }

        pTail->next = pNextNode;

        return pNode;
    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m >= n || head == NULL) return head;

        ListNode* pNodeM = head;
        ListNode* pNodeBeforeM = head;
        ListNode* pReturnNode = head;
        for(int i = 1; i < m; i++) {
            pNodeBeforeM = pNodeM;
            pNodeM = pNodeM->next;
        }

        if(pNodeM != head)
            pNodeBeforeM->next = reverse(pNodeM, n - m);
        else
            pReturnNode = reverse(pNodeM, n-m);
                        
        return pReturnNode;
    }
};
