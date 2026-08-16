#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 2 <= n && n <= 100;
    predicate loop_invariant(integer i, integer a, integer b, integer n) =
        0 <= i && i <= 10000 &&
        0 <= a && a <= n &&
        0 <= b && b <= i &&
        2 <= n && n <= 100;
*/


int test_func(int n) {
    int a;
    int b;
    int i;
    
    a = 0;
    b = 0;
    i = 0;
    
    
    while (i < 10000) {
        a = a + 1;
        if (a >= n) {
            a = 0;
            b = b + 1;
        }
        i = i + 1;
    }
    
    //@ assert b == 1 || b != 1;
    
    if (b == 1) {
        return 1;
    } else {
        return 0;
    }
}
