#include <stdbool.h>


int func(int n, int r)
{
    int max_val;
    int ans;

    //@ assert (1 <= (n) && (n) <= 100 && 0 <= (r) && (r) <= 4111);
    
    if (n > 10) {
        max_val = n;
    } else {
        max_val = 10;
    }
    
    ans = r + 100 * (max_val - n);
    
    //@ assert n >= 10 ==> ans == r;
    //@ assert n < 10 ==> ans == r + 100 * (10 - n);
    
    return ans;
}
