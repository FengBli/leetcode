//
// Created by Bailin Feng on 2020/11/28.
//

#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // find end to list2
        ListNode *ptr = list2;
        while(ptr->next != nullptr) {
            ptr = ptr->next;
        }
        cout << ptr->val << endl;

        // find pointer to a and to b
        ListNode *ptrB = list1;
        ListNode *ptrA;
        int i = -1;
        while(i != b && ptrB != nullptr) {
            if(i == a) ptrA = ptrB;
            ptrB = ptrB->next;
            i++;
        }
        ptrA->next = list1;
        ptr->next = ptrB;
        return list1;
    }
};