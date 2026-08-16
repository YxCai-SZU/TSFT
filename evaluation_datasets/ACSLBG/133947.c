#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n <= 1000000000000 &&
        1 <= m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        n + m / 2;

    logic integer lower_bound(integer n, integer m) =
        m / 4;
*/


uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t min_val;
    uint64_t max_val;
    
    //@ assert valid_input(n, m);
    
    if (n < m / 2) {
        min_val = n;
    } else {
        min_val = m / 2;
    }
    
    if (n + m / 4 >= m / 2) {
        max_val = m / 2;
    } else {
        max_val = n + m / 4;
    }
    
    //@ assert max_val <= n + m / 2;
    //@ assert max_val >= m / 4;
    
    return max_val;
}
