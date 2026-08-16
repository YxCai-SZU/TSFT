#include <limits.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    logic integer cube(integer x) = x * x * x;

    lemma square_bound: \forall integer x; 1 <= x <= 9 ==> x * x <= 81;
    lemma cube_bound: \forall integer x; 1 <= x <= 9 ==> x * x * x <= 729;
*/

/*@
    requires is_valid_range(x);
    ensures \result == cube(x);
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at scope top
    int res;

    //@ assert 1 <= x <= 9;
    //@ assert x * x <= 81;
    //@ assert x * x * x <= 729;

    res = x * x * x;
    return res;
}
