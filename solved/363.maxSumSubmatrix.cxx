#ifdef LOCAL
#pragma GCC optimize("Ofast")
#define DBG_MACRO_NO_WARNING
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include <sstream>

#include "dbg.h"

#define fr(x) freopen(x, "r", stdin)
#define fw(x) freopen(x, "w", stdout)
#define REP(x, l, u) for(ll x = l; x < u; x++)

using ll = long long;
using ull = unsigned long long;
using vvi = std::vector<std::vector<int>>;
using vvs = std::vector<std::vector<std::string>>;
using pii = std::pair<int, int>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vs = std::vector<std::string>;
using vvs = std::vector<std::vector<std::string>>;
using si = std::set<int>;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void trimLeftTrailingSpaces(std::string &);
void trimRightTrailingSpaces(std::string &);
vi stringToIntegerVector(std::string);
vs stringToStringVector(std::string);
vvi stringToIntegerVectorVector(std::string);
vvs stringToStringVectorVector(std::string);
std::string treeNodeToString(TreeNode *);
TreeNode* stringToTreeNode(std::string);
void prettyPrintTree(TreeNode *, std::string, bool);

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
	}));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

vi stringToIntegerVector(std::string input) {
	vi output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

vs stringToStringVector(std::string input) {
	vs output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		item = item.substr(1, item.length() - 2);
		output.push_back(item);
	}
	return output;
}

vvi stringToIntegerVectorVector(std::string input) {
	vvi output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ']';

	getline(ss, item, delim);
	if(item.size())
		output.push_back(stringToIntegerVector(item + "]"));

	while(getline(ss, item, delim)) {
		item = item.substr(1, item.size()-1);
		output.push_back(stringToIntegerVector(item + "]"));
	}
	return output;
}

vvs stringToStringVectorVector(std::string input) {
	vvs output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ']';
	getline(ss, item, delim);
	if(!item.empty()) {
		output.push_back(stringToStringVector(item + "]"));
	}
	while(getline(ss, item, delim)) {
		item = item.substr(1, item.length() - 1);
		output.push_back(stringToStringVector(item + "]"));
	}
	return output;
}

std::string treeNodeToString(TreeNode* root) {
	if (root == nullptr) {
	return "[]";
	}

	std::string output = "";
	std::queue<TreeNode*> q;
	q.push(root);
	while(!q.empty()) {
		TreeNode* node = q.front();
		q.pop();

		if (node == nullptr) {
		output += "null, ";
		continue;
		}

		output += std::to_string(node->val) + ", ";
		q.push(node->left);
		q.push(node->right);
	}
	return "[" + output.substr(0, output.length() - 2) + "]";
}

TreeNode* stringToTreeNode(std::string input) {
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return nullptr;
	}

	std::string item;
	std::stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(stoi(item));
	std::queue<TreeNode*> nodeQueue;
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

void prettyPrintTree(TreeNode* node, std::string prefix = "", bool isLeft = true) {
	if (node == nullptr) {
		std::cout << "Empty tree";
		return;
	}

	if(node->right) {
		prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
	}

	std::cout << prefix + (isLeft ? "└── " : "┌── ") + std::to_string(node->val) + "\n";

	if (node->left) {
		prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
	}
	return;
}
#endif  /* LOCAL */


class Solution {
public:
	/**
	 * Status: AC, Daily Challenge. 
	 * Date: Thu Apr 22 21:21:25 CST 2021
	 * */
	int maxSumSubmatrix( vvi matrix, int k ) {
		int m = matrix.size();
		if(m == 0) return 0;
		int n = matrix[0].size();
		if(n == 0) return 0;

		int res = INT_MIN;
		for(int up = 0; up < m; ++up) {
			vi colSum(n, 0);
			for(int bottom = up; bottom < m; ++bottom) {
				for(int i = 0; i < n; ++i) {
					colSum[i] += matrix[bottom][i];
				}

				si sums;
				int s = 0;
				for(int i = 0; i < n; ++i) {
					s += colSum[i];
					auto it = sums.lower_bound(s - k);
					if(it != sums.end()) res = res > (s - *it) ? res : (s - *it);
					sums.insert(s);
				}
			}
		}
		return res;
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	std::string s1, s2;
	int a, b;
	while(std::cin >> s1 >> a ) {
		auto matrix = stringToIntegerVectorVector(s1);
		auto res = s.maxSumSubmatrix(matrix, a);
		std::cout << res << std::endl;
	}
	return 0;	
}
#endif /* LOCAL */


