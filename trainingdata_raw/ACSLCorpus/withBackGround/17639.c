#include <stdbool.h>
/*@
    predicate valid_range(int* arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] && arr[i] <= 5;

    predicate loop_inv(int* x, int* y, integer i, integer count) =
        0 <= i <= 5 &&
        0 <= count <= i &&
        valid_range(x, 5) &&
        valid_range(y, 5);
*/

/*@
    requires \valid(x + (0..4)) && \valid(y + (0..4));
    requires valid_range(x, 5) && valid_range(y, 5);
    ensures 0 <= \result <= 5;
    assigns \nothing;
*/
int func(int* x, int* y) {
    int count = 0;
    int i = 0;
    /*@
        loop invariant loop_inv(x, y, i, count);
        loop assigns i, count;
        loop variant 5 - i;
    */
    while (i < 5) {
        //@ assert 0 <= i < 5;
        if (x[i] == y[i]) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
