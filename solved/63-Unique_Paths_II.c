// Status: AC, 0ms, beats 100%
// AC
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridRowSize, int obstacleGridColSize) {
    if( obstacleGrid[0][0]==1 ) {
        return 0;
    }
    
    int i, j, result = 0;
    int **dp = (int**) malloc(sizeof(int*)*(obstacleGridRowSize+1));

    for ( i = 0; i <= obstacleGridRowSize; ++i ) {
        dp[i] = (int*) malloc(sizeof(int)*(obstacleGridColSize+1));
        dp[i][0] = 0;
    }

    for ( i = 0; i <= obstacleGridColSize; ++i ) {
        dp[0][i] = 0;
    }

    for( i = 1; i <= obstacleGridRowSize; ++i ) {
        for( j = 1; j <= obstacleGridColSize; ++j ) {          
            if( i==1 && j==1 ) {
                dp[i][j] = 1;
            } else if( obstacleGrid[i-1][j-1]==1 ) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    result = dp[obstacleGridRowSize][obstacleGridColSize];

    return result;
}
