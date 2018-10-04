// Status: AC, 0ms, beats 100%
char* addBinary(char* a, char* b) {
    #include <string.h>
    int aLen, bLen, cLen, minLen, maxLen;
    int curSum, i, k, aIsLonger;
    char carry = '0';
    char *c;    // result
    
    aLen = strlen(a);
    bLen = strlen(b);
    
    if(aLen > bLen) {
        aIsLonger = 1;
        minLen = bLen;
        maxLen = aLen;
    } else {
        aIsLonger = 0;
        minLen = aLen;
        maxLen = bLen;
    }
    
    cLen = maxLen + 1;
    
    c = (char*) malloc(sizeof(char) * (cLen+1));
    c[cLen] = '\0';

    for(k = 1; k <= minLen; ++k) {
        curSum = a[aLen-k] + b[bLen-k] + carry;
        if(curSum == '1' + '1' + '0') {
            carry = '1';
            c[cLen-k] = '0';
        } else if(curSum == '1' + '1' + '1') {
            carry = '1';
            c[cLen-k] = '1';
        } else {
            carry = '0';
            if(curSum == '1' + '0' + '0')
                c[cLen-k] = '1';
            else 
                c[cLen-k] = '0';
        }
    }
    
    if(aIsLonger)
        while(k <= maxLen) {
            curSum = a[aLen-k] + carry;
            if(curSum == '1'*2) {
                carry = '1';
                c[cLen-k] = '0';
            } else {
                carry = '0';
                if(curSum == '0' + '0')
                    c[cLen-k] = '0';
                else
                    c[cLen-k] = '1';
            }
            ++k;
        }
    else
        while(k <= maxLen) {
            curSum = b[bLen-k] + carry;
            if(curSum == '1'*2) {
                carry = '1';
                c[cLen-k] = '0';
            } else {
                carry = '0';
                if(curSum == '0' + '0')
                    c[cLen-k] = '0';
                else
                    c[cLen-k] = '1';
            }
            ++k;
        }
    if(carry == '1') {
        c[0] = '1';
        return c;
    }
    
    return &c[1];
    
}