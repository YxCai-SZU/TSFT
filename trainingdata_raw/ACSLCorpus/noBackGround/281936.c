#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures (n < 10 && m < 10) ==> \result == ((n) * (m));
    ensures (n >= 10 || m >= 10) ==> \result == -1;
    assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t m)
{
    int64_t result;
    int64_t n_int;
    int64_t m_int;
    int64_t product;

    if (n >= 10 || m >= 10) {
        result = -1;
        //@ assert (n >= 10 || m >= 10) ==> result == -1;
        return result;
    } else {
        n_int = (int64_t)n;
        m_int = (int64_t)m;
        //@ assert (1 <= (n_int) <= 9);
        //@ assert (1 <= (m_int) <= 9);
        //@ assert 1 <= ((n_int) * (m_int)) <= 81;
        product = n_int * m_int;
        result = product;
        //@ assert (n < 10 && m < 10) ==> result == ((n) * (m));
        return result;
    }
}
