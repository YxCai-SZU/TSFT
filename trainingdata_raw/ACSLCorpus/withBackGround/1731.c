#include <limits.h>

/*@
    predicate is_valid_i(integer i) = 1 <= i && i <= 9;
    logic integer cube(integer i) = i * i * i;
    lemma cube_range: \forall integer i; is_valid_i(i) ==> 1 <= cube(i) <= 729;
*/

/*@
    requires 1 <= i <= 9;
    ensures \result == i * i * i;
    assigns \nothing;
*/
int func(int i)
{
    // Variable declarations at top of scope
    int res;

    //@ assert 1 <= i && i <= 9;
    //@ assert 1 <= i * i <= 81;
    //@ assert 1 <= i * i * i <= 729;

    res = i * i * i;
    return res;
}
