// TODO: unfinished

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** letterCombinations(char* digits, int* returnSize) {
    int pos[9] = {0, 3, 6, 9, 12, 15, 19, 22, 26};
    int size[9] = {1, 3, 3, 3, 3, 3, 4, 3, 4};
    
    int length;
    int i, j, k, s, cur, numPer, index, remainder;
    char **table;
    char **res;

    length = strlen(digits);
    table = (char**) malloc(sizeof(char*)*8);

    for(i = 0; i < 8; ++i) {
        table[i] = (char*) malloc(sizeof(char*)*(pos[i+1]-pos[i]));
        for(j = pos[i]; j < pos[i+1]; ++j)
            table[i][j-pos[i]] = (char) 'a' + j;
    }

    // for(i = 0; i < 8; ++i) {
    //     for(j = 0; table[i][j]; ++j)
    //         printf("%c ", table[i][j]);
    //     printf("\n");
    // }

    returnSize = malloc(sizeof(int));
    *returnSize = 1;
    
    if(length == 0)
        return "";

    for(i = 0; i < length; ++i) {
        *returnSize *= size[digits[i] - '1'];
    }
    numPer = *returnSize;
    // printf("#permutation = %d\n", *returnSize);

    res = (char**) malloc(sizeof(char*)*(*returnSize));

    for(i = 0; i < *returnSize; ++i) {
        res[i] = (char*) malloc(sizeof(char)*length);
    }

    k = length-1;
    int alreadyHandled = 1;
    printf("intial numPer = %d\n", numPer);
    while(numPer > 1) {
        index = digits[k] - '1';
        remainder = numPer / size[index];
        printf("remainder = %d\n", remainder);
        if(index != 0)
            for(i = 0; i < remainder; ++i) {
                for(s = 1; s < alreadyHandled; ++s) {

                    for(j = 0; j < size[index]; ++j) {
                        res[i*remainder+j*s][k] = table[index-1][j];
                    }
                }
            }

        alreadyHandled *=  size[index];
        numPer /= size[index];
        k--;

    }
    return res;
}