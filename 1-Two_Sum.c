#include <stdlib.h> 
#include <stdbool.h> 
// brute force
int* twoSum(int* nums, int numsSize, int target) {
    int i, j, flag = 0;
    for (i = 0; i < numsSize; ++i) {
        for (j = i + 1; j < numsSize; ++j) {
            if ((nums[i] + nums[j]) == target)
                flag = 1;
            if (flag == 1)
                break;
        }
        if(flag == 1)
            break;
    }
    int *res = (int *) malloc(sizeof(int) * 2);
    res[0] = i;
    res[1] = j;
    return res;
}

// Status: AC, 24ms, beats 90.68%
int* twoSum(int *nums, int numsSize, int target) {
    int *complements, *res;
    int i, j, complement;
    bool flag;

    flag = false;
    complements = (int*) malloc(sizeof(int)*numsSize);
    for(i = 0; i < numsSize; ++i) {
        for(j = 0; j < i; ++j) {
            if(complements[j] == nums[i]) {
                flag = true;
                break;
            }
        }
        if(flag)
            break;
        complements[i] = target - nums[i];
    }

    if(!flag) 
        return NULL;

    res = (int*) malloc(sizeof(int)*2);
    res[0] = j;
    res[1] = i;

    return res;
}