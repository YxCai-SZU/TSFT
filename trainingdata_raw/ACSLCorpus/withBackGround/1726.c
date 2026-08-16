#include <limits.h>

/*@
    predicate is_safe_sum(integer a, integer b, integer c) =
        a >= INT_MIN / 3 && a <= INT_MAX / 3 &&
        b >= INT_MIN / 3 && b <= INT_MAX / 3 &&
        c >= INT_MIN / 3 && c <= INT_MAX / 3 &&
        a + b + c >= INT_MIN && a + b + c <= INT_MAX;

    lemma sum_in_range:
        \forall integer a, b, c;
            is_safe_sum(a, b, c) ==> a + b + c >= INT_MIN && a + b + c <= INT_MAX;
*/

/*@
    requires is_safe_sum(a, b, c);
    ensures \result == a + b + c;
    assigns \nothing;
*/
int sum_numbers(int a, int b, int c)
{
    //@ assert a + b + c >= INT_MIN;
    //@ assert a + b + c <= INT_MAX;
    return a + b + c;
}
