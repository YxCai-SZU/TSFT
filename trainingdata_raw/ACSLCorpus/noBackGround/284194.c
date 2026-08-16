#include <limits.h>

/*@
    requires ((n) >= 1) && ((k) >= 1);
    ensures ((\result) >= 0) && \result <= 1;
    assigns \nothing;
*/
int func(long n, long k) {
    long abs_n;
    long abs_k;
    int result;
    
    //@ assert n >= 1 && k >= 1;
    
    if (n < 0) {
        abs_n = -n;
    } else {
        abs_n = n;
    }
    
    if (k < 0) {
        abs_k = -k;
    } else {
        abs_k = k;
    }
    
    //@ assert abs_n >= 0;
    //@ assert abs_k > 0;
    
    /*@
        loop invariant abs_n >= 0;
        loop invariant abs_k > 0;
        loop assigns abs_n;
        loop variant abs_n;
    */
    while (abs_n >= abs_k) {
        abs_n -= abs_k;
        //@ assert abs_n >= 0;
    }
    
    //@ assert abs_n < abs_k;
    
    if (abs_n == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    return result;
}
