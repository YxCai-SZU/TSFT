#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;

    logic integer square(integer a) = a * a;
    logic integer cube(integer a) = a * a * a;
    logic integer formula(integer a) = a + square(a) + cube(a);

    lemma square_bounds:
        \forall integer a; valid_range(a) ==> 1 <= square(a) <= 100;

    lemma cube_bounds:
        \forall integer a; valid_range(a) ==> 1 <= cube(a) <= 1000;

    lemma result_bounds:
        \forall integer a; valid_range(a) ==> 3 <= formula(a) <= 1110;
*/

/*@
    requires 1 <= a <= 10;
    ensures \result == formula(a);
    assigns \nothing;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t a2;
    int64_t a3;
    int64_t ans;

    //@ assert valid_range(a);
    //@ assert 1 <= square(a) && square(a) <= 100;

    a2 = a * a;

    //@ assert valid_range(a);
    //@ assert 1 <= cube(a) && cube(a) <= 1000;

    a3 = a * a * a;

    ans = a + a2 + a3;

    //@ assert 3 <= formula(a) && formula(a) <= 1110;

    return ans;
}
