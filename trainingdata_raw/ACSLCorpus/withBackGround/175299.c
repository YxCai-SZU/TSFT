#include <stdbool.h>

/*@
    predicate valid_range(int *a, integer len) =
        len == 3 &&
        \forall integer i; 0 <= i < len ==> 1 <= a[i] <= 9;

    predicate is_increasing_pred(int *a) =
        a[0] < a[1] && a[1] < a[2];
*/

/*@
    requires \valid_read(a + (0..2));
    requires valid_range(a, 3);
    ensures \result == 1 <==> is_increasing_pred(a);
    assigns \nothing;
*/
bool is_increasing(int *a) {
    int i;

    // Check if each element is within the range 1-9
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= a[j] <= 9;
        loop assigns i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert 1 <= a[i] <= 9;
        i++;
    }

    // Check if the sequence is increasing
    if (a[0] < a[1] && a[1] < a[2]) {
        return true;
    } else {
        return false;
    }
}
