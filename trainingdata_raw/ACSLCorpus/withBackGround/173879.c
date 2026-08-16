#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    lemma lower_bound_3r: \forall integer r; valid_range(r) ==> 3 * 1 <= 3 * r;
    lemma upper_bound_3r: \forall integer r; valid_range(r) ==> 3 * r <= 3 * 100;

    lemma lower_bound_3r_sq: \forall integer r; valid_range(r) ==> 3 * 1 * 1 <= 3 * r * r;
    lemma upper_bound_3r_sq: \forall integer r; valid_range(r) ==> 3 * r * r <= 3 * 100 * 100;
*/

/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t area;

    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * 1 <= 3 * r;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 3 * 1 * 1 <= 3 * r * r;
    //@ assert 3 * r * r <= 3 * 100 * 100;

    area = 3 * r * r;
    return area;
}
