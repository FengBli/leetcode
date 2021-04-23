#include <iostream>
#include <vector>
#include <string>

using namespace std;



// AC
class Solution {
public:
	int max_(int a, int b, int c) {
		int ab = a > b ? a : b;
		return c > ab ? c : ab;
	}

	int longestCommonSubsequence(string s, string t) {

		int ss = s.size();
		int tt = t.size();

		vector<vector<int> > dp(ss+1, vector<int>(tt+1, 0));
		for(int i = 0; i < ss; ++i) {
			dp[i][0] = 0;
		}
		for(int j = 0; j < tt; ++j) {
			dp[0][j] = 0;
		}

		for(int i = 1; i <= ss; ++i) {
			for(int j = 1; j <= tt; ++j) {
				int a = dp[i-1][j-1] + (s[i-1] == t[j-1]);
				int b = dp[i-1][j];
				int c = dp[i][j-1];
				dp[i][j] = max_(a, b, c);
			}
		}
		
		return dp[ss][tt];
	}
};

