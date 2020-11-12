// Status: AC, 12ms, beats 100%

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    if(NULL == root)
        return NULL;

    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->right, p, q);

    if(root->val < p->val && root->val < q->val)
        return lowestCommonAncestor(root->left, p, q);

    return root;
}