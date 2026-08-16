#include <stdint.h>

/*@ predicate m_ge_n(integer m, integer n) = m >= n; */

/*@
    requires 1 <= n <= 100;
    requires 0 <= m <= n;
    ensures m_ge_n(m, n) ==> \result == 1;
    ensures !m_ge_n(m, n) ==> \result == 1919810;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    
    if (m >= n) {
        result = 1;
    } else {
        //@ assert 1919810 >= 0 && 1919810 <= 2147483647;
        result = 1919810;
    }
    
    return result;
}
