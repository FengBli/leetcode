#include <iostream>

struct ListNode {
   int val;
   ListNode *next;
   ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(nullptr == head || nullptr == head->next)
      	return head;

      ListNode *p = head;
      ListNode *tail, *q;
            
      int size = 0;
      while(p) {
        tail = p;
        ++size;
        p = p->next;
      }

      if(0 == k%size)
      	return head;
      
      if(0 == k)
      	return head;

      k = size - k;
      
      p = head;
      for(int i = 0; i < k; ++i) {
      	q = p;
        p = p->next;
      }  
      
      tail->next = head;
      q->next = NULL;
      
      return p;
    }
};

int main() {
	return 0;
}