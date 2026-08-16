#include <stdbool.h>

/*@
    predicate r_invariant(integer r, integer n) =
        0 <= r <= n &&
        r % 3 == n % 3;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (n % 3 <= k);
*/
bool func(unsigned long n, unsigned long k) {
    unsigned long r = n;
    
    /*@
        loop invariant r_invariant(r, n);
        loop assigns r;
        loop variant r;
    */
    while (r >= 3) {
        //@ assert r >= 3;
        r -= 3;
    }
    
    //@ assert r == n % 3;
    return r <= k;
}
