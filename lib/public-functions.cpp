int Solution::getListLength(ListNode *head)
{
    ListNode *pNode = head;
    int length = 0;
    while (pNode != NULL) {
        length++;
        pNode = pNode->next;
    }

    return length;
}


