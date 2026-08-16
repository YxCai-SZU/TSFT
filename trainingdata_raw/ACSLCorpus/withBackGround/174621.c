#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_array(int *a, size_t len) =
        len == 3 &&
        \valid(a + (0 .. 2)) &&
        1 <= a[0] <= 100 &&
        1 <= a[1] <= 100 &&
        1 <= a[2] <= 100;

    logic integer compute_res(integer a0, integer a1, integer a2) =
        a0 >= a1 && a1 >= a2 ?
            a0 + a1 - a2 + 1 :
            1;

    lemma res_bounds:
        \forall integer a0, a1, a2;
            1 <= a0 <= 100 && 1 <= a1 <= 100 && 1 <= a2 <= 100 ==>
            0 <= compute_res(a0, a1, a2) <= 200;
*/

/*@
    requires valid_array(a, len);
    ensures \result >= 0 && \result <= 200;
    assigns \nothing;
*/
int func(int *a, size_t len) {
    int res = 0;
    
    //@ assert a[0] >= a[1] && a[1] >= a[2] ==> a[0] + a[1] <= 200;
    //@ assert a[0] >= a[1] && a[1] >= a[2] ==> a[0] + a[1] - a[2] >= 0;
    
    if (a[0] >= a[1] && a[1] >= a[2]) {
        res = a[0] + a[1] - a[2] + 1;
    } else {
        res = 1;
    }
    
    return res;
}
