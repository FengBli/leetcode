#include <limits.h> 
#include <stdlib.h> 

// Status: AC, 4ms, beats 33.3%
int minimumTotal(int** triangle, int triangleRowSize, int *triangleColSizes) {
    // base cases
    if( triangleRowSize==0 )
        return 0;
    if( triangleRowSize==1 )
        return triangle[0][0];

    int itemSize = triangleRowSize * (triangleRowSize+1) / 2;
    int *dp = (int*) malloc(sizeof(int)*itemSize);
    int min = INT_MAX;

    int i, j, k=0, index = 0, aboveIndex, localMin;
    
    // the first three rows
    dp[index++] = triangle[0][0];
    dp[index++] = dp[0] + triangle[1][0];
    dp[index++] = dp[0] + triangle[1][1];

    if( triangleRowSize==2 )
        return ( dp[1] > dp[2] ) ? dp[2] : dp[1];

    for( i = 2; i < triangleRowSize; ++i ) {
        for( j = 0; j < triangleColSizes[i]; ++j) {

           if( j==0 ) { // first element of current row

                aboveIndex = (i-1)*i/2;
                dp[index++] = dp[aboveIndex] + triangle[i][j];

           } else if ( j == triangleColSizes[i]-1 ) {   // last element of current row

                aboveIndex = (i+1)*i/2 - 1;
                dp[index++] = dp[aboveIndex] + triangle[i][j];
                
           } else { // elements in middle

                aboveIndex = i*(i-1)/2 + j;
                localMin = ( dp[aboveIndex] < dp[aboveIndex-1] ) ? dp[aboveIndex] : dp[aboveIndex-1];
                dp[index++] = localMin + triangle[i][j];

           }
        }
    }

    // for ( i = 0; i < triangleRowSize; ++i ) {
    //     for( j = 0; j < triangleColSizes[i]; ++j) {
    //         printf("%d\t", dp[k++]);
    //     }
    //     printf("\n");
    // }

    index--;
    for ( i = 0; i < triangleColSizes[triangleRowSize-1]; ++i ) {
        min = min < dp[index-i] ? min : dp[index-i];
    }
    free(dp);
    return min;

}