#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
    ensures \result <= 10000;
    assigns \nothing;
*/
long func(long a, long b, long c, long d) {
    long max_val;
    
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;
    
    if (a * b > c * d) {
        max_val = a * b;
    } else {
        max_val = c * d;
    }
    
    //@ assert max_val >= 1;
    
    return max_val;
}
