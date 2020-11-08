#include <vector>
#include <queue>
// TODO: unfinished
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
    	int M = matrix.size();
    	int N = matrix[0].size();

    	std::priority_queue<int> row, col;

        for(int i = 0; i < M; ++i) {
        	for(int j = 0; j < N; ++j) {
        		if(0 == matrix[i][j]) {
        			row.push(i);
        			col.push(j);
        		}

        	}
        }
    }
};