// Status: AC, 0ms, beats 100%
int uniquePaths(int m, int n) {
    int i, j;
    int result;
    int **dp = (int**) malloc(sizeof(int*)*(m+1));
    
    for ( i = 0; i < m+1; ++i ) {
        dp[i] = (int*) malloc(sizeof(int)*(n+1));
    }

    for ( i = 0; i < n+1; ++i ) {
        dp[0][i] = 0;
    }

    for ( i = 0; i < m+1; ++i ) {
        dp[i][0] = 0;
    }

    for ( i = 1; i < m+1; ++i ) {
        for ( j = 1; j < n+1; ++j ) {
            if( i == 1 && j == 1 ) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    result = dp[m][n];

    for ( i = 0; i < m+1; ++i ) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
