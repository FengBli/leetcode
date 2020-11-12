/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
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

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int i = 0 ;
        ListNode *cur = head;
        ListNode *prev = head;
        while(i++ < n) {
            cur = cur->next;
        }
        if(!cur) {
            head = prev->next;
            return head;
        }
        while(cur->next) {
            cur = cur->next;
            prev = prev->next;
        }
        prev->next = prev->next->next;

        return head;
    }
};
// @lc code=end

