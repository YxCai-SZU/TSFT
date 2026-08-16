#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b, integer c) =
        1 <= a <= 500 &&
        1 <= b <= 500 &&
        1 <= c <= 1000;

    logic integer ab_sum(integer a, integer b) = a + b;
    logic integer ac_sum(integer a, integer c) = a + c;
    logic integer bc_sum(integer b, integer c) = b + c;

    lemma condition_lemma:
        \forall integer a, b, c;
        valid_range(a, b, c) ==>
        (ab_sum(a, b) >= c && ab_sum(a, b) >= 2 * (a - (ab_sum(a, b) - c))) ==
        ((a + b >= c) && a + b >= 2 * (a - (a + b - c)));
*/

/*@
    requires valid_range(a, b, c);
    ensures \result == ((a + b >= c) && a + b >= 2 * (a - (a + b - c)));
*/
bool func(int a, int b, int c)
{
    int ab;
    int ac;
    int bc;
    bool result;

    ab = a + b;
    ac = a + c;
    bc = b + c;

    //@ assert ab == ab_sum(a, b);
    //@ assert ac == ac_sum(a, c);
    //@ assert bc == bc_sum(b, c);

    if (ab >= c && ab >= 2 * (a - (ab - c)))
    {
        //@ assert ab >= c && ab >= 2 * (a - (ab - c));
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == ((a + b >= c) && a + b >= 2 * (a - (a + b - c)));
    return result;
}
