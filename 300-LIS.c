#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Status: AC, 12ms, beats 91.53%
// TODO: there is a O(n log n) solution

/* return the length of the LIS of input array :nums: */
int LIS(int *nums, int len) {
    int* size = (int*) malloc(sizeof(int)*len);
    int i, j;
    for(i = 0; i < len; ++i)
        size[i] = 1;
    int max = INT_MIN;

    for(i = 1; i < len; ++i) {
        for(j = 0; j < i; ++j) {
            if(nums[i] > nums[j] && size[j] + 1 > size[i]) {
                size[i] = size[j] + 1;
                if(size[i] > max) 
                    max = size[i];
            }
        }

    }
    return max;
}

int main(int argc, char const *argv[])
{   
    int SIZE = 6;
    // int nums[9] = {10,22, 9, 33, 21, 50, 41, 60, 80};
    int nums[] = {50, 3, 10, 7, 40, 80};

    int lenLIS = LIS(nums, SIZE);
    printf("lenLIS = %d\n", lenLIS);

    return 0;
}