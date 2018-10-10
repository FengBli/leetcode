// Status: AC, 20ms, beats 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* ListNodePtr;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    ListNodePtr p, q, r;
    p = l1;
    q = l2;

    int flag, sum;
    flag = 0;
    while(p && q) {
        sum = p->val + q->val + flag;
        flag = false;

        if(sum >= 10) {
            flag = 1;
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
            sum = flag + p->val;
            flag = false;

            if(sum >= 10) {
                flag = 1;
                sum %= 10;
            }
            p->val = sum;

            if(!p->next)
                r = p;

            p = p->next;
        }
        if(flag) {
            r->next = (ListNodePtr) malloc(sizeof(struct ListNode));
            r->next->val = 1;
            r->next->next = NULL;
        }
        return l1;
    } else {
        while(q) {
            sum = flag + q->val;
            flag = false;

            if(sum >= 10) {
                flag = 1;
                sum %= 10;
            }
            q->val = sum;

            if(!q->next)
                r = q;

            q = q->next;
        }

        if(flag) {
            r->next = (ListNodePtr) malloc(sizeof(struct ListNode));
            r->next->val = 1;
            r->next->next = NULL;
        }
        return l2;
    }
}