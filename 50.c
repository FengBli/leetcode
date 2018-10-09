// Status: AC, 4ms, beats 100%
double myPow(double x, int n) {
    // base cases
    if(x == 0 || x == 1.0)
        return x;
    
    // base cases
    if(x == -1.0)
        if(n & 1)
            return -1.0;
        else
            return 1.0;
    
    double res = 1.0;

    // handling negative power
    if(n < 0) {
        n = -1 * n;
        x = 1.0 / x; 
    }
    
    while(n) {
        if(n & 1)
            res *= x;
        
        x *= x;

        // beyond the precision of double
        if(x == 0.0)
            return 0.0;
        
        n = n >> 1;
    }
    return res;
}