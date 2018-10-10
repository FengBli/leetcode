// Status: AC, 12ms, beats 100%

/*
A      |I      |T   //each pattern only contains one char
-----------------
B   H  |J   S  |    // each pattern contains 2 chars each line
C  G   |K  R   |
D F    |O Q    |
-----------------
E      |P      |    // each pattern only contains one char

consider each as a pattern with length: *basic* = numRows+(numRows-2) = 2*numRows - 2;
So there are *numPatterns* = strlen(s) / basic + (length%basic != 0) patterns.

First line: 
    chars in first line have their indexes satisfying: index%basic == 0

Middle lines:
    chars in i-th line have their indexes satisfying:     (1 < i < basic/2)
        +----->front ones: index%basic==i
        +----->rear  ones: index%basic==basic-i

Last line:
    chars in (basic/2)-th line have indexes: index%basic==basic/2


Then just do the reverse: given mod and pattern-index, compute the index
*/

char* convert(char* s, int numRows) {
    int length, basic, numPatterns;
    int pattern, mod;
    int i;
    char *res;

    length = strlen(s);

    if(length <= 1 || numRows <= 1)
        return s;

    basic = 2 * numRows - 2;
    if(numRows >= length)
        return s;

    numPatterns = length / basic + (length%basic != 0);
    i = 0;
    res = malloc(sizeof(char)*(length+1));
    
    // first line
    for(pattern = 0; pattern < numPatterns; ++pattern) {
        res[i++] = s[pattern*basic];
    }

    // middle lines
    for(mod = 1; mod < basic/2; ++mod) {
        for(pattern = 0; pattern < numPatterns; ++pattern) {
            if(pattern*basic+mod < length)
                res[i++] = s[pattern*basic+mod];
            if((pattern+1)*basic-mod < length)
                res[i++] = s[(pattern+1)*basic-mod];
        }
    }

    // last line
    if(length%basic > basic/2) // check whether last pattern has last line
        numPatterns++;

    for(pattern = 0; pattern < numPatterns; ++pattern) {
        res[i++] = s[pattern*basic+basic/2];
    }

    res[length] = '\0';
    return res;
}