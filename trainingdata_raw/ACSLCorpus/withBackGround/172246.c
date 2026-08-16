#include <stdint.h>

/*@
    predicate valid_range(integer a) = 1 <= a && a <= 10;

    logic integer compute_result(integer a) = a + a * a + a * a * a;

    lemma result_bounds:
        \forall integer a; valid_range(a) ==> compute_result(a) <= 1331;

    lemma square_bounds:
        \forall integer a; valid_range(a) ==> a * a <= 100;

    lemma cube_bounds:
        \forall integer a; valid_range(a) ==> a * a * a <= 1000;
*/

/*@
    requires 1 <= a <= 10;
    requires a == (int64_t)a;
    ensures \result == a + a * a + a * a * a;
    ensures \result <= 1331;
*/
int64_t func(int64_t a)
{
    // Variable declarations at scope top
    int64_t ans;

    //@ assert a >= 1 && a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    //@ assert a + a * a + a * a * a <= 1331;

    ans = a + a * a + a * a * a;
    return ans;
}
