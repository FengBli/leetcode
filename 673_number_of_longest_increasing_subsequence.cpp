#include <vector>
#include <map>
#include <iostream>
#include <limits.h>

#define INF INT_MAX/10

class Solution {
public:
  int findNumberOfLIS(std::vector<int>& nums) {
		if(!nums.size())
			return 0;

		int N = nums.size();
		int dp[N], cnt[N];

		std::fill(dp, dp+N, INF);
		std::fill(cnt, cnt+N, 0);

		for(int i = 0; i < N; i++) {
			int* p = std::lower_bound(dp, dp+N, nums[i]);
			*p = nums[i];
			cnt[p-dp]++;
		}

		for (int i = 0; i < N; ++i)
			std::cout << cnt[i] << " ";
		std::cout << std::endl;

		int index = std::lower_bound(dp, dp+N, INF) - dp;

		int res = 1;
		for(int i = 0; i < index; ++i)
			res *= cnt[i];

		return res;
  }
};

int main() {
	std::vector<int> nums({1, 2, 4, 3, 5, 4, 7, 2});
	Solution s;
	s.findNumberOfLIS(nums);
	return 0;
}