#include <iostream>
#include <stdlib.h>
#include <vector>
#include <map> // std::lower_bound
#include <algorithm> // std::fill
#include <limits.h>	// INT_MAX

#define INF INT_MAX/10

class Solution{
public:
	int lengthOfLIS(std::vector<int>&  nums) {
		if(!nums.size())
			return 0;

		int N = nums.size();
		int dp[N];
		std::fill(dp, dp+N, INF);
		for(int i = 0; i < N; i++) {
			*std::lower_bound(dp, dp+N, nums[i]) = nums[i];
		}
		return std::lower_bound(dp, dp+N, INF) - dp;
	}
};