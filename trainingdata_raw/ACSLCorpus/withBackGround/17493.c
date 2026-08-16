#include <stdint.h>

/*@
    predicate is_valid_input(integer a, integer b, integer c) =
        0 <= a && a <= 100 &&
        0 <= b && b <= 100 &&
        0 <= c && c <= 100;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a >= b && a >= c) ? a :
        (b >= a && b >= c) ? b :
        c;

    lemma max_in_range:
        \forall integer a, b, c;
            is_valid_input(a, b, c) ==>
            max_of_three(a, b, c) >= 0 && max_of_three(a, b, c) <= 100;
*/

/*@
    requires is_valid_input(a, b, c);
    ensures \result >= 1 && \result <= 3;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t max;

    //@ assert is_valid_input(a, b, c);

    if (a >= b && a >= c)
    {
        max = a;
    }
    else if (b >= a && b >= c)
    {
        max = b;
    }
    else
    {
        max = c;
    }

    //@ assert max == max_of_three(a, b, c);
    //@ assert max >= 0 && max <= 100;

    if (max % 3 == 0)
    {
        //@ assert max % 3 == 0;
        return 3;
    }
    else if (max % 2 == 0)
    {
        //@ assert max % 2 == 0;
        return 2;
    }
    else
    {
        //@ assert max % 3 != 0 && max % 2 != 0;
        return 1;
    }
}
