/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

typedef struct ListNode* ListNodePtr;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) 
            return head;

        ListNodePtr prev, p, q, ahead;    

        prev = head;
        q = head;
        p = q->next;

        do{
            ahead = p->next;

            p->next = q;
            q->next = ahead;

            if(prev == head) {
                head = p;
            } else {
                prev->next = p;
                prev = q;
            }
            
            q = ahead;

            if(!q) {
                break;
            }

            p = ahead->next;
        }while(p);

        return head;
    }
};
// @lc code=end

