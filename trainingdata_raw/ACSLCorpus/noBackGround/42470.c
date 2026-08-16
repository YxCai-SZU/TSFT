#include <limits.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result == 1 <==> 
        (a == b + c || b == a + c || c == a + b);
    assigns \nothing;
*/
int func(int a, int b, int c) {
    // Variable declarations at scope top
    int result;

    //@ assert 1 <= b + c <= INT_MAX;
    //@ assert 1 <= a + c <= INT_MAX;
    //@ assert 1 <= a + b <= INT_MAX;

    if (a == b + c || b == a + c || c == a + b) {
        result = 1;
    } else {
        result = 0;
    }

    return result;
}
