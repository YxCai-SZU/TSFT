#include <stdint.h>

/*@
    predicate valid_range(integer x) = 0 <= x <= 23;

    logic integer mod24(integer a, integer b) =
        a + b < 24 ? a + b : a + b - 24;
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    ensures \result >= 0;
    ensures \result <= 23;
    ensures \result == mod24(a, b);
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    
    if (a + b < 24)
    {
        //@ assert a + b >= 0;
        //@ assert a + b <= 23;
        result = a + b;
    }
    else
    {
        //@ assert a + b - 24 >= 0;
        //@ assert a + b - 24 <= 23;
        result = a + b - 24;
    }
    
    //@ assert result == mod24(a, b);
    return result;
}
