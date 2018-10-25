// Status: AC, 0ms, beats 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* ListNodePtr;

struct ListNode* swapPairs(struct ListNode* head) {
    
    if(!head || !head->next) // one or zero node
        return head;

    ListNodePtr prev, p, q, ahead;

    prev = head;
    q = head;
    p = q->next;

    do {
        ahead = p->next;

        p->next = q;
        q->next = ahead;

        if(prev == head)
            head = p;
        else {
            prev->next = p;
            prev = q;
        }

        // move forward
        q = ahead;

        if(!q)
            break;

        p = ahead->next;
    } while(p);

    return head;

}