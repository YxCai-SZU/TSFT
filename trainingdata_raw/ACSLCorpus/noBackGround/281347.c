#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (1900 * (n));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    
    if (1 <= m && m <= 3) {
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) >= (100 * ((n) - (m)) + 1900 * (m));
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) <= (1900 * (n));
        result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    } else if (m == 4) {
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) >= (100 * ((n) - (m)) + 1900 * (m));
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) <= (1900 * (n));
        result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    } else {
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) >= (100 * ((n) - (m)) + 1900 * (m));
        //@ assert (100 * ((n) - (m)) + 1900 * (m)) <= (1900 * (n));
        result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    }
    
    return result;
}
