// Status: AC, 0ms, beats 100%.

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

typedef struct StackNode {
    char data;
    struct StackNode *next;
} StackNode, *StackNodePtr;

typedef struct Stack {
    StackNodePtr head;
    int size;
} Stack, *StackPtr;

StackPtr StackInit() {
    StackPtr S = (StackPtr) malloc(sizeof(Stack));
    S->head = (StackNodePtr) malloc(sizeof(StackNode));
    S->head->next = NULL;
    S->size = 0;

    return S;
}

int StackPush(StackPtr S, char c) {
    
    // construct a node for the input
    StackNodePtr p = (StackNodePtr) malloc(sizeof(StackNode));
    if(!p)
        return -1;
    p->data = c;
    p->next = NULL;

    // add it to stack
    StackNodePtr s = S->head->next;
    S->head->next = p;
    p->next = s;
    ++ S->size;

    return 0;
}

int StackPop(StackPtr S, char* c) {
    if(S->size == 0)
        return -1;

    StackNodePtr p = S->head->next->next;
    StackNodePtr to_del = S->head->next;
    S->head->next = p;
    *c = to_del->data;
    -- S->size;

    return 0;
}

int StackPrint(StackPtr S) {
    if(S->size == 0)
        return -1;
    StackNodePtr p = S->head->next;
    while(p) {
        printf("%c\n", p->data);
        p = p->next;
    }

    return 0;
}

bool isValid(char* s) {
    StackPtr S = StackInit();
    int i;
    char c = 'a';
    char *topElem = &c;
    for (i = 0; s[i]; ++i) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{')
            StackPush(S, s[i]);
        else {
            StackPop(S, topElem);
            if(s[i] == ')' && *topElem == '(')
                continue;
            else if(s[i] == ']' && *topElem == '[')
                continue;
            else if(s[i] == '}' && *topElem == '{')
                continue;
            else
                return 0;
        }
    }
    // StackPrint(S);

    if(S->size != 0)
        return 0;
    return 1;
}

int main() {
    char* str = "{()}[[()]]{";
    int res = isValid(str);
    printf("%d\n", res);
    return 0;   
}