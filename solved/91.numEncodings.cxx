#include <iostream>
#include <vector>
#include <string>

using namespace std;

using vi = vector<int>;

class Solution {
public:
	
	/* Status: AC,
	 * leetcode每日一题
	 * Date:  Wed Apr 21 13:43:10 CST 2021
	 **/
	int numDecodings(string s) {
		int n = s.size();
		if(n == 0) return 0;
		if(n == 1) {
			if(s == "0") return 0;
			else return 1;
		}
		vi dp(n+1, 0);
		if(s[n-1] == '0') dp[n-1] = 0;
		else dp[n-1] = 1;
		std::string subs = s.substr(n-2, 2);
		if(subs <= "26" && subs > "10") dp[n-1] = 1;
		else dp[n-1] = 0;
		for(int i = n-2; i >= 0; --i) {
			if(s[i] == '0') dp[i] = 0;
			else {
				dp[i] += dp[i+1];
				std::string ss = s.substr(i, 2);
				if(ss <= "26" && ss >= "10") {
					dp[i] += dp[i+2];
				}
			}
		}
		
		return dp[0];	
	}
};

#ifdef LOCAL
int main() {
	Solution s;
	std::string s1, s2;
	int a, int b;
	while(std::cin >> s1 ) {
		auto res = s.numDecodings(s1 );
		std::cout << res << std::endl;
	}
	return 0;	
}
#endif /* LOCAL */


