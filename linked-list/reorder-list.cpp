#if 0
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    unsigned int generateNodeMap(ListNode *head, std::map<unsigned int, ListNode *> &nodeMap)
    {
        ListNode *pNode = head;
        unsigned int length = 0;
        while (pNode != NULL) {
            nodeMap[length++] = pNode;
            pNode = pNode->next;
        }

        return length;
    }

    void reorderList(ListNode* head) {
        std::map<unsigned int, ListNode *> nodeMap;

        unsigned int totalNodes = generateNodeMap(head, nodeMap);
        int loopCount = (totalNodes/2 -1) + (totalNodes%2);

        for(int i=0; i<loopCount; i++, totalNodes--) {
            nodeMap[i]->next = nodeMap[totalNodes-1];
            nodeMap[totalNodes-1]->next = nodeMap[i+1];
            nodeMap[totalNodes-1-1]->next = NULL;
        }
        /* Performance is a little bit higher than above the codes
        for(int i=0; i<loopCount; i++, totalNodes--, head = head->next->next) {
            nodeMap[totalNodes-1]->next = head->next;
            head->next = nodeMap[totalNodes-1];
            nodeMap[totalNodes-1-1]->next = NULL;
        }
        */

    }
};
