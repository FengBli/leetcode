// Status: AC,  12ms, beats 88.95%, T(n) = O(2n) = O(n);

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    vector<int> inorderSeq;

    void inorderTraverseWithRecursion(TreeNode *root) {
        
        if(NULL == root)
            return;

        inorderTraverseWithRecursion(root->left);
        inorderSeq.push_back(root->val);
        inorderTraverseWithRecursion(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {

        inorderTraverseWithRecursion(root);

        int min = INT_MAX;
        int curMin = 0;
        for(int i = 0; i < inorderSeq.size()-1; ++i) {
            curMin = ((inorderSeq[i] - inorderSeq[i+1]) >= 0) ? (inorderSeq[i] - inorderSeq[i+1]) : (inorderSeq[i+1] - inorderSeq[i]);

            if(curMin < min) {
                min = curMin;
                if(0 == min)
                    return min;
            }
        }

        return min;
    }
};


// Status: AC,  12ms, beats 88.95%, T(n) = O(n);
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:

    int min;
    int prev;

    void inorderTraverseWithRecursion(TreeNode *root) {
        
        if(NULL == root)
            return;

        inorderTraverseWithRecursion(root->left);
        int curMin = root->val - prev;
        curMin = (curMin > 0) ? curMin : (-1) * curMin;
        if(curMin < min)
            min = curMin;
        prev = root->val;
        inorderTraverseWithRecursion(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        prev = INT_MAX;
        min = INT_MAX;

        inorderTraverseWithRecursion(root);

        return min;
    }
};



// Solution with non-recursive inorder traverse, 
// Status: AC,  8ms, beats 99.07%, T(n) = O(n);
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int min, curMin;
        min = INT_MAX;

        std::stack<TreeNode*> visit;
        int prev = INT_MAX;

        visit.push(root);
        TreeNode *p;

        while(visit.size()) {
            while(visit.top()) {
                visit.push(visit.top()->left);
            }
            visit.pop();
            if(visit.size()) {

                p = visit.top();
                visit.pop();

                curMin = p->val - prev;
                curMin = (curMin > 0) ? curMin : (-1) * curMin;
                if(curMin < min)
                    min = curMin;

                prev = p->val;

                visit.push(p->right);
            }
        }
        return min;
    }
    
};
