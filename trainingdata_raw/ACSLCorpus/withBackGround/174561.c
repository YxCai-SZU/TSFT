#include <stdint.h>

/*@
    predicate is_sign_result(integer x, integer r) =
        (x < 0 ==> r == -1) &&
        (x == 0 ==> r == 0) &&
        (x > 0 ==> r == 1);
 */

/*@
    requires -0x8000000000000000 <= x <= 0x7FFFFFFFFFFFFFFF;
    ensures \result == 0 || \result == 1 || \result == -1;
    ensures is_sign_result(x, \result);
 */
int64_t func(int64_t x)
{
    int64_t result;
    //@ ghost int64_t x_spec = x;

    if (x < 0)
    {
        //@ assert x_spec < 0;
        result = -1;
    }
    else if (x == 0)
    {
        //@ assert x_spec == 0;
        result = 0;
    }
    else
    {
        //@ assert x_spec > 0;
        result = 1;
    }

    //@ assert is_sign_result(x_spec, result);
    return result;
}
