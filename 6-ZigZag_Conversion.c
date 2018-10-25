// Status: AC, 12ms, beats 100%

/*
+-------+-------+-------+
|A      |I      |T      | // 1 char
|B   H  |J   S  |       | // 2 chars
|C  G   |K  R   |       | // 2 chars
|D F    |O Q    |       | // 2 chars
|E      |P      |       | // 1 char
+-------+-------+-------+

consider each box as a pattern with length: :patternSize: = numRows+(numRows-2) = 2*numRows - 2;
So there are :numPatterns: = strlen(s) / patternSize + (length%patternSize != 0) patterns.

First line: 
    chars in first line have their indexes satisfying: index % patternSize == 0

Middle lines:
    chars in i-th line have their indexes satisfying:     (1 < i < patternSize/2)
        +-----> first char: index % patternSize == i
        +----->  last char: index % patternSize == patternSize - i

Last line:
    chars in (patternSize/2)-th line have indexes: index % patternSize == patternSize / 2

Then just do the reverse: given mod and pattern-index, compute the index
*/

char* convert(char* s, int numRows) {
    int length, patternSize, numPatterns;
    int pattern, mod;
    int i;
    char *res;

    length = strlen(s);

    if(length <= 1 || numRows <= 1)
        return s;

    patternSize = 2 * numRows - 2;
    if(numRows >= length)
        return s;

    numPatterns = length / patternSize + (length%patternSize != 0);
    i = 0;
    res = malloc(sizeof(char)*(length+1));
    
    // first line
    for(pattern = 0; pattern < numPatterns; ++pattern) {
        res[i++] = s[pattern*patternSize];
    }

    // middle lines
    for(mod = 1; mod < patternSize/2; ++mod) {
        for(pattern = 0; pattern < numPatterns; ++pattern) {
            if(pattern*patternSize+mod < length)
                res[i++] = s[pattern*patternSize+mod];
            if((pattern+1)*patternSize-mod < length)
                res[i++] = s[(pattern+1)*patternSize-mod];
        }
    }

    // last line
    if(length%patternSize > patternSize/2) // check whether last pattern has last line
        numPatterns++;

    for(pattern = 0; pattern < numPatterns; ++pattern) {
        res[i++] = s[pattern*patternSize+patternSize/2];
    }

    res[length] = '\0';
    return res;
}