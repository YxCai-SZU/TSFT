#include <stdint.h>

/*@
    predicate is_triangular(integer n, integer ret) =
        n >= 0 && n <= 0x1000 &&
        ret == n * (n + 1) / 2 &&
        ret >= 0;

    logic integer triangular_value(integer n) = n * (n + 1) / 2;

    lemma triangular_bound:
        \forall integer n; 0 <= n <= 0x1000 ==> n * (n + 1) <= 0x1000 * (0x1000 + 1);
*/


uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t sum;
    uint32_t temp;
    uint32_t result;
    
    //@ assert n + 1 >= n;
    temp = n + 1;
    
    //@ assert n * temp >= 0;
    sum = n * temp;
    
    //@ assert sum / 2 >= 0;
    result = sum / 2;
    
    return result;
}
