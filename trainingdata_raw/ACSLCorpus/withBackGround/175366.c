#include <stdbool.h>

/*@
    predicate scaled_in_range(integer v) =
        0 <= v && v <= 10000;

    logic integer scaled_value(integer v) = v * 100;

    lemma scaled_bounds:
        \forall integer a, b, x;
            0 <= a <= 100 && 0 <= b <= 100 && 0 <= x <= 100 ==>
            scaled_in_range(scaled_value(a)) &&
            scaled_in_range(scaled_value(b)) &&
            scaled_in_range(scaled_value(x));
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= x <= 100;
    ensures \result == (x >= 0 && a <= x && x <= a + b);
*/
bool func(long a, long b, long x)
{
    long scale_factor;
    long scaled_a;
    long scaled_b;
    long scaled_x;
    bool result;

    scale_factor = 100;
    
    //@ assert scaled_in_range(a * scale_factor);
    scaled_a = a * scale_factor;
    
    //@ assert scaled_in_range(b * scale_factor);
    scaled_b = b * scale_factor;
    
    //@ assert scaled_in_range(x * scale_factor);
    scaled_x = x * scale_factor;

    //@ assert scaled_a >= 0 && scaled_a <= 10000;
    //@ assert scaled_b >= 0 && scaled_b <= 10000;
    //@ assert scaled_x >= 0 && scaled_x <= 10000;

    if (scaled_x >= scaled_a && scaled_x <= scaled_a + scaled_b)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
