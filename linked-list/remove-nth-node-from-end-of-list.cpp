#if 0
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

      After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
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
    unsigned int generateNodeMap(ListNode *head, std::map<unsigned int, ListNode *> &nodeMap) {
        ListNode *pNode = head;
        unsigned int length = 0;
        while (pNode != NULL) {
            nodeMap[length++] = pNode;
            pNode = pNode->next;
        }
        nodeMap[length] = NULL;

        return length;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::map<unsigned int, ListNode *> nodeMap;

        unsigned int length = generateNodeMap(head, nodeMap);

        if(n > length) return head;
        if(n == length) {
            ListNode *pNext = head->next;
            free(head);
            return pNext;
        }

        nodeMap[length - n - 1]->next = nodeMap[length - n + 1];
        free(nodeMap[length - n]);
        nodeMap.clear();

        return head;
    }
};
