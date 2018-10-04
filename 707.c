// Status: AC, 24ms, beats 54.36%.
// Those faster submissions use a *rear* pointer or a *length* atrribute

#include <stdio.h>
#include <stdlib.h>

typedef struct MyLinkedListNode {
    int val;
    struct MyLinkedListNode *next;
}MyLinkedListNode, *MyLinkedListNodePtr;

typedef struct MyLinkedList{
    MyLinkedListNodePtr head;
} MyLinkedList, *MyLinkedListPtr;


/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
    MyLinkedListPtr obj = (MyLinkedListPtr) malloc(sizeof(MyLinkedList));
    obj->head = NULL;

    return obj;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {
    /* Note that index starts from 0. */
    if(index < 0)
        return -1;

    MyLinkedListNodePtr p = obj->head;
    int i = 0;
    while(p && i < index) {
        p = p->next;
        ++i;
    }

    if(!p || i != index)
        return -1;
    return p->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedListNodePtr to_insert = (MyLinkedListNodePtr) malloc(sizeof(MyLinkedListNode));
    to_insert->val = val;
    to_insert->next = NULL;

    if(!obj->head) {  // empty list
        obj->head = to_insert;
        return;
    }

    MyLinkedListNodePtr p = obj->head;
    obj->head = to_insert;
    to_insert->next = p;
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedListNodePtr to_insert = (MyLinkedListNodePtr) malloc(sizeof(MyLinkedListNode));
    to_insert->val = val;
    to_insert->next = NULL;

    if(!obj->head) { // empty list
        obj->head = to_insert;
        return;
    }

    MyLinkedListNodePtr p = obj->head;
    while(p->next)
        p = p->next;

    p->next = to_insert;
}

/** Add a node of value val before the index-th node in the linked list. 
If index equals to the length of linked list, the node will be appended to the end of linked list. 
If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    /* Note that index starts from 0. */

    if(index < 0)
        return;

    MyLinkedListNodePtr to_insert = (MyLinkedListNodePtr) malloc(sizeof(MyLinkedListNode));
    to_insert->val = val;
    to_insert->next = NULL;

    if(!obj->head && index == 0) {
        obj->head = to_insert;
        return;
    }
        
    MyLinkedListNodePtr p, q;
    p = obj->head;
    q = NULL;

    int i = 0;
    while(p && i < index){
        q = p;
        p = p->next;
        ++i;
    }
    if(i != index)
        return;

    q->next = to_insert;
    to_insert->next = p;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    /* Note that index starts from 0. */
    MyLinkedListNodePtr head = obj->head;

    if(!head || index < 0)
        return;

    if(index == 0) {    // delete the first node
        head = head->next;
        return;
    }
        
    MyLinkedListNodePtr p, q;
    p = obj->head;
    q = p;

    int i = 0;
    while(p && i < index){
        q = p;
        p = p->next;
        ++i;
    }
    
    if(!p || i != index)
        return;

    q->next = p->next;
    p->next = NULL;
    free(p);
}

void traverse(MyLinkedList *obj) {
    MyLinkedListNodePtr p = obj->head;
    while(p) {
        printf("%d->", p->val);
        p = p->next;
    }
    printf("NULL\n");
}

void myLinkedListFree(MyLinkedList *obj) {
    free(obj);
}


/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main() {
    MyLinkedListPtr head = myLinkedListCreate();
    myLinkedListAddAtHead(head, 1);
    // myLinkedListAddAtTail(head, 3);
    myLinkedListAddAtIndex(head, 1, 2);
    printf("get(1)=%d\n", myLinkedListGet(head, 1));
    printf("get(0)=%d\n", myLinkedListGet(head, 0));
    printf("get(2)=%d\n", myLinkedListGet(head, 2));
    traverse(head);
    myLinkedListFree(head);
    return 0;
}