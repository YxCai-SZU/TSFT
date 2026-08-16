#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == (a + b >= c);
    assigns \nothing;
*/
bool func(long a, long b, long c) {
    long state = 0;
    long idx = 0;
    
    /*@
        loop invariant 0 <= idx <= a;
        loop invariant state == idx;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns state, idx;
        loop variant a - idx;
    */
    while (idx < a) {
        state += 1;
        idx += 1;
    }
    
    idx = 0;
    
    /*@
        loop invariant 0 <= idx <= b;
        loop invariant state == a + idx;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns state, idx;
        loop variant b - idx;
    */
    while (idx < b) {
        state += 1;
        idx += 1;
    }
    
    //@ assert state == a + b;
    return state >= c;
}
