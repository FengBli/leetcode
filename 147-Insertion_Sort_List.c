// Status: AC, 4ms, beats  100.00%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode *LinkedListPtr;

LinkedListPtr insertionSortList(LinkedListPtr head) {

    if(NULL == head || NULL == head->next)
        return head;

    LinkedListPtr cur, toInsert;
    LinkedListPtr insertPos, posPrev;

    cur = head;
    toInsert = cur->next;
    
    while(toInsert) {
        if(toInsert->val >= cur->val) {
            cur = toInsert;
        } else {

            insertPos = head;
            posPrev = head;

            while(toInsert->val > insertPos->val) {
                posPrev = insertPos;
                insertPos = insertPos->next;
            }

            if(insertPos == head) {
                head = toInsert;
                cur->next = toInsert->next;
                toInsert->next = insertPos;
            } else {
                posPrev->next = toInsert;
                cur->next = toInsert->next;
                toInsert->next = insertPos;
            }
        }
        toInsert = cur->next;
    }
    return head;
}