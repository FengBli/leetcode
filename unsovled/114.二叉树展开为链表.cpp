/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    void pre_order_traverse(TreeNode* root){
        if (root == nullptr)
            return;
        
        new_root->val = root->val;
        new_root->right = new TreeNode();
        new_root = new_root->right; 
        
        pre_order_traverse(root->left );
        pre_order_traverse(root->right );
    }

    void flatten(TreeNode* root) {

        pre_order_traverse(root);
        
        for (TreeNode* p = node; p != nullptr; p = p->right) {
            std::cout << p->val << std::endl;
        }

    }
    
};

// @lc code=end

