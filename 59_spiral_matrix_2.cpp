#include <vector>
#include <iostream>
#include <cstdlib>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {

        std::vector<std::vector<int>> matrix;
        
        if(!n)
        	return matrix;

        for (int i = 0; i < n; ++i){
            std::vector<int> row;
            row.resize(n, 9);
            matrix.push_back(row);
        }


        int i = 2, j;
        int start = 0;
        int cnt = 1;
        int rowSize = n, colSize = n;

        for(;rowSize>=1&&colSize>=1;) {

            if (rowSize == 1) {
        		matrix[start][start] = cnt++;
                
            	break;
            }

            for (j = 0; j < colSize; ++j) {
                matrix[start][start+j] = cnt++;
                
            }

            for (j = 1; j < rowSize; ++j){
                matrix[start+j][start+colSize-1] = cnt++;
                
            }

            for (j = 1; j < colSize; ++j){
                matrix[start+rowSize-1][start+colSize-1-j] = cnt++;
                
            }

            for (j = 1; j < rowSize-1; ++j){
                matrix[start+rowSize-1-j][start] = cnt++;
                
            }

            rowSize -= i;
            colSize -= i;
            start++;
        }

        return matrix;
  }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> res = s.generateMatrix(5);
    for (std::vector<int> v : res) {
        for (int i : v) 
            std::cout << i << " ";
        std::cout << std::endl;
    }
    return 0;
}