#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b <= a <= 20 && 1 <= c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (a - b >= c) ? 0 : c - (a - b);

    lemma result_properties:
        \forall integer a, b, c;
        valid_range(a, b, c) ==>
        compute_result(a, b, c) >= 0 &&
        compute_result(a, b, c) <= c &&
        (a - b >= c ==> compute_result(a, b, c) == 0) &&
        (a - b < c ==> compute_result(a, b, c) == c - (a - b));
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0 && \result <= c;
    ensures (a - b >= c) ==> \result == 0;
    ensures (a - b < c) ==> \result == c - (a - b);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert a - b >= 0;
    //@ assert a - b <= 20;
    //@ assert c >= 0;
    //@ assert c <= 20;
    
    if (c > (a - b))
    {
        result = c - (a - b);
    }
    else
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result <= c;
    
    if (a - b >= c)
    {
        return 0;
    }
    else
    {
        return c - (a - b);
    }
}
