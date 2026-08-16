#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) * (1 + (a) + (a) * (a)));
    assigns \nothing;
*/
size_t func(size_t a)
{
    // Variable declarations at top of scope
    size_t res;

    //@ assert a >= 1 && a <= 10;
    //@ assert a + a <= 2 * 10;
    //@ assert a * a <= 10 * 10;
    //@ assert a * a * a <= 10 * 10 * 10;
    //@ assert a + a * a + a * a * a <= 10 + 100 + 1000;
    //@ assert a * (1 + a + a * a) <= 10 * 1111;

    res = a * (1 + a + a * a);
    return res;
}
