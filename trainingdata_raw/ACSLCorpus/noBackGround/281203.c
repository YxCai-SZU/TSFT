#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 1 <= a && a <= 10;
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    //@ assert 1 <= a * a && a * a <= 100;
    //@ assert 3 <= a + a * a + a * a * a && a + a * a + a * a * a <= 1110;

    result = a + a * a + a * a * a;
    return result;
}
