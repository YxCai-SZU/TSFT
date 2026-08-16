#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_small(integer x) = 1 <= x && x <= 20; */
/*@ predicate both_small(integer x, integer y) = x < 10 && y < 10; */
/*@ predicate one_large(integer x, integer y) = x >= 10 || y >= 10; */

/*@
    requires \valid_read(a + (0..1));
    requires is_small(a[0]) && is_small(a[1]);
    ensures both_small(a[0], a[1]) ==> \result == 1;
    ensures one_large(a[0], a[1]) ==> \result == 0;
*/
int32_t func(const uint32_t* a) {
    int32_t ans;
    //@ assert is_small(a[0]) && is_small(a[1]);
    
    if (a[0] < 10 && a[1] < 10) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    return ans;
}
