#include <stdbool.h>

/*@
    predicate a_equals_b(integer a, integer b) = a == b;
    predicate a_not_equals_b(integer a, integer b) = a != b;
    logic integer difference(integer a, integer b) = a - b;

    lemma diff_zero: \forall integer a, b; a_equals_b(a, b) ==> difference(a, b) == 0;
    lemma diff_positive: \forall integer a, b; a_not_equals_b(a, b) && b <= a ==> difference(a, b) > 0;
*/

/*@
    requires 1 <= a <= 100;
    requires 0 <= b <= a;
    ensures \result == (a == b);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b)
{
    // Declare all variables at the top
    bool result;

    // Proof assertions in ACSL
    //@ assert a == b ==> a - b == 0;
    //@ assert a != b ==> a - b > 0;

    result = (a == b);
    return result;
}
