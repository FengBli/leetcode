/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

*/


#include<bits/stdc++.h>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* left;
//     Node* right;
//     Node* next;

//     Node() : val(0), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

//     Node(int _val, Node* _left, Node* _right, Node* _next)
//         : val(_val), left(_left), right(_right), next(_next) {}
// };

class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> nodes;

        if(!root)
            return root;
        nodes.emplace_back(root);

        Node* cur = root;

        while(cur){
            int n = nodes.size();
            for (int i = 0; i < n-1; i++) {
                nodes[i]->next = nodes[i+1];
                // cout << nodes[i]->val << "->" << nodes[i+1]->val << endl;
            }
            nodes[n-1]->next = nullptr;
            // cout << nodes[n-1]->val << "->#" << endl;

            cur = cur->left;

            for(int i = 0; i < n; ++ i) {
                if(nodes[0]->left) {
                    nodes.emplace_back(nodes[0]->left);
                    nodes.emplace_back(nodes[0]->right);
                }
                nodes.erase(nodes.begin());
            }

        }
        return root;
        
    }
};

// int main() {
//     vector<int> a {1, 2, 3, 4, 5, 6, 7};
//     int n= a.size();
//     for(int i = 0; i < n; ++i) {
//         cout << a[0] << endl;
//         a.erase(a.begin());
//     }

//     return 0;
// }
// @lc code=end

