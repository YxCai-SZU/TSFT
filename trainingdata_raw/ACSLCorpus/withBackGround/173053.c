#include <stdint.h>

/*@ predicate m_in_range(integer m) = 1 <= m && m <= 20; */

/*@
    requires 1 <= n && n <= 20;
    requires m_in_range(m);
    ensures (m < 6 && \result == 0) || (m >= 6 && m <= 20 && \result == 1) || (m > 20 && \result == -1);
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t result;
    
    if (m < 6) {
        result = 0;
    } else if (m <= 20) {
        result = 1;
    } else {
        //@ assert m > 20 && m <= 20;
        result = -1;
    }
    
    return result;
}
