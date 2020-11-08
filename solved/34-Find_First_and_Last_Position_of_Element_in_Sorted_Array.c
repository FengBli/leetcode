// Status: AC, 4ms, beats 100%

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* binSearch(int* nums, int start, int end, int target, int returnSize) {
    int* res = malloc(sizeof(int) * returnSize);

    if(start==end && target==nums[start]) {
        res[0] = start;
        if(returnSize==2)
            res[1] = start;
        return res;
    } else if(start==end) {
        res[0] = -1;
        if(returnSize==2)
            res[1] = -1;
        return res;
    }

    int mid, low, high;
    mid = (start + end) / 2;
    if(target < nums[mid]) 
        return binSearch(nums, start, mid, target, 2);
    else if(target > nums[mid])
        return binSearch(nums, mid+1, end, target, 2);
    else {
        low = (binSearch(nums, start, mid, target, 2))[0];
        high = (binSearch(nums, mid+1, end, target, 2))[1];
        if(high==-1)
            high = mid;
        res[0] = low;
        res[1] = high;
        return res;
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    return binSearch(nums, 0, numsSize-1, target, 2);

}