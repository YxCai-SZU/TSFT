#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        c - (a - b);

    logic integer final_result(integer a, integer b, integer c) =
        compute_result(a, b, c) < 0 ? 0 : compute_result(a, b, c);

    lemma result_properties:
        \forall integer a, b, c;
        valid_range(a, b, c) ==>
        (
            final_result(a, b, c) >= 0 &&
            final_result(a, b, c) <= c &&
            (
                final_result(a, b, c) == compute_result(a, b, c) ||
                final_result(a, b, c) == 0
            )
        );
*/

/*@
    requires valid_range(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures \result == compute_result(a, b, c) || \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    int tmp;

    //@ assert valid_range(a, b, c);
    
    tmp = c - (a - b);
    
    //@ assert tmp == compute_result(a, b, c);
    
    if (tmp < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = tmp;
        //@ assert result == compute_result(a, b, c);
    }
    
    //@ assert result == final_result(a, b, c);
    
    return result;
}
