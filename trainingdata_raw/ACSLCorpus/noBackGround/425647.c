#include <stdint.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures (n > 9 || m > 9) ==> \result == -1;
    ensures (n <= 9 && m <= 9) ==> \result == n * m;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    uint32_t product_unsigned;
    int32_t product;
    
    n_unsigned = (uint32_t)n;
    m_unsigned = (uint32_t)m;
    
    if (n_unsigned > 9 || m_unsigned > 9) {
        product_unsigned = 0xFFFFFFFF;
    } else {
        //@ assert 1 <= n_unsigned <= 9 && 1 <= m_unsigned <= 9;
        //@ assert n_unsigned * m_unsigned <= 81;
        product_unsigned = n_unsigned * m_unsigned;
    }
    
    if (n > 9 || m > 9) {
        product = -1;
    } else {
        product = (int32_t)product_unsigned;
    }
    
    //@ assert (n > 9 || m > 9) ==> product == -1;
    //@ assert (n <= 9 && m <= 9) ==> product == n * m;
    
    return product;
}
