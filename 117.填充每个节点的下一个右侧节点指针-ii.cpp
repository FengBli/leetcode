/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
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

typedef Node TreeNode;
void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}



class Solution {
public:
    Node* connect(Node* root) {
        vector<Node*> ns;
        ns.emplace_back(root);

        bool cur = (root != nullptr);
        while(cur) {
            int n = ns.size();

            for(int i = 0; i < n; i++) {
                if(ns[0]->left)
                    ns.emplace_back(ns[0]->left);
                if(ns[0]->right)
                    ns.emplace_back(ns[0]->right);

                if(i < n-1)
                    ns[0]->next = ns[1];
                else 
                    ns[0]->next = nullptr;

                ns.erase(ns.begin());
            }
            cur = ns.size();
        }

        return root;
    }

    Node* connect_ii(Node* root) { // in constant space.
        if(!root)
            return root;
        
        Node *cur = root;
        Node *head = root;

        vector<Node*> ns;
        bool flag = 1;
        while(cur) {
            
            if(cur->left)
                ns.emplace_back(cur->left);
            if(cur->right)
                ns.emplace_back(cur->right);
            
            if(flag && ns.size()) {
                head = ns[0];
                flag = 0;
            }
            
            while(ns.size() > 1) {
                ns[0]->next =  ns[1];
                cout << ns[0]->val << " -> " << ns[1]->val << endl;
                ns.erase(ns.begin());
            }
            cur = cur->next;

            if(!cur && ns.size() == 1) {
                ns[0]->next = nullptr;
                cout << ns[0]->val << " -> #" << endl;
                ns.erase(ns.begin());
                assert(ns.size() == 0);
                cur = head;
                flag = 1;
            }
        }
        return root;
    }
};

int main() {
    // std::string s = "[1,2,3,4,5,null,7]";
    std::string s = "[0,2,4,1,null,3,-1,5,1,null,6,null,8]";
    Node *root = stringToTreeNode(s);
    Solution ss;
    ss.connect_ii(root);

    return 0;
}
// @lc code=end

