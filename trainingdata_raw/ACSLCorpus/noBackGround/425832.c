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
    size_t ret;
    size_t div_result;

    //@ assert 1 <= a && a <= 20;
    //@ assert 1 <= b && b <= 20;
    //@ assert 1 <= t && t <= 20;

    div_result = t / a;
    //@ assert 0 <= div_result && div_result <= 20;

    //@ assert 0 <= div_result * b && div_result * b <= 400;
    ret = div_result * b;

    //@ assert ret == (((t) / (a)) * (b));
    return ret;
}
