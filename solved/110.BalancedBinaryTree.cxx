#include <iostream>
#include <vector>

using namesapce std;

class Solution {
public:
	/* AC */
	int depth(TreeNode *root) {
		if(root == nullptr) return 0;
		if(root->left == nullptr && root->right == nullptr) return 1;
		int depth_left = depth(root->left);
		int depth_right = depth(root->right);
		if(depth_left == -1 || depth_right == -1) return -1;
		
		bool isBalanced = static_cast<int>(std::abs(depth_left - depth_right) <= 1);
		if(!isBalanced) return -1;
		
		return (depth_left > depth_right ? depth_left : depth_right) + 1;
	}

	bool isBalanced(TreeNode *root) {
		return depth(root) != -1;
	}
};


