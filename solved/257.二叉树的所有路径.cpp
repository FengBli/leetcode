/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

typedef TreeNode* TreeNodePtr;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if (nullptr == root)
            return res;

        stack<pair<TreeNodePtr, string>> m;
        m.push(make_pair(root, to_string(root->val)));

        while(!m.empty()) {
            auto p = m.top();
            m.pop();

            TreeNodePtr ptr = p.first;
            string path = p.second;

            if(ptr->left == nullptr && nullptr == ptr->right) {
                res.push_back(path);
            } else {
                if(ptr->left) {
                    m.push(make_pair(ptr->left, path + "->" + to_string(ptr->left->val)));
                }

                if(ptr->right) {
                    m.push(make_pair(ptr->right, path + "->" + to_string(ptr->right->val)));
                }

            }
        }

        return res;
    }
};
// @lc code=end

