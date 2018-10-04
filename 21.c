#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct ListNode{
	int val;
	struct ListNode *next;	
} ListNode, *ListNodePtr;

void traverse(struct ListNode *l) {
	struct ListNode *p = l;
	while (p) {
		printf("%d  ", p->val);
		p = p->next;
	}
	printf("\n");
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1)
    	return l2;
    if(!l2)
    	return l1;

    struct ListNode *p, *q, *result, *res;
    result = (struct ListNode *) malloc(sizeof(struct ListNode));
    result->next = NULL;
    res = result;
    p = l1;
    q = l2;

    while(p && q) {
    	if(p->val <= q->val) {
    		res->next = p;
    		p = p->next;
    		res = res->next;
    	} else {
    		res->next = q;
    		q = q->next;
    		res = res->next;
    	}
    }
    while(p) {
    	res->next = p;
		p = p->next;
		res = res->next;
    }
    while(q) {
		res->next = q;
		q = q->next;
		res = res->next;
    }

    result = result->next;
    return result;
}
struct ListNode* create(int i) {
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode* p = head;
	int j = 1;
	while(j < i) {
		p->val = j;
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		if(j+1 < i)
			p = p->next;
		++j;
	}
	p->next = NULL;
	return head;

}

int main() {
	// struct ListNode* l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	// l1->val = 1;
	// l1->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	// l1->next->val = 2;

	// struct ListNode* l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	// l2->val = 1;
	// l2->next = (struct ListNode*)malloc(sizeof(struct ListNode));
	// l2->next->val = 2;
	printf("=======l1=========\n");
	struct ListNode* l1 = create(20);
	traverse(l1);
	
	printf("=======l2=========\n");
	struct ListNode* l2 = create(8);
	traverse(l2);

	printf("=======result=========\n");
	struct ListNode* res = mergeTwoLists(l1, l2);
	traverse(res);
}