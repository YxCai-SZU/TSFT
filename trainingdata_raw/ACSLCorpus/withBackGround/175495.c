#include <stdint.h>

/*@
    predicate max_of_three(integer a, integer b, integer c, integer m) =
        (a >= b && a >= c ==> m == a) &&
        (b >= a && b >= c ==> m == b) &&
        (c >= a && c >= b ==> m == c);

    logic integer sum_plus_one(integer a, integer b, integer c) = a + b + c + 1;
*/

/*@
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result <= a + b + c + 1;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;

    //@ assert a <= 100 && b <= 100 && c <= 100;

    if (a >= b && a >= c)
    {
        max = a;
        //@ assert max == a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
        //@ assert max == b;
    }
    else
    {
        max = c;
        //@ assert max == c;
    }

    //@ assert max_of_three(a, b, c, max);
    //@ assert max <= a + b + c;

    return max + 1;
}
