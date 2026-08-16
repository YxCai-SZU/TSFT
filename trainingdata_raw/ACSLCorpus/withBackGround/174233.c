#include <stdbool.h>

/*@
    predicate valid_array(int *a, integer len) =
        len == 2 &&
        \valid(a + (0 .. 1)) &&
        1 <= a[0] <= 100 &&
        1 <= a[1] <= 100;

    logic integer compute_result(integer a0, integer a1) =
        a0 > a1 * 2 ? a0 - a1 * 2 : 0;

    lemma result_nonnegative:
        \forall integer a0, a1;
        1 <= a0 <= 100 && 1 <= a1 <= 100 ==>
        compute_result(a0, a1) >= 0;

    lemma result_cases:
        \forall integer a0, a1;
        1 <= a0 <= 100 && 1 <= a1 <= 100 ==>
        compute_result(a0, a1) == a0 - a1 * 2 ||
        compute_result(a0, a1) == 0;
*/

/*@
    requires valid_array(a, 2);
    assigns \nothing;
    ensures \result >= 0;
    ensures \result == a[0] - a[1] * 2 || \result == 0;
*/
int func(int *a) {
    // Variable declarations at top of scope
    int result;
    
    //@ assert a[0] >= 1 && a[0] <= 100;
    //@ assert a[1] >= 1 && a[1] <= 100;
    
    if (a[0] > a[1] * 2) {
        //@ assert a[0] > a[1] * 2;
        result = a[0] - a[1] * 2;
    } else {
        //@ assert a[0] <= a[1] * 2;
        result = 0;
    }
    
    //@ assert result >= 0;
    return result;
}
