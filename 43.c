#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SEGLENGTH 4

char* strSlice(char* str, int end, int length) {
    if(end < length)
        length = end + 1;

    char* res = (char*) malloc(sizeof(char) * (length+1));
    int i;
    int strLen = strlen(str);

    for(i = 0; i < length; ++i) {
        res[length-1-i] = str[end-i];
    }
    res[i] = '\0';
    
    return res;
}

char* multiply(char* num1, char* num2) {
    // note that: INT_MAX = 2147483647, So we can only divide these two "number" :num1: and :num2: into length-of-4 segments 
    // and then multiply these segments.

    int num1Length = strlen(num1);
    int num2Length = strlen(num2);

    int segSize1 = num1Length / SEGLENGTH + (num1Length % SEGLENGTH != 0);
    int segSize2 = num2Length / SEGLENGTH + (num2Length % SEGLENGTH != 0);

    int i, j;
    char* seg1;

    for(i = 0; i < segSize1; ++i) {
        // printf("start point = %d\n", num1Length-(i+1)*SEGLENGTH);
        seg1 = strSlice(num1, num1Length-1-i*SEGLENGTH, SEGLENGTH);
        printf("%s\n", seg1);
        for(j = 0; j < segSize2; ++j) {
            break;
        }
    }

    free(seg1);

    return NULL;
}


int main(int argc, char const *argv[])
{
    /* code */
    char* s = "987654321987654321";
    char* t = "12345";

    multiply(s, t);

    return 0;
}