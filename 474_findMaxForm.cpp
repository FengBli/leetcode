#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution{
public:
	int findMaxForm(vector<string>& strs, int m, int n) {
		vector<pair<int, int> > cnts;
		for(string s : strs) {
			int mm = 0; 
			for(char c : s) 
				if(c == '0') mm++;
			cnts.push_back(make_pair(mm, s.size() - mm));
		}
		


		return 0;
	}
};
