// TODO: unfinished
#include <iostream>
#include <vector>

class Solution{
  public:
    bool canJump(std::vector<int>& nums) {
    	int N = nums.size();
    	int dest = N - 1;

    	for (int i = N-1; i >= 0; --i) {
    		if(i+nums[i] >= dest) {
    			dest = i;
    		}
    	}

    	return dest == 0;


    }


  	/*bool canJump(std::vector<int>& nums) {
  		int n = nums.size();
  		int flags[n];

  		memset(flags, 0, sizeof(flags));
  		flags[n-1] = 1; 	// 1 stands for reachable, 0 for unreachable

  		for(int i = n-2; i >= 0; --i) {
  			int far = min(i+nums[i], n-1);

  			for (int j = i+1; j <= far; ++j) {
  				if(flags[j]) {
  					flags[i] = 1;
  					break;
  				}
  			}
  		}
  		return flags[0];
  	}*/

	/*bool canJump(vector<int>& nums) {
      int n = nums.size();
      int flags[n];
      memset(flags, 0, sizeof(flags));
      
      flags[n-1] = 1;
      for (int i = n-2; i>=0;--i) {
      	for(int j = 0; i+j<=n-1&&j<=nums[i]; ++j){
          if(flags[i+j]){
            flags[i] = 1;
            break; 
          }
        }
      } 
      return flags[0];
    }*/
};



int main() {
  int arr[5] = {2, 3, 1, 1, 4};

  std::vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
  Solution s;
  std::cout << s.canJump(nums) << std::endl;
  return 0;
}
