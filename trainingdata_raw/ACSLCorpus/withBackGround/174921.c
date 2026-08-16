#include <stdint.h>

/*@ predicate in_range(integer v) = -100 <= v <= 100; */

/*@
    logic integer max_of_three(integer x, integer y, integer z) =
        (x >= y && x >= z) ? x : ((y >= x && y >= z) ? y : z);
*/

/*@
    lemma mul_in_range:
        \forall integer a, b;
            in_range(a) && in_range(b) ==> -10000 <= a * b <= 10000;
*/

/*@
    requires in_range(a) && in_range(b);
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t add;
    int64_t sub;
    int64_t mul;
    int64_t result;

    add = a + b;
    sub = a - b;

    //@ assert -10000 <= a * b <= 10000;
    mul = a * b;

    if (add >= sub && add >= mul)
    {
        result = add;
    }
    else if (sub >= add && sub >= mul)
    {
        result = sub;
    }
    else
    {
        result = mul;
    }

    //@ assert result == max_of_three(add, sub, mul);
    return result;
}
