#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	std::vector<std::vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		int N = nums.size();
		
		if (N < 3)
			return res;

		sort(nums.begin(), nums.end());

		for(int i = 0; i < N; ++i) {
			if(i > 0 && nums[i] == nums[i-1])
				continue;

			for (int j = i+1; j < N; ++j) {
				if(j > i+1 && nums[j] == nums[j-1]) 
					continue;

				for(int k = N-1; k > j; --k) {

					if(nums[i] + nums[j] + nums[k] == 0) {
						res.push_back({nums[i], nums[j], nums[k]});
					}
				}
			}
		}
		
		for (auto tuple : res) {
			for( auto item : tuple) {
				cout << item << "\t";
			}
			cout << endl;
		}

		return res;
	}
	
};


int main() {
	Solution s;
	vector<int> v {-1,0,1,2,-1,-4,-2,-3,3,0,4};
	// vector<int> v;
	// int a;
	// while(cin >> a)
	// 	v.push_back(a);
	
	s.threeSum(v);
}