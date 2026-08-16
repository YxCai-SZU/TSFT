#include <stddef.h>

/*@
    requires (2 <= (a) && (a) <= 100 &&
        2 <= (b) && (b) <= 100);
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    // Variable declarations at scope top
    size_t res;

    //@ assert a > 1 && b > 1;
    //@ assert a <= 100 && b <= 100;
    //@ assert (a - 1) * (b - 1) <= 9801;

    res = (a - 1) * (b - 1);
    //@ assert res == (((a) - 1) * ((b) - 1));
    return res;
}
