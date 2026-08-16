#include <stdint.h>

/*@
    predicate is_valid_n(integer n) = 0 <= n <= 1000;
    predicate is_valid_m(integer m) = 0 <= m <= 99;
    
    logic integer compute_mul(integer m) = m * 21;
    
    lemma mul_bounds:
        \forall integer m; is_valid_m(m) ==> 0 <= compute_mul(m) <= 2079;
*/

/*@
    requires 1 <= N <= 100000;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (N % 100) * 21 < N;
    ensures \result == 0 ==> (N % 100) * 21 >= N;
*/
uint32_t func(uint32_t N) {
    uint32_t n;
    uint32_t m;
    uint32_t result;
    
    n = N / 100;
    m = N % 100;
    
    //@ assert is_valid_n(n);
    //@ assert is_valid_m(m);
    
    if (m * 21 < N) {
        //@ assert m * 21 < N;
        result = 1;
    } else {
        //@ assert m * 21 >= N;
        result = 0;
    }
    
    return result;
}
