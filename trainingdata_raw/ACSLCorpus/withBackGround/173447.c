#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c, integer d) =
        1 <= a && a < b && b < c && c < d && d <= 100;

    logic integer mul_b_c(integer b, integer c) = b * c;
    logic integer mul_a_d(integer a, integer d) = a * d;
    logic integer mul_b_c1(integer b, integer c) = b * (c + 1);

    lemma mul_bounds_b_c:
        \forall integer b, c; 1 <= b <= 100 && 1 <= c <= 100 ==> mul_b_c(b, c) <= 10000;

    lemma mul_bounds_a_d:
        \forall integer a, d; 1 <= a <= 100 && 1 <= d <= 100 ==> mul_a_d(a, d) <= 10000;

    lemma mul_bounds_b_c1:
        \forall integer b, c; 1 <= b <= 100 && 1 <= c <= 100 ==> mul_b_c1(b, c) <= 10100;
*/

/*@
    requires bounds(a, b, c, d);
    ensures \result == (mul_b_c(b, c) >= mul_a_d(a, d) || mul_b_c1(b, c) >= mul_a_d(a, d));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c, unsigned int d)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    //@ assert 1 <= d && d <= 100;

    //@ assert mul_b_c(b, c) <= 10000;
    //@ assert mul_a_d(a, d) <= 10000;
    //@ assert mul_b_c1(b, c) <= 10100;

    result = (b * c >= a * d) || (b * (c + 1) >= a * d);
    return result;
}
