#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_params(integer n, integer k, long *h) =
        1 <= n <= 100000 &&
        1 <= k <= 500 &&
        \valid(h + (0 .. n-1)) &&
        \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;

    predicate loop_invariant(integer n, integer k, long *h, 
                             integer index, integer cnt) =
        0 <= index <= n &&
        0 <= cnt <= index &&
        \forall integer i; 0 <= i < index ==> h[i] >= 1 && h[i] <= 500 &&
        valid_params(n, k, h) &&
        cnt <= n;
*/

/*@
    requires valid_params(n, k, h);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
long func(long n, long k, const long *h) {
    long cnt = 0;
    size_t index = 0;
    
    /*@
        loop invariant loop_invariant(n, k, h, index, cnt);
        loop assigns index, cnt;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        //@ assert 0 <= index < n;
        
        if (k <= h[index]) {
            cnt = cnt + 1;
        }
        
        index = index + 1;
    }
    
    return cnt;
}
