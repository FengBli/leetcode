#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MIN

// Status: AC, 12ms, beats 91.53%

/* return the length of the LIS of input array :nums: */
/* T(n) = O(n^2), S(n) = O(n) */
int lengthOfLIS(int* nums, int numsSize) {

    if(numsSize == 0)
        return 0;
    
    int* size = (int*) malloc(sizeof(int)*numsSize);
    int i, j;
    for(i = 0; i < numsSize; ++i)
        size[i] = 1;
    int max = 1;

    for(i = 1; i < numsSize; ++i) {
        for(j = 0; j < i; ++j) {
            if(nums[i] > nums[j] && size[j] + 1 > size[i]) {
                size[i] = size[j] + 1;
                
                max = (size[i] > max) ? size[i] : max;
            }
        }

    }
    free(size);
    return max;
}

int binarySearch(int *nums, int low, int high, int key) { 

    while (high-low > 1) { 

        int mid = low + (high-low)/2; 

        if (nums[mid] >= key) 
            high = mid; 
        else
            low = mid; 
    } 
  
    return high; 
} 

// Status: AC, 0ms, beats 100%
// T(n) = O(n log n)
int lengthOfLIS2(int *nums, int numsSize) {

    if(0 == numsSize)
        return 0;

    int *size = (int*) malloc(sizeof(int)*numsSize);
    int *aux = (int*) malloc(sizeof(int)*(numsSize+1));

    int i, k, length, max = 1;
    for( i = 1; i <= numsSize; ++i ) {
        aux[i] = INT_MAX;
    }
    aux[0] = INT_MIN;

    length = 1;
    for( i = 0; i < numsSize; ++i ) {

        k = binarySearch(aux, 0, length, nums[i]);

        if(length == k)
            length++;
        
        aux[k] = nums[i];
        size[i] = k;

        max = (size[i] > max) ? size[i] : max;
    }

    return max;
}

int main(int argc, char const *argv[]) {   

    int nums[] = {50, 3, 10, 7, 40, 14, 80};
    // int nums[] = {10,22, 9, 33, 21, 50, 41, 60, 80};

    int SIZE = sizeof(nums) / sizeof(int);

    printf("lenLIS  = %d\n", lengthOfLIS(nums, SIZE));
    printf("lenLIS2 = %d\n", lengthOfLIS2(nums, SIZE));

    return 0;
}