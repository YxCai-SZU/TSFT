#include <stdint.h>

/*@ requires (1 <= (n) <= 100 &&
      1 <= (m) <= 100 &&
      1 <= (a) <= 100 &&
      1 <= (b) <= 100 &&
      (a) < (b) &&
      (b) < (n) + (m));
    ensures \result >= 0 && \result <= n;
*/
int32_t func(int32_t n, int32_t m, int32_t a, int32_t b)
{
    uint32_t n_u;
    uint32_t m_u;
    uint32_t a_u;
    uint32_t b_u;
    uint32_t result_u;
    int32_t result;

    //@ assert b - a >= 0;
    n_u = (uint32_t)n;
    m_u = (uint32_t)m;
    a_u = (uint32_t)a;
    b_u = (uint32_t)b;

    //@ assert b_u - a_u >= 0;
    //@ assert b_u - a_u <= n_u + m_u;

    if (n_u >= b_u - a_u) {
        result_u = n_u - (b_u - a_u);
    } else {
        result_u = 0;
    }

    //@ assert result_u >= 0;
    //@ assert result_u <= n_u;

    result = (int32_t)result_u;
    return result;
}
