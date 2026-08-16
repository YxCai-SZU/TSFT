#include <limits.h>

/*@
    predicate valid_inputs(integer n, integer white) =
        1 <= n <= 100 && 0 <= white <= n * n;

    logic integer black_value(integer n, integer white) =
        n * n - white;

    predicate valid_output(integer n, integer white, integer black) =
        black == black_value(n, white) && black >= 0;

    lemma multiplication_bounds:
        \forall integer n; 1 <= n <= 100 ==> n * n <= INT_MAX;

    lemma subtraction_nonnegative:
        \forall integer n, white; valid_inputs(n, white) ==> n * n >= white;

    lemma result_bounds:
        \forall integer n, white; valid_inputs(n, white) ==> 
            black_value(n, white) >= 0 && black_value(n, white) <= INT_MAX;
*/

/*@
    requires valid_inputs(n, white);
    ensures valid_output(n, white, \result);
    assigns \nothing;
*/
int func(int n, int white)
{
    int black;
    //@ assert n * n >= white;
    //@ assert (n * n) - white >= 0;
    //@ assert n * n <= INT_MAX;
    
    black = (n * n) - white;
    
    //@ assert black >= 0;
    //@ assert black <= INT_MAX;
    //@ assert black + white == n * n;
    //@ assert black <= n * n;
    //@ assert white <= n * n;
    //@ assert n * n <= INT_MAX;
    //@ assert n >= 1 && n <= 100;
    
    return black;
}
