#include <stdint.h>

/*@
    requires (1 <= (a) <= 3 && 1 <= (b) <= 3 && (a) != (b));
    ensures \result == (6 - ((a) + (b)));
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 6 >= (int32_t)a + (int32_t)b;
    //@ assert 6 - ((int32_t)a + (int32_t)b) >= 1;
    //@ assert 6 - ((int32_t)a + (int32_t)b) <= 3;

    result = 6 - ((int32_t)a + (int32_t)b);
    return result;
}
