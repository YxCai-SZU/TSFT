#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= b && b <= a && a <= 20 &&
        1 <= c && c <= 20;

    logic integer compute_ans(integer a, integer b, integer c) =
        c - a + b;

    lemma ans_bound:
        \forall integer a, b, c;
        valid_range(a, b, c) ==>
        compute_ans(a, b, c) <= a - b + c;
*/


int func(int a, int b, int c)
{
    int ans;
    int res;

    ans = c - a + b;

    //@ assert ans >= 0 || ans < 0;

    if (ans < 0)
    {
        res = 0;
    }
    else
    {
        //@ assert ans <= a - b + c;
        res = ans;
    }

    return res;
}
