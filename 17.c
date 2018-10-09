// Status: AC, 0ms, beats 100%

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits, int* returnSize) {
    int size[9] = {0, 3, 3, 3, 3, 3, 4, 3, 4};
    int pos[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};  // used for generating :table:, not want to input by-hand
    
    int i, j, k;
    int digitsSize, start, stepSize, curPos, returnSizeCopy, index, remainder;
    char **table;
    char **res ;

    digitsSize = strlen(digits);
    table = (char**) malloc(sizeof(char*)*8);

    // generate the table
    for(i = 0; i < 8; ++i) {
        table[i] = (char*) malloc(sizeof(char*)*(pos[i+1]-pos[i]));
        for(j = pos[i]; j < pos[i+1]; ++j)
            table[i][j-pos[i]] = (char) 'a' + j;
    }

    // returnSize = malloc(sizeof(int));    // TODO: notice this, don't do it again!
    *returnSize = (digitsSize != 0);

    // calculate :*returnSize:
    for(i = 0; i < digitsSize; ++i) 
        *returnSize *= size[digits[i] - '1'];
    returnSizeCopy = *returnSize;

    res = (char**) malloc(sizeof(char*)* *returnSize);
    for(i = 0; i < *returnSize; ++i)
        res[i] = (char*) malloc(sizeof(char)*(digitsSize+1));

    curPos = digitsSize;
    stepSize = 1;
    while(--curPos >= 0) {
        start = 0;
        index = digits[curPos] - '1';
        remainder = returnSizeCopy / size[index];

        for(i = 0; size[index]&&(i<remainder); ++i) {
            for(j = 0; j < size[index]; ++j) {
                for(k = 0; k < stepSize; ++k) {
                    res[start++][curPos] = table[index-1][j];   
                    // this will always do :*returnSize: times each while-iteration
                }
            }
        }

        stepSize *=  size[index];
        returnSizeCopy = remainder;
    }

    for(i = 0; i < *returnSize; ++i)
        res[i][digitsSize] = '\0'; 

    for(i = 0; i < 8; ++i)
        free(table[i]);
    free(table);
    

    return res;
}