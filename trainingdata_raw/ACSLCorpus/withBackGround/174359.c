#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t a) {
    // Variable declarations at scope top
    uint64_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    
    result = n * n - a;
    return result;
}
