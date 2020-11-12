// Status: AC,  16ms, beats 57.97%

/* 5. Longest Palindromic Substring
    Given a string s, find the longest palindromic substring in s. 
    You may assume that the maximum length of s is 1000.
 */
#include <limits.h>

char* longestPalindrome(char* s) {
    int length = strlen(s);
    int SIZE = 2*length-1;
    int i, j, k;
    int curLen, maxLen, maxCenter;

    maxLen = INT_MIN;

    for(k = 1; k <= SIZE; ++k) {
        if(k % 2) { // odd case
            i = k - 2;
            j = k + 2;
            curLen = 1;
            while(i >= 1 && j <= SIZE) {
                if(s[i/2] == s[j/2])
                    curLen += 2;
                else
                    break;
                i -= 2;
                j += 2;
            }

            if(curLen > maxLen) {
                maxLen = curLen;
                maxCenter = k;
            }
            printf("ODD: center at s[%d]={%c}, size = %d\n", k/2, s[k/2], curLen);
        } else {    // even case
            i = k - 1;
            j = k + 1;
            curLen = 0;
            while(i >= 1 && j <= SIZE) {
                if(s[i/2] == s[j/2])
                    curLen += 2;
                else
                    break;
                i -= 2;
                j += 2;
            }

            if(curLen > maxLen) {
                maxLen = curLen;
                maxCenter = k;
            }
            printf("EVEN: center between s[%d]={%c} and s[%d]={%c}, size = %d\n", k/2-1, s[k/2-1], k/2, s[k/2], curLen);
        }   
    }

    int start = (maxCenter - maxLen) / 2;   // start index
    char *res = (char*) malloc(sizeof(char)*(maxLen+1));
    for(i = 0; i < maxLen; ++i) {
        res[i] = s[start+i];
        printf("%c ", res[i]);
    }
    res[i] = '\0';
    printf("\n");
    return res;
}