#include <stdint.h>

/*@
    requires (1 <= (n) <= 20) && (1 <= (m) <= 20);
    ensures (n <= 9 && m <= 9 ==> \result == m * n) &&
            (n > 9 || m > 9 ==> \result == -1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t max_val;
    int32_t result;

    //@ assert (1 <= (n) <= 20) && (1 <= (m) <= 20);
    
    if (n > m) {
        max_val = n;
    } else {
        max_val = m;
    }

    if (max_val <= 9) {
        //@ assert n <= 9 && m <= 9;
        //@ assert m * n <= 81;
        result = (int32_t)(m * n);
    } else {
        //@ assert n > 9 || m > 9;
        result = -1;
    }

    return result;
}
