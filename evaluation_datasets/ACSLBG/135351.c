#include <limits.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;

    lemma result_bounds:
        \forall integer a, b, c, r;
        valid_range(a) && valid_range(b) && valid_range(c) &&
        (r == a + b + 1 || r == c) ==>
        0 <= r <= sum_abc(a, b, c);
*/


int func(int a, int b, int c)
{
    int result = 0;

    //@ assert a + b <= 200;
    //@ assert a + b + 1 <= 201;
    //@ assert c <= 100;

    if (c > a + b + 1)
    {
        result = a + b + 1;
    }
    else
    {
        result = c;
    }

    //@ assert result >= 0;
    //@ assert result <= a + b + c;

    return result;
}
