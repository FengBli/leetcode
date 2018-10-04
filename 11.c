// TODO: brute force
int maxArea(int* height, int heightSize) {
    int i, j;
    int maxArea, curArea;
    maxArea = INT_MIN;
    curArea = 0;

    for(i = 0; i < heightSize-1; ++i)
        for(j = i+1; j < heightSize; ++j) {
            curArea = (j - i) * ((height[i] < height[j]) ? height[i] : height[j]);
            if(maxArea < curArea)
                maxArea = curArea;
        }
    return maxArea;
}

// T(n) = O(n)  4ms
int maxArea(int* height, int heightSize) {
    int i, j;
    int curArea, maxArea;
    int curHeight;
    
    i = 0;
    j = heightSize - 1;

    maxArea = INT_MIN;
    curArea = 0;

    while(i != j) {
        if(height[i] > height[j]) {
            curHeight = height[j];
            --j;
        }
        else {
            curHeight = height[i];
            ++i;
        }
        
        curArea = (j - i + 1) * curHeight;

        if(maxArea < curArea)
            maxArea = curArea;
    }
    return maxArea;
}