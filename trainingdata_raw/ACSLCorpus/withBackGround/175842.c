#include <stdbool.h>

/*@
    predicate in_range(integer a, integer b, integer c) =
        1 <= a <= 500 && 1 <= b <= 500 && 1 <= c <= 1000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b;
        in_range(a, b, 0) ==> 2 <= sum(a, b) <= 1000;

    lemma sum_reflexive:
        \forall integer a, b;
        in_range(a, b, 0) ==> sum(a, b) == a + b;

    lemma sum_implication:
        \forall integer a, b, c;
        in_range(a, b, c) ==> (sum(a, b) >= c ==> sum(a, b) >= c);
*/

/*@
    requires in_range(a, b, c);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    bool ans = true;

    //@ assert 2 <= a + b <= 1000;
    //@ assert a + b == a + b;
    //@ assert (a + b >= c ==> a + b >= c);

    if (a + b < c)
    {
        ans = false;
    }

    return ans;
}
