#if 0
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:

A:          a1 → a2 \
                     c1 → c2 → c3
B:     b1 → b2 → b3 /
begin to intersect at node c1.

Notes:
    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.
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

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pNodeA = headA;
        ListNode *pNodeB = headB;
        int lengthA = getListLength(pNodeA);
        int lengthB = getListLength(pNodeB);

        if(lengthA == 0 || lengthB == 0)
            return NULL;

        int offset = (lengthA > lengthB) ? (lengthA - lengthB) : (lengthB - lengthA);
        if(lengthA > lengthB) {
            for(int i =0; i < offset; i++) pNodeA = pNodeA->next;
        }
        else {
            for(int i =0; i < offset; i++) pNodeB = pNodeB->next;
        }

        while(pNodeA != pNodeB) {
            pNodeA = pNodeA->next;
            pNodeB = pNodeB->next;
        }
        
        return pNodeA;
    }
};
