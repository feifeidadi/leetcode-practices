#if 0
Given a singly linked list, determine if it is a palindrome.
e.g.
    a->NULL
    Palindrome

    b->a->NULL
    Not Palindrome

    a->b->a->NULL
    Is Palindrome

    c->a->b->a->NULL
    Not Palindrome

    a->c->a->b->a->NULL
    Not Palindrome

    b->a->c->a->b->a->NULL
    Not Palindrome

    a->b->a->c->a->b->a->NULL
    Is Palindrome

Follow up:
Could you do it in O(n) time and O(1) space?

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
    bool isPalindrome(ListNode* head) {
        ListNode *pNode = head;
        std::map<unsigned int, ListNode *> nodeMap;
        unsigned int length = 0;

        while (pNode != NULL) {
            nodeMap[pNode] = ;
            pNode = pNode->next;
            length++;
        }

        return (nodeMap.size() == length ? false:true);
    }
};
