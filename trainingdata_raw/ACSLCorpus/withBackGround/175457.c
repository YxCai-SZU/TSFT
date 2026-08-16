#include <stdbool.h>

/*@
    predicate valid_input(int *a, integer len) =
        len >= 3 &&
        1 <= a[0] && a[0] <= 100 &&
        1 <= a[1] && a[1] <= 20 &&
        1 <= a[2] && a[2] <= 2000;

    logic integer safe_mult(integer x) = x * 50;

    lemma mult_bounds: \forall integer x; 1 <= x <= 20 ==> 1 <= safe_mult(x) <= 2000;
*/

/*@
    requires \valid(a+(0..2));
    requires valid_input(a, 3);
    ensures \result <= a[2];
    ensures \result >= -1;
    assigns \nothing;
*/
int func(int *a) {
    int ans;
    
    //@ assert 1 <= a[1] && a[1] <= 20;
    //@ assert 1 <= a[1] * 50 && a[1] * 50 <= 2000;
    
    ans = a[1] * 50;
    
    if (ans > a[2]) {
        ans = -1;
    }
    
    return ans;
}
