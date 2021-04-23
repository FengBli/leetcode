#include "leetcode.hpp"

class Solution {
public:
	/* Status: 	TODO, 
	 * Date:  Wed Apr 21 00:44:15 CST 2021
	 * */
	 bool isHappy(int n) { 
		si seq{};
		int nn = n;
		do {
			int sum_ = 0;
			while(nn) {
				int digit = nn%10;
				sum_ += digit * digit;
				nn /= 10;
			}
			if(seq.count(sum_) > 0) { std::cout << std::endl; return false; }
			seq.insert(sum_);
			nn = sum_;
			std::cout << nn << " ";
		} while (nn != 1);
		std::cout << std::endl;
		return true;	
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	std::string s1, s2;
	int a, b;
	while(std::cin >> a ) {
		auto res = s.isHappy(a);
		std::cout << "res = " << res << std::endl;
	}
	return 0;	
}
#endif /* LOCAL */


