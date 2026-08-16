#include <stddef.h>

/*@
    requires (1 <= (a) && (a) <= 20 &&
        1 <= (b) && (b) <= 20 &&
        1 <= (t) && (t) <= 20);
    ensures \result == (((t) / (a)) * (b));
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    // Variable declarations at scope top
    size_t ret;

    //@ assert (1 <= (a) && (a) <= 20 &&         1 <= (b) && (b) <= 20 &&         1 <= (t) && (t) <= 20);
    //@ assert t / a <= 20;
    //@ assert (t / a) * b <= 400;

    ret = (t / a) * b;
    return ret;
}
