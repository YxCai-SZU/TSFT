#include <stdbool.h>

/*@
    predicate nonnegative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate within_bounds(integer a, integer b, integer c) =
        a <= 100 && b <= 100 && c <= 100;

    lemma product_bound:
        \forall integer a, b;
            a >= 0 && b >= 0 && a <= 100 && b <= 100 ==> a * b <= 10000;

    lemma division_bound:
        \forall integer a, b;
            a >= 0 && b >= 0 && a <= 100 && b <= 100 ==> a * b / 100 <= 100;

    lemma division_nonnegative:
        \forall integer a, b;
            a >= 0 && b >= 0 && a <= 100 && b <= 100 ==> a * b / 100 >= 0;
*/

/*@
    requires nonnegative(a, b, c);
    requires within_bounds(a, b, c);
    ensures \result == (a * b / 100 <= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    //@ assert a * b <= 10000;
    //@ assert a * b / 100 <= 100;
    //@ assert a * b / 100 >= 0;
    
    return a * b / 100 <= c;
}
