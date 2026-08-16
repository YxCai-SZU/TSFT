#include <stdbool.h>

/*@
    predicate valid_range(int* a, integer len) =
        len >= 3 &&
        \forall integer i; 0 <= i < 3 ==> a[i] >= 1 && a[i] <= 13;

    logic integer element_at(int* a, integer i) = a[i];
*/

/*@
    requires \valid(a + (0 .. 2));
    requires valid_range(a, 3);
    ensures \result == (element_at(a, 2) == element_at(a, 0) + element_at(a, 1));
    assigns \nothing;
*/
bool func(int* a) {
    //@ assert valid_range(a, 3);
    return a[2] == a[0] + a[1];
}
