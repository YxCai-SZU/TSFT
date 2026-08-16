#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_x(integer x) = 1 <= x <= 100000; */

/*@
    requires is_valid_x(x);
    ensures \result == 0 || \result == 1;
*/
int func(size_t x) {
    int a = 0;
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= x + 1;
        loop invariant a >= 0;
        loop invariant a <= (int)(i - 1);
        loop assigns a, i;
    */
    while (i < x + 1) {
        if (i % 100 <= 5) {
            a += 1;
        }
        i += 1;
    }
    
    int ans = 0;
    if (a >= 10) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert ans == 0 || ans == 1;
    return ans;
}
