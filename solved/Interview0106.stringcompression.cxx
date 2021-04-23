#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	/* AC 2021.04.20 */
	string compressString(std::string s) {
		int cnt = 1;
		s += "#";
		std::string res = "";
		for(int i = 1; i < s.size(); ++i) {
			if(s[i] == s[i-1]) ++cnt;
			else {
				res += s[i-1] + std::to_string(cnt);
				cnt = 1;
			}
		}
		s.erase(s.end() - 1);
		return res.size() >= s.size() ? s : res;
	}
};
