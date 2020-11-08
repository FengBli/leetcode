#include <vector>
#include <iostream>
#include <cstdlib>

class Solution {
public:
	// AC
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        
        if(!matrix.size())
        	return res;

        int rowSize = matrix.size();
        int colSize = matrix[0].size();

        int i, j, k;
        int start = 0;
        for(i = 2;rowSize>=1&&colSize>=1;) {

            if (rowSize == 1) {
            	for(j = 0; j < colSize; ++j)
            		res.push_back(matrix[start][start+j]);
            	break;
            }

            if (colSize == 1) {
            	for(j = 0; j < rowSize; ++j)
            		res.push_back(matrix[start+j][start]);
            	break;
            }

            for (j = 0; j < colSize; ++j)
                res.push_back(matrix[start][start+j]);

            for (j = 1; j < rowSize; ++j)
                res.push_back(matrix[start+j][start+colSize-1]);

            for (j = 1; j < colSize; ++j)
                res.push_back(matrix[start+rowSize-1][start+colSize-1-j]);

            for (j = 1; j < rowSize-1; ++j)
                res.push_back(matrix[start+rowSize-1-j][start]);

            rowSize -= i;
            colSize -= i;
            start++;

        }

        return res;
  }
};


int main() {
	std::vector<std::vector<int>> matrix;
	int N = 2, M = 5;
	for(int i = 0; i < N; ++i) {

		std::vector<int> row;
		for (int j = 0; j < M; ++j) 
			row.push_back(rand()%100+1);
		matrix.push_back(row);
	}

	for (std::vector<int> v: matrix) {
		for (int i : v) 
			std::cout << i << " ";
		std::cout << std::endl;
	}

	Solution s;
	std::vector<int> v = s.spiralOrder(matrix);
	std::cout << "size: " << v.size() << std::endl;
	for (int i : v) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}