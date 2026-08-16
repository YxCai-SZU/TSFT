#include <stdbool.h>

/*@
    predicate valid_x(int *x) =
        \valid(x + (0 .. 2)) &&
        1 <= x[0] <= 100 &&
        1 <= x[1] <= 100 &&
        1 <= x[2] <= 200;

    predicate valid_y(int *y) =
        \valid(y + (0 .. 2)) &&
        1 <= y[0] <= 100 &&
        1 <= y[1] <= 100 &&
        1 <= y[2] <= 200;

    logic integer ans_bound(integer i) = i * 200;

    lemma ans_non_negative:
        \forall integer i, integer ans;
        0 <= i <= 3 && ans >= 0 && ans <= ans_bound(i) ==> ans >= 0;
*/

/*@
    requires valid_x(x) && valid_y(y);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int *x, int *y) {
    int ans = 0;
    int i = 0;

    /*@
        loop invariant 0 <= i <= 3;
        loop invariant ans >= 0;
        loop invariant ans <= ans_bound(i);
        loop invariant valid_x(x);
        loop invariant valid_y(y);
        loop assigns ans, i;
        loop variant 3 - i;
    */
    while (i < 3) {
        if (y[i] >= x[i]) {
            ans += y[i] - x[i];
        }
        i += 1;
        
        //@ assert i <= 3;
    }
    
    return ans;
}
