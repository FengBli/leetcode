// Status: AC, 4ms, beats 100%

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
typedef struct ListNode* ListNodePtr;

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        
        int *returnSize = (int*) malloc(sizeof(int)*k);
        
        ListNodePtr q, p = root;
        int length = 0;
        for(; p; p = p->next)
            ++length;

        int m = length / k;
        int r = length % k;
        
        int i, j;
        for(i = 0; i < k; ++i) {
            returnSize[i] = m;
            if(i < r)
                returnSize[i] += 1;
            // printf("%d ", returnSize[i]);
        }
        // printf("\n");

        res.push_back(root);
        p = root;
        for(i = 0; i < k; ++i) {
            for(j = 0; j < returnSize[i]; ++j) {
                q = p;
                p = p->next;
            }

            if(i+1 < k) {
                res.push_back(p);
                q->next = NULL;
            }
        }
        
        // printf("size of vector = %d\n", res.size());
        
        // for(i = 0; i < res.size(); ++i) {
        //     printf("[");
        //     ListNodePtr s = res[i];
        //     if(s)
        //         while(s) {
        //             printf("%d  ", s->val);
        //             s = s->next;
        //         }
        //     else
        //         printf("NULL", i);
        //     printf("]\n");
        // }

        return res;        
    }
};

