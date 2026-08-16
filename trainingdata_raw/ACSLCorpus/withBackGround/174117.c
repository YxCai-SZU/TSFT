#include <limits.h>

/*@
    predicate is_valid_range(integer x) = -1290 <= x <= 1290;

    logic integer cube(integer x) = x * x * x;

    lemma cube_range:
        \forall integer x;
            is_valid_range(x) ==>
            cube(x) >= -1290 * 1290 * 1290 &&
            cube(x) <= 1290 * 1290 * 1290;
*/

/*@
    requires is_valid_range(x);
    ensures \result == cube(x);
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    //@ assert is_valid_range(x);
    //@ assert x * x >= -1290 * 1290 && x * x <= 1290 * 1290;
    //@ assert x * x * x >= -1290 * 1290 * 1290 && x * x * x <= 1290 * 1290 * 1290;
    ans = x * x * x;
    return ans;
}
