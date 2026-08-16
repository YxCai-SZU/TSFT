#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 && 1 <= c && c <= 20;

    logic integer compute_result(integer a, integer b, integer c) =
        (c < (a - b)) ? 0 : (c - (a - b));

    lemma result_properties:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
            compute_result(a, b, c) >= 0 &&
            compute_result(a, b, c) <= c &&
            (c < a - b ==> compute_result(a, b, c) == 0) &&
            (c >= a - b ==> compute_result(a, b, c) == c - a + b);
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures c < a - b ==> \result == 0;
    ensures c >= a - b ==> \result == c - a + b;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int x;
    int ans;

    x = a - b;

    //@ assert x == a - b;

    if (c < x)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = c - x;
        //@ assert ans == c - x;
    }

    //@ assert ans == compute_result(a, b, c);
    return ans;
}
