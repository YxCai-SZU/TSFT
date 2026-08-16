#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 0 <= v && v <= 1000000000000000000;
*/

/*@
    requires valid_range(x) && valid_range(y) && valid_range(z);
    ensures \result == (x <= y + z);
    assigns \nothing;
*/
bool func(unsigned long long x, unsigned long long y, unsigned long long z) {
    unsigned long long n;
    
    n = 0;
    /*@
        loop invariant 0 <= n && n <= x;
        loop invariant valid_range(x) && valid_range(y) && valid_range(z);
        loop assigns n;
    */
    while (n < x) {
        n = n + 1;
    }
    
    //@ assert n == x;
    return x <= y + z;
}
