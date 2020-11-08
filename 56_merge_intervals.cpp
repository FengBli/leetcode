#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
  public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    	std::vector<std::vector<int>> res;

    	if(!intervals.size())
    		return res;
    	

			if (1 == intervals.size()) {
    		res = intervals;
	    	return res;
    	}

    	std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) -> bool { return a[0] < b[0]; });

    	std::vector<int> current_interval, previous_interval = intervals[0];

    	int i;
    	int c_s, c_t;		// current interval starting and ending point
    	int p_s, p_t;		// previous interval starting and ending point
    	
    	for(i = 1; i < intervals.size(); ++i) {

    		current_interval = intervals[i];

    		c_s = current_interval[0];
    		c_t = current_interval[1];

    		p_s = previous_interval[0];
    		p_t = previous_interval[1];

    		if(c_s > p_t) {
    			res.push_back(previous_interval);
    			previous_interval = current_interval;
    		} else if( c_s == p_t || (c_s <= p_t && c_t >= p_t)) {
    			previous_interval.pop_back();
    			previous_interval.push_back(c_t);
    		} 
    	}

  		res.push_back(previous_interval);
    	return res;
    }
};

int main() {
	std::vector<std::vector<int>> res;

	std::vector<int> c, d;
	c.push_back(1);
	c.push_back(4);

	d.push_back(0);
	d.push_back(4);

	res.push_back(c);
	res.push_back(d);
	Solution s;
	std::vector<std::vector<int>> r = s.merge(res);

	for(std::vector<int> interval : r) {
		std::cout << interval[0] << ", " << interval[1] << std::endl;
	}

	return 0;
}

