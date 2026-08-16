#include <stdint.h>

/*@
    predicate is_valid_range(integer a) =
        1 <= a && a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer target_expr(integer a) = a + square(a) + cube(a);

    lemma square_bound: \forall integer a; is_valid_range(a) ==> square(a) <= 100;
    lemma cube_bound: \forall integer a; is_valid_range(a) ==> cube(a) <= 1000;
    lemma expr_bound: \forall integer a; is_valid_range(a) ==> target_expr(a) <= 1110;
*/

/*@
    requires is_valid_range(a);
    ensures \result == target_expr(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert square(a) <= 100;
    //@ assert cube(a) <= 1000;
    //@ assert a + square(a) + cube(a) <= 1110;

    result = a + (a * a) + (a * a * a);
    return result;
}
