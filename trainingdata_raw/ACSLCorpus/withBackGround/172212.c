#include <stdbool.h>

/*@
    predicate is_target(integer k) =
        k == 7 || k == 5 || k == 3;
*/

/*@
    requires 1 <= k <= 9;
    ensures \result == (k == 7 || k == 5 || k == 3);
    assigns \nothing;
*/
bool func(int k)
{
    bool result;

    //@ assert 1 <= k <= 9;

    if (k == 7 || k == 5 || k == 3) {
        //@ assert is_target(k);
        result = true;
    } else {
        //@ assert !is_target(k);
        result = false;
    }

    return result;
}
