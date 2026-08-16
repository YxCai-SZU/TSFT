#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    ensures \result == ((a) * (1 + (a) * (1 + (a))));
    assigns \nothing;
*/
int32_t func(int32_t a)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert 1 <= a <= 100;
    //@ assert 1 + a * (1 + a) >= 1;
    //@ assert 1 + a * (1 + a) <= 101 * 101;
    //@ assert a * (1 + a * (1 + a)) >= 1;
    //@ assert a * (1 + a * (1 + a)) <= 100 * 101 * 101;

    result = a * (1 + a * (1 + a));
    return result;
}
