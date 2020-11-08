// Status: AC, 20ms, beats 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode* ListNodePtr;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNodePtr p, q, r;
    p = l1;
    q = l2;

    int carry, sum;
    carry = 0;
    while(p && q) {
        sum = p->val + q->val + carry;
        carry = 0;

        if(sum >= 10) {
            carry = 1;
            sum %= 10;
        }
        p->val = sum;
        q->val = sum;

        p = p->next;
        if(!q->next)
            r = q;
        q = q->next;
    }

    if(p) {
        while(p) {
            sum = carry + p->val;
            carry = 0;

            if(sum >= 10) {
                carry = 1;
                sum %= 10;
            }
            p->val = sum;

            if(!p->next)
                r = p;

            p = p->next;
        }

        if(carry) {
            r->next = (ListNodePtr) malloc(sizeof(struct ListNode));
            r->next->val = 1;
            r->next->next = 0;
        }

        return l1;
    } else {
        
        while(q) {
            sum = carry + q->val;
            carry = 0;

            if(sum >= 10) {
                carry = 1;
                sum %= 10;
            }
            q->val = sum;

            if(!q->next)
                r = q;

            q = q->next;
        }

        if(carry) {
            r->next = (ListNodePtr) malloc(sizeof(struct ListNode));
            r->next->val = 1;
            r->next->next = 0;
        }

        return l2;
    }
}