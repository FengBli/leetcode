#include <limits.h> 
// Status: AC, 4ms, beats 100%
// AC 
int minPathSum(int** grid, int gridRowSize, int gridColSize) {
    
    if( (gridRowSize+gridColSize)==0 )
        return 0;
    
    int i, j, result = 0;
    int **dp = (int**) malloc(sizeof(int*)*(gridRowSize+1));

    for ( i = 0; i <= gridRowSize; ++i ) {
        dp[i] = (int*) malloc(sizeof(int)*(gridColSize+1));
        dp[i][0] = INT_MAX;
    }

    for ( i = 0; i <= gridColSize; ++i ) {
        dp[0][i] = INT_MAX;
    }

    for( i = 1; i <= gridRowSize; ++i ) {
        for( j = 1; j <= gridColSize; ++j ) {          
            if( i==1 && j==1 ) {
                dp[i][j] = grid[0][0];
            } else {
                dp[i][j] = ((dp[i-1][j] < dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1]) + grid[i-1][j-1];
            }
        }
    }

    result = dp[gridRowSize][gridColSize];

    return result;
}