// Status: AC, 8ms, beats 100%

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

    if(root == p || root == q)
        return root;

    struct TreeNode* left_lca = lowestCommonAncestor(root->left, p, q);
    struct TreeNode* right_lca = lowestCommonAncestor(root->right, p, q);

    if(left_lca && right_lca)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}