#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        a >= 1 && b >= 1 && c >= 1 &&
        a <= 5000 && b <= 5000 && c <= 5000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bounds:
        \forall integer a, b, c;
        bounds(a, b, c) ==> sum(a, b) >= 2 && sum(a, b) <= 10000;
*/

/*@
    requires bounds(a, b, c);
    ensures \result <==> (a + b >= c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert bounds(a, b, c);
    //@ assert a >= 1 && b >= 1 && c >= 1;
    //@ assert a <= 5000 && b <= 5000 && c <= 5000;
    return (a + b) >= c;
}
