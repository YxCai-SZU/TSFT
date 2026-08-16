#include <stdbool.h>

/*@
    predicate within_range(integer a, integer b, integer x) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= x <= 200;

    logic integer sum(integer a, integer b) = a + b;

    lemma condition_lemma:
        \forall integer a, b, x;
            within_range(a, b, x) ==>
            ((x <= sum(a, b) && a <= x) ==>
                x <= sum(a, b) && a <= x);

    lemma neg_condition_lemma:
        \forall integer a, b, x;
            within_range(a, b, x) ==>
            (!(x <= sum(a, b) && a <= x) ==>
                !(x <= sum(a, b) && a <= x));
*/

/*@
    requires within_range(a, b, x);
    ensures \result == (x <= a + b && a <= x);
*/
bool func(unsigned int a, unsigned int b, unsigned int x)
{
    // Variable declarations at scope top
    bool result;

    if (x <= a + b && a <= x)
    {
        //@ assert x <= a + b && a <= x;
        result = true;
    }
    else
    {
        //@ assert !(x <= a + b && a <= x);
        result = false;
    }

    return result;
}
