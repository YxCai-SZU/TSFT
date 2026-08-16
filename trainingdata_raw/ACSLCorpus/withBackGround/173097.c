#include <stdbool.h>

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        (a - b >= c) ? 0 : c - (a - b);

    lemma ans_properties:
        \forall integer a, b, c;
        valid_input(a, b, c) ==>
        compute_ans(a, b, c) >= 0 &&
        compute_ans(a, b, c) <= c &&
        (a - b >= c ==> compute_ans(a, b, c) == 0) &&
        (a - b < c ==> compute_ans(a, b, c) == c - (a - b));
*/

/*@
    requires valid_input(a, b, c);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (a - b >= c) ==> \result == 0;
    ensures (a - b < c) ==> \result == c - (a - b);
*/
int func(int a, int b, int c)
{
    int minus;
    int ans;

    //@ assert valid_input(a, b, c);
    
    minus = a - b;
    
    //@ assert minus == a - b;
    
    if (c - minus < 0)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = c - minus;
        //@ assert ans == c - minus;
    }
    
    //@ assert (a - b >= c) ==> ans == 0;
    //@ assert (a - b < c) ==> ans == c - (a - b);
    
    return ans;
}
