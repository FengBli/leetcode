#include <iostream>
#include <vector>
// TODO: unfinished
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    bool isValidBST(TreeNode *root) { 
      if(!root || (!root->left && !root->right))
        return true;

      for(int i = 1; i < nums.size(); ++i)
        if(nums[i] <= nums[i-1])
          return false;
      return true;
    }      

    void dfs(TreeNode *root) {
    
      if(root->left)
        dfs(root->left);

      nums.push_back(root->val);

      if(root->right)
        dfs(root->right);
      
      
    }
  private:
    vector<int> nums;  
};

int main() {

  return 0;
}
