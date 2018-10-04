// TODO: unfinished

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
typedef struct ListNode* ListNodePtr;

struct ListNode* swapPairs(struct ListNode* head) {
    if(!head->next) // only one node
        return head;

    ListNodePtr p = head;

}