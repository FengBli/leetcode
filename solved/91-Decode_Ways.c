#include <string.h> 

// Status: AC, 0ms, beats 100%
int solve(char* s, int *dp, int n) {
    if( n==0 ) {
        dp[n] = 1;
    }
    
    if( n==1 ) {
        dp[1] = (s[0]=='0') ? 0 : 1;
    }

    int flag, a, b;

    if( dp[n] == -1 ) {
        flag = ( (s[n-1]>'0' && s[n-1]<='6' && s[n-2]=='2') ||
            ( s[n-1]!='0' && s[n-2]=='1' ) );
        if ( flag ) {
            a = solve(s, dp, n-1);
            b = solve(s, dp, n-2);
            if( a==0 || b==0 ) {
                dp[n] = 0;
            } else {
                dp[n] = a+b;
            }
        } else if( s[n-1]=='0' && s[n-2]>='1' && s[n-2]<='2' ) {
            dp[n] = solve(s, dp, n-2);
        } else if( s[n-1]=='0' ) {
            dp[n] = 0;
        } else {
            dp[n] = solve(s, dp, n-1);
        }
    }
    
    return dp[n];
    
}

int numDecodings(char* s) {
    
    int i, flag, result;
    int len = strlen(s);

    int *dp = (int*) malloc(sizeof(int)*(len+1));
    for(i = 0; i <= len; ++i) {
        dp[i] = -1;
    }
    
    solve(s, dp, len);
    result = dp[len];
    free(dp);
    return result;
}

/*
TODO:错误的bottom-up版本,考虑是否有正确的bottom-up的解法
例如9123210,最后的0只能和1配在一起,则OPT(9123210) = OPT(91232) = OPT(9123), 
    而bottom-up在OPT(912321) = OPT(91232) + OPT(9123)导致错误.
    故,只能top-down?
*/
int numDecodings_WA(char* s) {

    if(s[0] == '0') {
        return 0;
    }

    int i, flag, result;
    int len = strlen(s);
    int *dp = (int*) malloc(sizeof(int)*(len+1));

    dp[0] = 1;
    dp[1] = 1;

    for ( i = 2; i <= len; ++i ) {
        flag = ( s[i-1] > '0' && s[i-1] <= '6' && s[i-2] >= '1' && s[i-2] <= '2'); 
        if( flag ) {
            dp[i] = dp[i-1] + dp[i-2];
        } else if ( s[i-1] == '0' && s[i-2] > '2' ) {
            return 0;
        } else {
            dp[i] = dp[i-1];
        }
    }

    for ( i = 0; i <= len; ++i ) {
        printf("%d ", dp[i]);
    }
    printf("\n");

    result = dp[len];
    free(dp);
    return result;
}
