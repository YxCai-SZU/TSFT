#include <stdint.h>

/*@ predicate valid_params(integer n, integer m) =
        1 <= n && n <= 100 &&
        0 <= m && m <= n * n;
*/

/*@ logic integer square(integer n) = n * n; */

/*@ lemma square_bound: 
        \forall integer n; 1 <= n && n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result >= 0;
    ensures \result <= n * n;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at scope top
    int32_t result;
    uint64_t n_sq;
    
    // Precondition verification
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    
    n_sq = (uint64_t)n * (uint64_t)n;
    
    //@ assert n_sq <= 10000;
    
    if (n_sq == m) {
        result = 0;
    } else if (n_sq > m) {
        //@ assert n_sq - m >= 0;
        //@ assert n_sq - m <= n_sq;
        result = (int32_t)(n_sq - m);
    } else {
        //@ assert m - n_sq >= 0;
        //@ assert m - n_sq <= n_sq;
        result = (int32_t)(m - n_sq);
    }
    
    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= n * n;
    
    return result;
}
