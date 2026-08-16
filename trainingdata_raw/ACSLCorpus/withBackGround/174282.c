#include <stdbool.h>

/*@
    predicate valid_array(int *a, integer len) =
        len == 5 &&
        \forall integer i; 0 <= i < len ==> 0 <= a[i] && a[i] <= 123;

    logic integer array_diff(int *a) = a[4] - a[0];
*/

/*@
    requires valid_array(a, 5);
    requires 0 <= k && k <= 123;
    ensures \result == (k >= array_diff(a));
    assigns \nothing;
*/
bool func(int *a, int k) {
    // Variable declarations at scope top
    bool result;

    //@ assert valid_array(a, 5);
    //@ assert 0 <= k && k <= 123;
    //@ assert a[4] - a[0] == array_diff(a);

    result = (k >= (a[4] - a[0]));
    return result;
}
