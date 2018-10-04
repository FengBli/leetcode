// Status: AC, 12ms, beats 100%, cheating version using *double*
int myAtoi(char* str) {

    int length;
    int i, flag, hasFlag, frontWhitespace, numBegins;
    double res;

    length = strlen(str);
    res = 0;
    flag = true;
    hasFlag = true;
    frontWhitespace = true; // for cases like "   23" and "2 3"
    numBegins = false;  // for cases like "0-1"

    for(i = 0; i < length; ++i) {
        // skip only the front whitespaces
        if(frontWhitespace && str[i] == ' ')
            continue;
        else
            frontWhitespace = false;
        
        if(!numBegins && hasFlag && (str[i] == '-' || str[i] == '+')) {
            
            hasFlag = false;

            if(str[i] == '-')
                flag = false;

            continue;
        }

        if(str[i] >= '0' && str[i] <= '9') {
            res = res*10 + (str[i] - '0');
            numBegins = true;
        } else 
            break;
    }

    if(!hasFlag)
        if(!flag)
            res = -1 * res;

    // printf("%f\n", res);

    if(res >= INT_MAX)
        return INT_MAX;
    else if(res <= INT_MIN)
        return INT_MIN;
    else
        return (int) res;
}

//Status: AC 12ms, beats 100%
int myAtoi(char* str) {
    /* Notice: this code comes from www.geeksforgeeks.org */
    int sign = 1, base = 0, i = 0;

    // skip the front whitespaces
    while(str[i] == ' ')
        ++i;

    // sign of number
    if(str[i] == '-' || str[i] == '+') {
        sign = 1 - 2 * (str[i] == '-');
        ++i;
    }

    // checking for valid number
    while(str[i] >= '0' && str[i] <= '9') {
        // handling overflow test case
        if(base > INT_MAX/10 || (base == INT_MAX/10 && (str[i]-'0' > 7)))
            if(sign==1)
                return INT_MAX;
            else
                return INT_MIN;
        base = base*10 + (str[i] - '0');
        ++i;
    }

    return base*sign;
}