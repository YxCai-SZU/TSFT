#include <stdint.h>


int32_t func(uint32_t n, uint32_t m)
{
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    int32_t result;

    n_unsigned = n;
    m_unsigned = m;

    //@ assert n_unsigned <= 100 && m_unsigned <= 100;

    if (n_unsigned == m_unsigned) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}
